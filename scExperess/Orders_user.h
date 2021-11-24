//#pragma once
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define N 1
//
//typedef struct
//{
//	char name[30];
//	int sn;
//	int amount;
//	float price;
//
//}ProductFile;
//
//typedef struct
//{
//	char* username;
//	int id;
//	float tp;
//	char status;
//
//	ProductFile* items;
//}orders;
//
//
//int main()
//{
//	ProductFile* order;
//	char id[9];
//	int items, i;
//	gets(id);
//	puts("How many items?");
//	scanf("%d", &items);
//	order = (ProductFile*)malloc(items * sizeof(ProductFile));
//	for (i = 0; i < items; i++)
//	{
//		getchar();
//		gets(order[i].name);
//		scanf("%d", &order[i].sn);
//		scanf("%d", &order[i].amount);
//		scanf("%f", &order[i].price);
//	}
//
//
//
//}
//
//void OrderHistory(char id[9], ProductFile* order, int items)
//{
//	FILE* History;
//	char filename[9];
//	int i;
//	sprintf(filename, "%s.csv", id);
//	History = fopen(filename, "a");
//	if (!filename)
//	{
//		puts("Open file have failed");
//		exit(1);
//	}
//
//	for (i = 0; i < items; i++)
//	{
//		printf("%s %d %f", order[i].name, order[i].amount, order[i].price);
//		fprintf(filename, "%s,%d,%f", order[i].name,order[i].sn, order[i].amount, order[i].price);
//	}
//
//}
