#define _CRT_SECURE_NO_WARNINGS
#include "register.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


    //client register
    void ClientRegister(Client* list,int* size)
    {
        
        int i, flag = 1,id,password;
        char userName[50];
        char clubMember,status;
        printf("please enter your User Name: ");
        do {
            gets(userName);
            for (i = 0; i < strlen(userName); i++)
            {
                if ((userName[i] >= 65 && userName[i] <= 122) || userName[i] == ' ')
                {
                    if (userName[i] == ' ')
                    {
                        if (i == 0 || i == strlen(userName) - 1)
                        {
                            flag = 0;
                            
                        }
                    }
                    else if (i == strlen(userName) - 1)
                        flag = 1;
                    continue;
                }

                printf("Your User Name must be your full name, only letters are allowed, please try again: ");
                flag = 0;
                break;
            }
        } while (flag == 0);

        flag = 1;
        printf("please enter your Id: ");
        do {
            scanf("%d", id);
            if (id < 100000000 || id > 999999999)
            {
                printf("Id must be 9 digits. please tery again ");
                flag = 0;
                }

        } while (flag == 0);
           


        printf("please enter your Password: ");
        flag = 1;
        do{
            scanf("%d", password);
            if (password < 10000 || password > 99999)
            {
                printf("Password must be 5 digits. please tery again ");
                flag = 0;
            }
        } while (flag == 0);
        clubMember = 'n';
        status = 'y';
        
        list=Add_Client(list, size,userName,id,password,status,clubMember);
    }


    //set all products data in "Users.csv" file
    void set_All_Data_Client(Client* list, int size)
    {
        FILE* fw;

        fw = fopen("Clients.csv", "w");//open file for writing
        if (fw == NULL)
        {
            printf("Error!! file can't be opened\n");
            exit(1);
        }
        for (int i = 0; i < size; i++)
            fprintf(fw, "%s,%d,%d,%c,%c\n", list[i].name, list[i].id, list[i].password, list[i].status, list[i].clubMember);
        fclose(fw);//close file
    }

    Client* get_All_Data_Client(Client* list, int* size)
    {
        FILE* fr;
        char line[500];
        char* sp, *name;
        int id, pas, status, clubmember;

        fr = fopen("Clients.csv", "r");//open file for reading
        if (fr == NULL)
        {
            printf("Error!! file can't be opened\n");
            exit(1);
        }
        while (fgets(line, 500, fr) != NULL)
        {
            sp = strtok(line, ",");
            name = (char*)malloc((strlen(sp) + 1) * sizeof(char));
            if (name == NULL)
            {
                printf("Allocate memory failed.\n");
                exit(1);
            }
            strcpy(name, sp);
            sp = strtok(NULL, ",");
            id = atoi(sp);
            sp = strtok(NULL, ",");
            pas = atoi(sp);
            sp = strtok(NULL, ",");
            status = sp[0];
            sp = strtok(NULL, ",");
            clubmember = sp[0];
            list = Add_Client(list, size, name, id, pas, status, clubmember);
        }
        fclose(fr);//close file
        return list;
    }
    
    //client login
    int ClientLogin(Client* list, int* size)
    {
        int i, flag = 1,flag2=1, id, password;
        char userName[50];
        char clubMember;
        printf("please enter your Id: ");
        for (i = 0;i < size;i++)
        {
            if()
        }
        printf("please enter your User Name: ");
        do {
            gets(userName);
            if (strcmp(userName,c.name) == 0)
            {
                flag = 1;
                continue;
            }
            flag = 0;
            printf("Wrong User Name, please try again: ");

        } while (flag == 0);

        flag = 1;
        
        do {
            scanf("%d", id);
            if (id==c.id)
            {
                flag = 1;
                continue;
            }
            flag = 0;
            printf("Wrong Id, please try again: ");
        } while (flag == 0);
        
        if (c.status=='n')
        {
            flag2 = 0;
            printf("This user is blocked. Please contact management for more details");
        }

        //exit switch case back to client/manager login

        if (flag2)
        {
            flag = 1;
            printf("please enter your Password: ");
            do {
                scanf("%d", password);
                if (password==c.password)
                {
                    flag = 1;
                    continue;
                }
                flag = 0;
                printf("Wrong Password, please try again: ");
            } while (flag == 0);
            if (ClubMember(c)==1)

            return i;
        }
        else return -1;
    }

    //switchcase

     //actions on a client
    void ActionsOnClient()
    {
        int i, flag = 1;
        char userName[50];
        int id, password;
        printf("Please enter client's details: ");
        printf("Name: ");
        do {
            printf("User Name: ");
            gets(userName);
            printf("Id: ");
            scanf("%d", id);
            if (strcmp(userName, c.name) == 0 && id== c.id)
            {
                flag = 1;
                continue;
            }
            flag = 0;
            printf("User Name or Id are Incorrect , please try again: ");

        } while (flag == 0);
        //switchcase block un block
        int run = 1,option;
        while (run)
        {  //while we still want to run:
            printBlockOptions();//print the menu
            scanf("%d", &option);//get the user choise
            switch (option)
            {//act accordingly:
            case 1:
                c.status = 'n';               //activate the methods that resposible for it
                break;//end of this iteration
            case 2:
                c.status = 'y';               //activate the methods that resposible for it
                break;
            case 3:
                run = 0; //we want to stop running.
                printf("The system closed successfully\n");
                break;
            default: printf("Wrong option. Please try again!\n"); //not a supported option
            }//end switch

        }//end while(run)
    }

    //A function that print the menu to screen.
    void printBlockOptions()
    {
        printf("Please choose one of the following options:\n Press\n");
        printf("----------------------------------------------------------------------\n");
        printf("1- Block this user\n");
        printf("2- Unblock this user\n");
        printf("3- Exit\n");
        printf("----------------------------------------------------------------------\n");
    }//end method printManagerOptions()
    

    //adding manager into the manager's list
    Manager* Add_Manager(Manager* list, int* size, char* name, int id, int pas)
    {
        Manager* newlist = NULL;

        newlist = (Manager*)malloc((*size + 1) * sizeof(Manager));
        if (newlist == NULL)
        {
            printf("Allocate memory failed.\n");
            exit(1);
        }
        //copy old list
        for (int i = 0; i < *size; i++)
        {
            newlist[i].name = (char*)malloc((strlen(list[i].name) + 1) * sizeof(char));
            if (newlist[i].name == NULL)
            {
                printf("Allocate memory failed.\n");
                exit(1);
            }
            strcpy(newlist[i].name, list[i].name);
            
            newlist[i].id = list[i].id;
            newlist[i].password = list[i].password;
        }

        //add new product
        newlist[*size].name = (char*)malloc((strlen(name) + 1) * sizeof(char));
        if (newlist[*size].name == NULL)
        {
            printf("Allocate memory failed.\n");
            exit(1);
        }
        strcpy(newlist[*size].name, name);
        newlist[*size].id = id;
        newlist[*size].password = pas;

        (*size)++;
        //delete old list
        for (int i = 0; i < *size - 1; i++)
            free(list[i].name);

        free(list);
        return newlist;
    }

    //adding manager into the manager's list
    Client* Add_Client(Client* list, int* size, char* name, int id, int pas, char status, char clubmember)
    {
        Client* newlist = NULL;

        newlist = (Client*)malloc((*size + 1) * sizeof(Client));
        if (newlist == NULL)
        {
            printf("Allocate memory failed.\n");
            exit(1);
        }
        //copy old list
        for (int i = 0; i < *size; i++)
        {
            newlist[i].name = (char*)malloc((strlen(list[i].name) + 1) * sizeof(char));
            if (newlist[i].name == NULL)
            {
                printf("Allocate memory failed.\n");
                exit(1);
            }
            strcpy(newlist[i].name, list[i].name);

            newlist[i].id = list[i].id;
            newlist[i].password = list[i].password;
            newlist[i].status = list[i].status;
            newlist[i].clubMember = list[i].clubMember;
        }

        //add new product
        newlist[*size].name = (char*)malloc((strlen(name) + 1) * sizeof(char));
        if (newlist[*size].name == NULL)
        {
            printf("Allocate memory failed.\n");
            exit(1);
        }
        strcpy(newlist[*size].name, name);
        newlist[*size].id = id;
        newlist[*size].password = pas;
        newlist[*size].status = status;
        newlist[*size].clubMember = clubmember;

        (*size)++;
        //delete old list
        for (int i = 0; i < *size - 1; i++)
            free(list[i].name);

        free(list);
        return newlist;
    }

    //manager register
    void ManagerRegister()
    {
        int i, flag = 1;
        char userName[50];
        int id, password;
        Manager m;
        printf("please enter your User Name: ");
        do {
            gets(userName);
            for (i = 0; i < strlen(userName); i++)
            {
                if ((userName[i] >= 65 && userName[i] <= 122) || userName[i] == ' ')
                {
                    if (userName[i] == ' ')
                    {
                        if (i == 0 || i == strlen(userName) - 1)
                        {
                            flag = 0;

                        }
                    }
                    else if (i == strlen(userName) - 1)
                        flag = 1;
                    continue;
                }

                printf("Your User Name must be your full name, only letters are allowed, please try again: ");
                flag = 0;
                break;
            }
        } while (flag == 0);
        strcpy(m.name, userName);


        flag = 1;
        printf("please enter your Id: ");
        do {
            scanf("%d", id);
            if (id < 100000000 || id > 999999999)
            {
                printf("Id must be 9 digits. please tery again ");
                flag = 0;
            }

        } while (flag == 0);



        printf("please enter your Password: ");
        flag = 1;
        do {
            scanf("%d", password);
            if (password < 10000 || password > 99999)
            {
                printf("Password must be 5 digits. please tery again ");
                flag = 0;
            }
        } while (flag == 0);

        Manager* list = NULL;
        static int size = 1;
        set_All_Data_Client(list, size);
        Add_Manager(list, size, userName, id, password);
        ManagerLogin(m); //go to login

    }


    //set all products data in "Users.csv" file
    void set_All_Data_Manager(Manager* list, int size)
    {
        FILE* fw;

        fw = fopen("Managers.csv", "w");//open file for writing
        if (fw == NULL)
        {
            printf("Error!! file can't be opened\n");
            exit(1);
        }
        for (int i = 0; i < size; i++)
            fprintf(fw, "%s,%d,%d\n", list[i].name, list[i].id, list[i].password);
        fclose(fw);//close file
    }

    Manager* get_All_Data_Manager(Manager* list, int* size)
    {
        FILE* fr;
        char line[500];
        char* sp, * name;
        int id, pas;

        fr = fopen("Managers.csv", "r");//open file for reading
        if (fr == NULL)
        {
            printf("Error!! file can't be opened\n");
            exit(1);
        }
        while (fgets(line, 500, fr) != NULL)
        {
            sp = strtok(line, ",");
            name = (char*)malloc((strlen(sp) + 1) * sizeof(char));
            if (name == NULL)
            {
                printf("Allocate memory failed.\n");
                exit(1);
            }
            strcpy(name, sp);
            sp = strtok(NULL, ",");
            id = atoi(sp);
            sp = strtok(NULL, ",");
            pas = atoi(sp);
      
            list = Add_Manager(list, size, name, id, pas);
        }
        fclose(fr);//close file
        return list;
    }


    //manager login
    int ManagerLogin(Manager m)
    {
        int i, flag = 1;
        char userName[100];
        int id, password;
        printf("please enter your User Name: \n");
        do {
            getchar();
            gets(userName);
            if (strcmp(userName, m.name) == 0)
            {
                flag = 1;
                continue;
            }
            flag = 0;
            printf("Wrong User Name, please try again: ");

        } while (flag == 0);

        flag = 1;
        printf("please enter your Id: ");
        do {
            scanf("%d", id);
            if (id == m.id)
            {
                flag = 1;
                continue;
            }
            flag = 0;
            printf("Wrong Id, please try again: ");
        } while (flag == 0);

            flag = 1;
            printf("please enter your Password: ");
            do {
                scanf("%d", password);
                if (password == m.password)
                {
                    flag = 1;
                    continue;
                }
                flag = 0;
                printf("Wrong Password, please try again: ");
            } while (flag == 0);

                return i;
        
    }
    //switchcase


    //switchcase

    int ClubMember(Client c) //לתקן צריך לחפש את הלקוח הספציפי בקובץ
    {
        if (c.clubMember == 'n')
        {
            char option;
            printf("do you want to be a club member? choose one of the following options: \n ");
            printf("0 - yes \n ");
            printf("1 - no \n ");
            scanf("%c", &option);
            if (option == '0')
            {
                FILE* fw;
                fw = fopen("Clients.csv", "w");//open file for writing
                if (fw == NULL)
                {
                    printf("Error!! file can't be opened\n");
                    exit(1);
                }
                for (int i = 0; i < size; i++)
                    fprintf(fw, "%s,%d,%d,%c,%c\n", list[i].name, list[i].id, list[i].password, list[i].status, list[i].clubMember);
                fclose(fw);//close file
                return 1;
                else
                    return 0;

                // do a discount
            }
        }
    } 





 
