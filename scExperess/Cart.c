#include "Cart.h"

//adding product's details to cart
Cart Add_To_Cart(Product* plist, int slist, Cart clist, int* scart, int sn, int quantity)
{
	for (int i = 0; i < slist; i++)
	{
		if (sn == plist[i].sn)
		{
			if ((quantity > 0) && (quantity <= plist[i].quantity))//add product
			{
				(*scart)++;
				int* newSN, * newAmount;
				newSN = (int*)malloc((*scart) * sizeof(int));
				if (newSN == NULL)
				{
					printf("Allocate memory failed.\n");
					exit(1);
				}
				newAmount = (int*)malloc((*scart) * sizeof(int));
				if (newAmount == NULL)
				{
					printf("Allocate memory failed.\n");
					exit(1);
				}
				//copy old list
				for (int i = 0; i < *scart - 1; i++)
				{
					newSN[i] = clist.sn[i];
					newAmount[i] = clist.amount[i];
				}
				//add new product's details
				newSN[*scart - 1] = sn;
				newAmount[*scart - 1] = quantity;
				free(clist.sn);
				free(clist.amount);
				clist.sn = newSN;
				clist.amount = newAmount;
				return clist;
			}
			else
			{
				printf("Error! illegal quantity.\n");
				return clist;
			}

		}
	}
	printf("Error! product can't be found.\n");
	return clist;
}

//printing current cart as "serial number" - "product name" - "amount" - "price(amount * product's price)"
void View_cart(Product* plist, int slist, Cart clist, int scart)
{
	int index;
	clist.tp = 0;//reset total price
	if (!scart)//scart = 0
		printf("Cart is empty.\n");
	else
	{
		printf("serial number - product - amount - price\n");
		for (int i = 0; i < scart; i++)
		{
			index = Get_Index_Of_Product(plist, slist, clist.sn[i]);
			if (index != ERROR)
			{
				printf("%d - %s - %d - %f\n", clist.sn[i], plist[index].name, clist.amount[i], (clist.amount[i] * Get_Price(plist[index])));//print details
				clist.tp += (clist.amount[i] * Get_Price(plist[index]));
			}
		}
		printf("Total price: %.2f\n", clist.tp);
	}
}

//remove product from cart by serial number
Cart Remove_From_Cart(Cart clist, int* scart, int sn)
{
	(*scart)--;
	int* newSN, * newAmount;
	newSN = (int*)malloc((*scart) * sizeof(int));
	if (newSN == NULL)
	{
		printf("Allocate memory failed.\n");
		exit(1);
	}
	newAmount = (int*)malloc((*scart) * sizeof(int));
	if (newAmount == NULL)
	{
		printf("Allocate memory failed.\n");
		exit(1);
	}
	//copy old list(except the serial number we need to remove)
	for (int i = 0; i < *scart + 1; i++)
	{
		if (sn == clist.sn[i])
		{
			newSN[i] = clist.sn[*scart];
			newAmount[i] = clist.amount[*scart];
		}
		newSN[i] = clist.sn[i];
		newAmount[i] = clist.amount[i];
		//free memory
		free(clist.sn);
		free(clist.amount);
		clist.sn = newSN;
		clist.amount = newAmount;
		return clist;
	}
}

//buying all products in cart
Cart Checkout(Product* plist, int slist, Cart clist, int scart)/////////////////////////////////////whiles for wrong input 
{
	char selection;
	int delivery, delFLAG = 1;
	printf("Are you sure you want to buy this cart? (y/n)\n");
	scanf("%c", &selection);
	if (selection == 'y' || selection == 'Y')
	{
		printf("Are you looking for delivery service? (y/n)\n");
		scanf("%c", &selection);
		if (selection == 'y' || selection == 'Y')
		{
			while (delFLAG)
			{
				printf("1 - North (%fnis)\n2 - Central (%fnis)\n3 - South (%fnis)\n4 - Back\n", NORTH, CENTRAL, SOUTH);
				scanf("%d", &delivery);
				if (delivery == 1)
				{
					clist.tp += NORTH;
					delFLAG = 0;
				}
				else if (delivery == 2)
				{
					clist.tp += CENTRAL;
					delFLAG = 0;
				}
				else if (delivery == 3)
				{
					clist.tp += SOUTH;
					delFLAG = 0;
				}
				else if (delivery == 4)
				{
					delFLAG = 0;
				}
				else
					printf("Wrong number, try again.\n");
			}
		}
	}
}
