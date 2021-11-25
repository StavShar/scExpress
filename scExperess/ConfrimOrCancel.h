
struct
{
	char name[30];
	int sn;
	int amount;
	float price;
}typedef ProductFile;

typedef struct
{
	char* username;
	int id;
	int serial;
	char status;//Confirm or cancel\delay the order.
	ProductFile* items;

}orders;

int getSer(int* pSer);