#include "Orders_user.h"

int main()
{
	FILE* orders = fopen("orders.csv", "r");
	Product order[N];
	char id[9] = "131231221";
	int items, i;

	if (orders == NULL)
	{
		printf("Can't open file. ");
		exit(1);
	}


	char name[50];
	char filechar = { 0 };
	puts("How many items?");
	scanf("%d", &items);
	/*order = (Product*)malloc(items * sizeof(Product));*/
	for (i = 0; i < items; i++)
	{
		getchar();
		gets(order[i].name);
		scanf("%d", &order[i].quantity);
		scanf("%f", &order[i].price);


	}

	orderHistory(orders, id, order, items);


	while (filechar != EOF)
	{
		filechar = fgetc(orders);
		printf("%c", filechar);
	}
	fclose(orders);


	return 0;

}




void orderHistory(FILE* HisOr, char id[9], Product order[N], int items)
{
	char filename[50];
	int i;
	sprintf(filename, "%s.csv", id);
	HisOr = fopen(filename, "a");
	if (!filename)
	{
		puts("Open file have failed");
		exit(0);
	}
	for (i = 0; i < items; i++)
	{
		
		
		fprintf(filename, "%s,%d,%f\n", order[i].name, order[i].quantity, order[i].price);


	}


	fclose(HisOr);
}