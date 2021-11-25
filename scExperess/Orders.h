

typedef struct
{
	char* name;
	int sn;
	int amount;
	float price;
}ProductFile;

typedef struct
{
	char* username;
	int id;
	int serial;
	char status;
	ProductFile* items;
}orders;



int DailyProfit(float* pTotalPrice, float tp);
void PrintfProfit(int* pTotalPrice);
int countItems(ProductFile* ListOrders);
int countOrder(orders* ListOrders);
orders* MakeOrder(ProductFile* listPro, int flag, int* ptr);
void ViewOrders(orders* ListOrders, int* ptr);
orders* ChangeStatus(orders* Allorders);
void orderHistory(int id, ProductFile* order, int items, char status, int* ptr, float* pTotalPrice);
int getSer(int* pSer);