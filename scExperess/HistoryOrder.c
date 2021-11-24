#define _CRT_SECURE_NO_WARNINGS
#include "HistoryOrder.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void orderHistory(int id, ProductFile* order, int items)
{
	FILE* HisOr;
	char filename[50];
	int i;
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


	}
	fclose(HisOr);
}