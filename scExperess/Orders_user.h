#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1

typedef struct
{
	char name[30];
	int quantity;
	float price;

}Product;

typedef struct
{
	char* username;
	int id;
	Product* items;
}order;

void orderHistory(FILE* HisOr, char id[9], Product order[N], int items);
