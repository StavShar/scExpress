//#include "Orders_user.h"
//
//
//
//void orderHistory(FILE* HisOr, char id[9], Product order[N], int items)
//{
//	char filename[50];
//	int i;
//	sprintf(filename, "%s.csv", id);
//	HisOr = fopen(filename, "a");
//	if (!filename)
//	{
//		puts("Open file have failed");
//		exit(0);
//	}
//	for (i = 0; i < items; i++)
//	{
//		
//		
//		fprintf(filename, "%s,%d,%f\n", order[i].name, order[i].quantity, order[i].price);
//
//
//	}
//
//
//	fclose(HisOr);
//}