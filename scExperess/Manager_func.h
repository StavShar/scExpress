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




int main()
{
	int* pTotalPrice = 0;
	int* ptr = 0;

}