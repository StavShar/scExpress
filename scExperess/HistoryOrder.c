#define _CRT_SECURE_NO_WARNINGS
#include "HistoryOrder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//status should get if the order is approved or not 
//order shloud get the array of the structure
//items is the number of the items that in the cart
//pTotalPrice initialized to 0 at first, to start with 0 profit
/*----> The user's orders history*/
void orderHistory(int id, ProductFile* order, int items, char status, int * ptr, float* pTotalPrice)
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

int DailyProfit(float* pTotalPrice, float tp)
{
	*pTotalPrice += tp;
	return *pTotalPrice;
}