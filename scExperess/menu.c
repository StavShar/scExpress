#include "menu.h"

#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS


void mainMenu()
{
    Manager* managers;
    Client* clients;
    int managers_size, clients_size;
    int GeneralRun = 1;//do we want another iteration?
    int option;//the choosen option for the menu.
    float profit = 0.0;
    managers = get_All_Data_Manager(managers, &managers_size);
    clients = get_All_Data_Client(clients, &clients_size);
    while (GeneralRun)
    {  //while we still want to run:
        printGeneralOptions();//print the menu
        scanf("%d", &option);//get the user choise
        switch (option)
        {//act accordingly:
        case 1:
            ManagerEntranceLoop(managers, &managers_size, &profit);
            //activate the methods that resposible for it
            break;//end of this iteration
        case 2:
            ClientEntranceLoop(clients, clients_size);
            break;
        case 3:
            GeneralRun = 0; //we want to stop running.
            printf("The system closed successfully\n");
            break;
        default: printf("Wrong option. Please try again!\n"); //not a supported option
        }//end switch

    }//end while(run)
    set_All_Data_Client(clients, clients_size);
    set_All_Data_Manager(managers, managers_size);
}

//A function that print the menu to screen.
void printGeneralOptions()
{
    printf("Please choose one of the following options:\n Press\n");
    printf("----------------------------------------------------------------------\n");
    printf("1- Access manager menu\n");
    printf("2- Access client menu\n");
    printf("3- Exit\n");
    printf("----------------------------------------------------------------------\n");
}//end method printManagerOptions()

void ManagerEntranceLoop(Manager* managers, int* size, float* profit)
{
    int ManagerEntranceRun = 1;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (ManagerEntranceRun)
    {  //while we still want to run:
        printGeneralOptions();//print the menu
        scanf("%d", &option);//get the user choise
        switch (option)
        {//act accordingly:
        case 1:
            ManagerRegister();
            //activate the methods that resposible for it
            break;//end of this iteration
        case 2:
            ManagerLogin();
            ManagerLoop(profit);
            break;
        case 3:
            ManagerEntranceRun = 0; //we want to stop running.
            printf("The system closed successfully\n");
            break;
        default: printf("Wrong option. Please try again!\n"); //not a supported option
        }//end switch

    }//end while(run)
}

//A function that print the menu to screen.
void printManagerEntranceOptions()
{
    printf("                            Welcome Manager:\nPlease choose one of the following options:\n Press\n");
    printf("----------------------------------------------------------------------\n");
    printf("1- Regiter\n");
    printf("2- Log in\n");
    printf("3- Exit\n");
    printf("----------------------------------------------------------------------\n");
}//end method printOptions()

void ClientEntranceLoop(Client* clients, int* size)
{
    int ClientEntranceRun = 1;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (ClientEntranceRun)
    {  //while we still want to run:
        printClientEntrancOptions();//print the menu
        scanf("%d", &option);//get the user choise
        switch (option)
        {//act accordingly:
        case 1:
            ClientRegister();
            //activate the methods that resposible for it
            break;//end of this iteration
        case 2:
            if (ClientLogin() == 1)
            {
                ClientLoop();
            }
            ClientEntranceLoop(clients, size);// ????


            break;
        case 3:
            ClientEntranceRun = 0; //we want to stop running.
            printf("The system closed successfully\n");
            break;
        default: printf("Wrong option. Please try again!\n"); //not a supported option
        }//end switch

    }//end while(run)
}

//A function that print the menu to screen.
void printClientEntranceOptions()
{
    printf("                            Welcome Costumer:\nPlease choose one of the following options:\n Press\n");
    printf("----------------------------------------------------------------------\n");
    printf("1- Regiter\n");
    printf("2- Log in\n");
    printf("3- Exit\n");
    printf("----------------------------------------------------------------------\n");
}//end method printOptions()

void ManagerLoop(int* profit)
{
    Product* products;
    orders* Orders;
    int products_size, Orders_size, sn, tr, rcount;
    int ManagerRun = 1;//do we want another iteration?
    int option;//the choosen option for the menu.
    products = Get_All_Data(products, &products_size);
    Orders = Get_All_Waiting_Orders(Orders, &Orders_size);
    while (ManagerRun)
    {  //while we still want to run:
        printManagerOptions();//print the menu
        scanf("%d", &option);//get the user choise
        switch (option) {//act accordingly:
        case 1:
            ActionsOnProducts();

            break;//end of this iteration
        case 2:
            Searches(products, products_size);

            break;
        case 3:
            printf("Enter serial number: ");
            scanf("%d", &sn);
            Update_Price(products, products_size, sn);
            break;
        case 4:
            ViewOrders();
            break;
        case 5:
            ChangeStatus();
            break;
        case 6:
            Get_Rating_vars(&tr, &rcount);
            Print_Rating(tr, rcount);
            Set_Rating_vars(tr, rcount);
            break;
        case 7:
            ActionsOnClient();
            break;
        case 8:
            printf("Enter serial number: ");
            scanf("%d", &sn);
            Discount_Product(products, products_size, sn);
            break;
        case 9:
            DailyProfit(profit,);
            break;
        case 10:
            Print_All_Products(products, products_size);
            Print_Products_Out_Of_Stock(products, products_size);
            break;
        case 11:
            ManagerRun = 0; //we want to stop running.
            printf("Goodbye!\n");//tell the user goodbye.
            break;
        default: printf("Wrong option. Please try again!\n"); //not a supported option
        }//end switch

    }//end while(run)
    set_All_Data(products, products_size);
    Set_All_Waiting_Orders(Orders, Orders_size);
}

