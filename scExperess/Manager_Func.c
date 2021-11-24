#include "Manager_func.h"
#include "HistoryOrder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Manager's view of all the orders
//ptr nitialized to 0 at first, to check if there is any history at all
void ViewOrders(orders* ListOrders, int *ptr)
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
orders* MakeOrder(ProductFile* listPro, int flag, int* ptr)
{
	orders* NewOrder;
	int items = 0, i;
	if (flag == 0)
	{
		NewOrder = (orders*)malloc(1 * sizeof(orders));
	}
	else
	{
		NewOrder = (orders*)realloc(NewOrder, 1 * sizeof(orders));
	}

	items = countItems(listPro);
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
int DailyProfit(float * pTotalPrice, float tp)
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