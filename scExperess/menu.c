#include "menu.h"
#include "register.h"
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS


void mainMenu()
{
    int GeneralRun = 1;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (GeneralRun)
    {  //while we still want to run:
        printGeneralOptions();//print the menu
        scanf("%d", &option);//get the user choise
        switch (option)
        {//act accordingly:
        case 1:
            ManagerEntranceLoop();
            //activate the methods that resposible for it
            break;//end of this iteration
        case 2:
            ClientEntranceLoop();
            break;
        case 3:
            GeneralRun = 0; //we want to stop running.
            printf("The system closed successfully\n");
            break;
        default: printf("Wrong option. Please try again!\n"); //not a supported option
        }//end switch

    }//end while(run)
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

    void ManagerEntranceLoop()
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
                ManagerLoop();
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
    void printanagerEntranceOptions()
    {
        printf("                            Welcome Manager:\nPlease choose one of the following options:\n Press\n");
        printf("----------------------------------------------------------------------\n");
        printf("1- Regiter\n");
        printf("2- Log in\n");
        printf("3- Exit\n");
        printf("----------------------------------------------------------------------\n");
    }//end method printOptions()

    void ClientEntranceLoop()
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
                if(ClientLogin() == 1)
                {
                    ClientLoop();
                }
                ClientEntranceLoop();

                
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


            void ManagerLoop()
            {
                int ManagerRun = 1;//do we want another iteration?
                int option;//the choosen option for the menu.
                while (ManagerRun)
                {  //while we still want to run:
                    printManagerOptions();//print the menu
                    scanf("%d", &option);//get the user choise
                    switch (option) {//act accordingly:
                    case 1:
                        
                        break;//end of this iteration
                    case 2:

                        break;
                    case 3:

                        break;
                    case 4:

                        break;
                    case 5:

                        break;
                    case 6:

                        break;
                    case 7:

                        break;
                    case 8:

                        break;
                    case 9:

                        break;
                    case 10: 
                        ManagerRun = 0; //we want to stop running.
                        printf("Goodbye!\n");//tell the user goodbye.
                        break;
                    default: printf("Wrong option. Please try again!\n"); //not a supported option
                    }//end switch

                }//end while(run)
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
    printf("6- Acrions on client\n");
    printf("7- Sales\n");
    printf("8- Daily profit\n");
    printf("9- Inventory status\n");
    printf("10- Logout\n");
    printf("----------------------------------------------------------------------\n");
}//end method printManagerOptions()


voidManagerLoop()
{
    int ClientRun = 1, option;
    while (ClientRun)
    {//while we still want to run:
        printClientOptions();//print the menu
        scanf("%d", &option);//get the user choise
        switch (option)
        {//act accordingly:
        case 1:
            //activate the functions that resposible for it
            break;//end of this iteration
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10: ClientRun = 0; //we want to stop running.
            printf("Goodbye!\n");//tell the user goodbye.
            break;
        default: printf("Wrong option. Please try again!\n"); //not a supported option
        }//end switch

    }//end while(run)
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
        printf("5- Logout\n");
        printf("----------------------------------------------------------------------\n");
    }//end method printClientOptions()









