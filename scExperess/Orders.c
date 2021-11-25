#include "Orders.h"


/* REMEMBER: free all the allocate memory in the main */


//Manager's view of all the orders
//ptr initialized to 0 at first, to check if there is any history at all
void ViewOrders(orders* ListOrders, int* ptr)
{
	if (*ptr)
	{
		FILE* View;
		char file;
		View = fopen("HistoryOfAllOrders.csv", "r");
		while (View != EOF)
		{
			fputc(file, View);
		}
	}
	else
		puts("There is no history yet.");
}

//The function bascilly adding one order at the time 
//Flag for poting that if this is the first user or not
//The *ptr for pointing at the location of the user order 
//pSer is initialized at digit 10000, to make a following serial number
//username is the name of the customer
//id is the id number of the customer
orders* MakeOrder(ProductFile* listPro, int flag, int* ptr, int* pSer, char* username, int id)
{
	orders* NewOrder;
	int items = 0, i;
	if (flag == 0)
	{
		NewOrder = (orders*)malloc(1 * sizeof(orders));
	}
	else
	{
		NewOrder = (orders*)realloc(NewOrder, 1 * sizeof(orders));//Added one at the time 
	}

	items = countItems(listPro);
	NewOrder[*ptr].id = id;
	strcpy(NewOrder[*ptr].username, username);
	NewOrder[*ptr].serial = getSer(*pSer);
	for (i = 0; i < items; i++)
	{
		strcpy(NewOrder[*ptr].items[i].name, listPro[i].name);
		NewOrder[*ptr].items[i].amount = listPro[i].amount;
		NewOrder[*ptr].items[i].sn = listPro[i].sn;
		NewOrder[*ptr].items[i].price = listPro[i].price;
	}
	*ptr++;//For the next customer order.
	return NewOrder;
}

//pSer is initialized at digit 10000, to make a following serial number
int getSer(int* pSer)
{
	*pSer += 4;
	return *pSer;
}

int countOrder(orders* ListOrders)
{
	int i;
	for (i = 0; !(ListOrders[i].username); i++);//Couting the size of the array of structre
	return i;

}

int countItems(ProductFile* ListOrders)
{
	int i, j;
	for (i = 0; !(ListOrders->name); i++);
	return i;
}

//pTotalPrice initialized to 0 at first, to start with 0 profit
int DailyProfit(float* pTotalPrice, float tp)
{
	*pTotalPrice += tp;
	return *pTotalPrice;
}

void PrintfProfit(int* pTotalPrice)
{
	printf("The total profit of the day is: %d\n", *pTotalPrice);

}

orders* ChangeStatus(orders* Allorders)
{
	int i, serial;
	char YN;//Yes and No to approve or cancel
	puts("Please enter the customer's id: ");
	scanf("%d", &serial);
	while (serial != Allorders->id)
	{
		puts("Worng id, try again.");
	}
	printf("Y = Confrim\nN = Cancel\n");
	printf("User details:\nName: %s :: ID: %d", Allorders[i].username, Allorders[i].id);
	scanf("%c", &YN);
	if (YN == "Y")
	{
		Allorders[i].status = "Y";
	}
	else
	{
		Allorders[i].status = "N";
	}
	return Allorders;
}

//status should get if the order is approved or not 
//order shloud get the array of the structure
//items is the number of the items that in the cart
//pTotalPrice initialized to 0 at first, to start with 0 profit
/*----> The user's orders history*/
void orderHistory(int id, ProductFile* order, int items, char status, int* ptr, float* pTotalPrice)
{
	if (status == "Y")
	{
		FILE* HisOr;
		FILE* ManagerHistory;
		char filename[50];
		int i;
		float tp = 0;
		sprintf(filename, "%d.csv", id);
		HisOr = fopen(filename, "a");
		if (!HisOr)
		{
			puts("Open file have failed");
			exit(0);
		}
		ManagerHistory = fopen("HistoryOfAllOrders.csv", "a");
		if (!(ManagerHistory))
			ManagerHistory = fopen("HistoryOfAllOrders.csv", "a");
		if (!(ManagerHistory))
		{
			puts("Open file have failed");
			exit(1);
		}

		fprintf(HisOr, "Product:,Seiral:,Amount:,Price:\n");
		fprintf(ManagerHistory, "ORDER: %d", *ptr);
		*ptr++;//Promote the user by one.
		fprintf(ManagerHistory, "Product:,Seiral:,Amount:,Price:\n");

		for (i = 0; i < items; i++)
		{
			fprintf(HisOr, "%s,%d,%d,%.3f\n", order[i].name, order[i].sn, order[i].amount, order[i].price);
			tp += order[i].price;
			fprintf(ManagerHistory, "%s,%d,%d,%.3f\n", order[i].name, order[i].sn, order[i].amount, order[i].price);
			tp += order[i].price;
		}
		fprintf(HisOr, "Total:,%f", tp);
		fprintf(ManagerHistory, "Total:,%f", tp);
		DailyProfit(pTotalPrice, tp);
		fclose(HisOr);
		fclose(ManagerHistory);
	}
	else
		puts("the order is not approved yet");
}