//A function that print the menu to screen.
void printManagerOptions()
{
    printf("Please choose one of the following options:\n Press\n");
    printf("----------------------------------------------------------------------\n");
    printf("1- Actions on a product\n");
    printf("2- Search product\n");
    printf("3- change price\n");
    printf("4- View orders\n");
    printf("5- Change order status\n");
    printf("6- Watch average site rating\n");
    printf("7- Actions on client\n");
    printf("8- Sales\n");
    printf("9- Daily profit\n");
    printf("10- Inventory status\n");
    printf("11- Logout\n");
    printf("----------------------------------------------------------------------\n");
}//end method printManagerOptions()

void ClientLoop()
{
    Product* products;
    orders* Orders;
    Cart cart;
    int products_size, Orders_size, cart_size, sn, quantity, tr, rcount;
    int ClientRun = 1, option;
    char name[50];
    products = Get_All_Data(products, &products_size);
    Orders = Get_All_Waiting_Orders(Orders, &Orders_size);

    while (ClientRun)
    {//while we still want to run:
        printClientOptions();//print the menu
        scanf("%d", &option);//get the user choise
        switch (option)
        {//act accordingly:
        case 1:orderHistory();
            //activate the functions that resposible for it
            break;//end of this iteration
        case 2:
            Select_cat(products, products_size);
            break;
        case 3:
            Low_to_high(products, products_size);
            break;
        case 4:
            printf("Enter name of product: ");
            getchar();
            gets(name);
            Name_search(products, products_size, name);
            break;
        case 5:
            Get_Rating_vars(&tr, &rcount);
            Print_Rating(tr, rcount);
            Set_Rating_vars(tr, rcount);
            break;
        case 6:
            printf("Enter serial number of product: ");
            scanf("%d", &sn);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            cart = Add_To_Cart(products, products_size,cart,&cart_size,sn,quantity);
            break;
        case 7:
            View_cart(products, products_size, cart, cart_size);
            break;
        case 8:
            Get_Rating_vars(&tr, &rcount);
            Website_ranking(&tr, &rcount);
            Set_Rating_vars(tr, rcount);
            break;
        case 9: ClientRun = 0; //we want to stop running.
            printf("Goodbye!\n");//tell the user goodbye.
            break;
        default: printf("Wrong option. Please try again!\n"); //not a supported option
        }//end switch

    }//end while(run)
    set_All_Data(products, products_size);
    Set_All_Waiting_Orders(Orders, Orders_size);
}

//A function that print the menu to screen.
void printClientOptions()
{
    printf("Please choose one of the following options:\n Press\n");
    printf("----------------------------------------------------------------------\n");
    printf("1- View order history\n");
    printf("2- Find products by categories\n");
    printf("3- Watch products by increasing price\n");
    printf("4- Search product by name\n");
    printf("5- Watch average site rating\n");
    printf("6- Add product to the cart\n");
    printf("7- Watch current cart\n");
    printf("8- Rate the site\n");
    printf("9- Logout\n");
    printf("----------------------------------------------------------------------\n");
}

void Searches(Product* products, int size)
{
    int sn, option, flag = 1;
    char name[50];

    do {
        printf("1- Search product by name\n2- Search product by serial number\n");
        scanf("%d", &option);
        if (option == 1)
        {
            printf("Enter name of product: ");
            getchar();
            gets(name);
            Name_search(products, size, name);
            flag = 0;
        }
        else if (option == 2)
        {
            printf("Enter serial number of product: ");
            scanf("%d", &sn);
            Serial_num_search(products, size, sn);
            flag = 0;
        }
        else
            printf("Wrong number, please try again.\n");
    } while (flag);
}
void Get_Rating_vars(int* tr, int* rcount)
{
    FILE* fr;
    char line[500];
    char* sp;

    fr = fopen("Rating_Vars.csv", "r");//open file for reading
    if (fr == NULL)
    {
        printf("Error!! file can't be opened\n");
        exit(1);
    }
    while (fgets(line, 500, fr) != NULL)
    {
        sp = strtok(line, ",");
        (*tr) = atoi(sp);
        sp = strtok(NULL, ",");
        (*rcount) = atoi(sp);
    }
    fclose(fr);//close file
}

void Set_Rating_vars(int tr, int rcount)
{
    FILE* fw;

    fw = fopen("Rating_Vars.csv", "w");//open file for writing
    if (fw == NULL)
    {
        printf("Error!! file can't be opened\n");
        exit(1);
    }
    fprintf(fw, "%d,%d\n", tr, rcount);
       
    fclose(fw);//close file
}
//end method printClientOptions()






