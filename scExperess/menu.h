#include "Cart.h"
#include "Orders.h"
#include "Orders_user.h"
#include "Product.h"
#include "register.h"
#include "searchProduct.h"

void mainMenu();
void printGeneralOptions();//A function that print the menu to screen.
void ManagerEntranceLoop(Manager* managers, int* size);
void printManagerEntranceOptions();//A function that print the menu to screen.
void ClientEntranceLoop(Client* clients, int* size);
void printClientEntranceOptions();//A function that print the menu to screen.
void ManagerLoop();
void printManagerOptions();//A function that print the menu to screen.
void ClientLoop();
void printClientOptions();//A function that print the menu to screen.
void Searches(Product* products, int size);//sub menu of different searches