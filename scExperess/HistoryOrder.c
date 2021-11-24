#define _CRT_SECURE_NO_WARNINGS
#include "HistoryOrder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//status should get if the order is approved or not 
//order shloud get the array of the structure
//items is the number of the items that in the cart
void orderHistory(int id, ProductFile* order, int items, char status)
{
	if (status == "Y")
	{
		FILE* HisOr;
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

		fprintf(HisOr, "Product:,Seiral:,Amount:,Price:\n");

		for (i = 0; i < items; i++)
		{
			fprintf(HisOr, "%s,%d,%d,%.3f\n", order[i].name, order[i].sn, order[i].amount, order[i].price);
			tp += order[i].price;
		}
		fprintf(HisOr, "Total:,%f", tp);
		fclose(HisOr);
	}
	else
	puts("the order is not approved yet");
}