#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1

typedef struct
{
	char name[30];
	int sn;
	int amount;
	float price;

}ProductFile;

typedef struct
{
	char* username;
	int id;
	float tp;
	char status;

	ProductFile* items;
}order;


