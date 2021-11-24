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
	char status;
	ProductFile* items;
}orders;

void orderHistory(int id, ProductFile* order, int items, char status);
//status shloud get if the order is approved or not 
int main()
{
	ProductFile* order;
	int id;
	int items, i;

	scanf("%d", &id);
	char name[50];
	char filechar = { 0 };
	puts("How many items?");
	scanf("%d", &items);
	order = (ProductFile*)malloc(items * sizeof(ProductFile));
	for (i = 0; i < items; i++)
	{
		getchar();
		gets(order[i].name);
		scanf("%d", &order[i].sn);
		scanf("%d", &order[i].amount);
		scanf("%f", &order[i].price);
	}
	orderHistory(id, order, items);
	free(order);
	return 0;
}

