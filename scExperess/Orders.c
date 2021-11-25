#include "Orders.h"


/* REMEMBER: free all the allocate memory in the main */


//Manager's view of all the orders
//ptr initialized to 0 at first, to check if there is any history at all
void ViewOrders(orders* ListOrders, int* ptr)
{
	if (*ptr)
	{
		FILE* View;
		char file;
		View = fopen("HistoryOfAllOrders.csv", "r");
		while (View != EOF)
		{
			//fputc(file, View);
		}
	}
	else
		puts("There is no history yet.");
}

//The function bascilly adding one order at the time 
//Flag for poting that if this is the first user or not
//The *ptr for pointing at the location of the user order 
//pSer is initialized at digit 10000, to make a following serial number
//username is the name of the customer
//id is the id number of the customer
orders MakeOrder(ProductFile* listPro, int* sizep, int orderSN, char* username, int id)
{
	orders order;
	order.username = (char*)malloc((strlen(username) + 1) * sizeof(char));
	if (order.username == NULL)
	{
		printf("Allocate memory failed.\n");
		exit(1);
	}
	strcpy(order.username, username);
	order.id = id;
	order.items = listPro;
	order.serial = orderSN;
	order.status = "w";

	return order;
}

//pSer is initialized at digit 10000, to make a following serial number
int getSer(int* pSer)
{
	(*pSer) += 4;
	return *pSer;
}

orders* Get_All_Waiting_Orders(orders* list, int* size)
{
	FILE* fr;
	ProductFile* plist;
	char line[500];
	char* sp, * username, * name;
	int Osn, sn2, amount, id, size1 = 0;
	char status;
	float price;
	fr = fopen("WaitingOrders.csv", "r");//open file for reading
	if (fr == NULL)
	{
		printf("Error!! file can't be opened\n");
		exit(1);
	}
	while (fgets(line, 500, fr) != NULL)
	{
		sp = strtok(line, ",");
		username = (char*)malloc((strlen(sp) + 1) * sizeof(char));
		if (username == NULL)
		{
			printf("Allocate memory failed.\n");
			exit(1);
		}
		strcpy(username, sp);
		sp = strtok(NULL, ",");
		id = atoi(sp);
		sp = strtok(NULL, ",");
		Osn = atoi(sp);
		sp = strtok(NULL, ",");
		status = sp[0];
		sp = strtok(line, ",");
		size1 = atoi(sp);
		plist = (ProductFile*)malloc(size1 * sizeof(ProductFile));
		if (plist == NULL)
		{
			printf("Allocate memory failed.\n");
			exit(1);
		}
		for (int i = 0; i < size1; i++)//init plist
		{
			plist[i].name = (char*)malloc((strlen(sp) + 1) * sizeof(char));
			if (plist[i].name == NULL)
			{
				printf("Allocate memory failed.\n");
				exit(1);
			}
			strcpy(plist[i].name, sp);
			sp = strtok(NULL, ",");
			sn2 = atoi(sp);
			sp = strtok(NULL, ",");
			amount = atoi(sp);
			sp = strtok(NULL, ",");
			price = atof(sp);
			plist[i].amount = amount;
			plist[i].price = price;
			plist[i].sn = sn2;
		}
		list = Add_Order(list, size, MakeOrder(plist, &size1, Osn, username, id));
	}
	fclose(fr);//close file
	return list;
}

orders* Add_Order(orders* list, int* size, orders order)
{
	orders* newlist;
	newlist = (orders*)malloc((*size + 1) * sizeof(orders));
	if (newlist == NULL)
	{
		printf("Allocate memory failed.\n");
		exit(1);
	}
	//copy old list
	for (int i = 0; i < *size; i++)
	{
		newlist[i].username = (char*)malloc((strlen(list[i].username) + 1) * sizeof(char));
		if (newlist[i].username == NULL)
		{
			printf("Allocate memory failed.\n");
			exit(1);
		}
		strcpy(newlist[i].username, list[i].username);
		newlist[i].id = list[i].id;
		newlist[i].items = list[i].items;
		newlist[i].serial = list[i].serial;
		newlist[i].status = list[i].status;
		newlist[i].size = list[i].size;
	}
	newlist[*size].username = order.username;
	newlist[*size].id = order.id;
	newlist[*size].items = order.items;
	newlist[*size].serial = order.serial;
	newlist[*size].status = order.status;
	newlist[*size].size = order.size;
	(*size)++;

	free(list);

	return newlist;
}

//pTotalPrice initialized to 0 at first, to start with 0 profit
int DailyProfit(float* pTotalPrice, float tp)
{
	*pTotalPrice += tp;
	return *pTotalPrice;
}

void PrintfProfit(int* pTotalPrice)
{
	printf("The total profit of the day is: %d\n", *pTotalPrice);

}

orders* ChangeStatus(orders* Allorders)
{
	int i=0, serial;
	char YN;//Yes and No to approve or cancel
	puts("Please enter the customer's id: ");
	scanf("%d", &serial);
	while (serial != Allorders->id)
	{
		puts("Worng id, try again.\n");
	}
	printf("Y = Confrim\nN = Cancel\n");
	printf("User details:\nName: %s :: ID: %d", Allorders[i].username, Allorders[i].id);
	scanf("%c", &YN);
	if (YN == "Y")
	{
		Allorders[i].status = "Y";
	}
	else
	{
		Allorders[i].status = "N";
	}
	return Allorders;
}

//status should get if the order is approved or not 
//order shloud get the array of the structure
//items is the number of the items that in the cart
//pTotalPrice initialized to 0 at first, to start with 0 profit
/*----> The user's orders history*/
void orderHistory(int id, ProductFile* order, int items, char status, int* ptr, float* pTotalPrice)
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

