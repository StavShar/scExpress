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

//printing current cart as "product name" - "amount" - "price(amount * product's price)"
void View_cart(Product* plist, int slist, Cart clist, int scart)
{
	int index;
	float tp = 0.0;//total price
	if (!scart)//scart = 0
		printf("Cart is empty.\n");
	else
	{
		printf("product - amount - price\n");
		for (int i = 0; i < scart; i++)
		{
			index = Get_Index_Of_Product(plist, slist, clist.sn[i]);
			if (index != ERROR)
			{
				printf("%s - %d - %f\n", plist[index].name, clist.amount[i], (clist.amount[i] * Get_Price(plist[index])));//print details
				tp += (clist.amount[i] * Get_Price(plist[index]));
			}
		}
		printf("Total price: %.2f\n", tp);
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

