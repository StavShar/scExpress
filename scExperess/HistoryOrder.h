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
	ProductFile* items;
}orders;

void orderHistory(int id, ProductFile* order, int items);

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

	return 0;

}

