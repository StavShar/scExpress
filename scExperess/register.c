#define _CRT_SECURE_NO_WARNINGS
#include "register.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


    //client register
    void ClientRegister()
    {
        int i, flag = 1;
        char userName[50], id[50], password[50],status[50];
        Client c;
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
        strcpy(c.name, userName);


        printf("please enter your Id: ");
        do {
            flag = 1;
            int count = 0;
            scanf("%s", id);
            for (i = 0; i < strlen(id); i++)
            {
                if (id[i] >= '0' && id[i] <= '9')
                {
                    count++;;
                }
                else
                {
                    flag = 0;
                    printf("Id number must be only digits, please try again: ");
                    break;
                }
            }
            if (count != 9 && flag == 1)
            {
                flag = 0;
                printf("Id number must be 9 digits, please try again: ");
            }
        } while (flag == 0);
        strcpy(c.id,id);


        printf("please enter your Password: ");
        do{
            flag = 1;
            int count = 0;
            scanf("%s", password);
            for (i = 0; i < strlen(password); i++)
            {
                if (password[i] >= '0' && password[i] <= '9')
                {
                    count++;;
                }
                else
                {
                    flag = 0;
                    printf("Password must be only digits, please try again: ");
                    break;
                }
            }
            if (count > 5 && flag == 1)
            {
                flag = 0;
                printf("Password can not be more than 5 digits, please try again: ");
            }
        } while (flag == 0);
        strcpy(c.password,password);

        strcpy(c.status, "free 2 buy");
            //write in file

        strcpy(c.clubMember, "not a club member");
        //write in file


          ClientLogin(c); //go to login
    }


    //set all products data in "Users.csv" file
    void set_All_Data_Client(Client* list, int size)
    {
        FILE* fw;

        fw = fopen("Users.csv", "w");//open file for writing
        if (fw == NULL)
        {
            printf("Error!! file can't be opened\n");
            exit(1);
        }
        for (int i = 0; i < size; i++)
            fprintf(fw, "%s,%s,%s,%s \n", list[i].name, list[i].id, list[i].password, list[i].status);
        fclose(fw);//close file
    }



    //client login
    int ClientLogin()
    {
        int i, flag = 1,flag2=1;
        char userName[50], id[50], password[50],clubMember[50];
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
        printf("please enter your Id: ");
        do {
            scanf("%s", id);
            if (strcmp(id, c.id) == 0)
            {
                flag = 1;
                continue;
            }
            flag = 0;
            printf("Wrong Id, please try again: ");
        } while (flag == 0);
        
        if (strcmp(c.status, "blocked") == 0)
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
                scanf("%s", password);
                if (strcmp(password, c.password) == 0)
                {
                    flag = 1;
                    continue;
                }
                flag = 0;
                printf("Wrong Password, please try again: ");
            } while (flag == 0);
            ClubMember(c);
            return 1;
        }
        else return 0;
    }

    //switchcase

     //actions on a client
    void ActionsOnClient(Client c)
    {
        int i, flag = 1;
        char userName[50], id[50], password[50];
        printf("Please enter client's details: ");
        printf("Name: ");
        do {
            printf("User Name: ");
            gets(userName);
            printf("Id: ");
            scanf("%s", id);
            if (strcmp(userName, c.name) == 0 && strcmp(id, c.id) == 0)
            {
                flag = 1;
                continue;
            }
            flag = 0;
            printf("User Name or Id are Incorrect , please try again: ");

        } while (flag == 0);
        printf("Id: ");

        //switchcase block un block

        //case block
        strcpy(c.status, "blocked");

        //case unblock
        strcpy(c.status, "free 2 buy");
    }

    void ClientLogout() 
    {
        //end switchcase exit system go to manager/client menu
    }

    //manager register
    void ManagerRegister()
    {
        int i, flag = 1;
        char userName[50], id[50], password[50];
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


        printf("please enter your Id: ");
        do {
            flag = 1;
            int count = 0;
            scanf("%s", id);
            for (i = 0; i < strlen(id); i++)
            {
                if (id[i] >= '0' && id[i] <= '9')
                {
                    count++;;
                }
                else
                {
                    flag = 0;
                    printf("Id number must be only digits, please try again: ");
                    break;
                }
            }
            if (count != 9 && flag == 1)
            {
                flag = 0;
                printf("Id number must be 9 digits, please try again: ");
            }
        } while (flag == 0);
        strcpy(m.id, id);


        printf("please enter your Password: ");
        do {
            flag = 1;
            int count = 0;
            scanf("%s", password);
            for (i = 0; i < strlen(password); i++)
            {
                if (password[i] >= '0' && password[i] <= '9')
                {
                    count++;;
                }
                else
                {
                    flag = 0;
                    printf("Password must be only digits, please try again: ");
                    break;
                }
            }
            if (count > 5 && flag == 1)
            {
                flag = 0;
                printf("Password can not be more than 5 digits, please try again: ");
            }
        } while (flag == 0);
        strcpy(m.password, password);

        ManagerLogin(m); //go to login

    }


    //set all products data in "Users.csv" file
    void set_All_Data_Manager(Manager* list, int size)
    {
        FILE* fw;

        fw = fopen("Users.csv", "w");//open file for writing
        if (fw == NULL)
        {
            printf("Error!! file can't be opened\n");
            exit(1);
        }
        for (int i = 0; i < size; i++)
            fprintf(fw, "%s,%s,%s \n", list[i].name, list[i].id, list[i].password);
        fclose(fw);//close file
    }


    //manager login
    void ManagerLogin()
    {
        int i, flag = 1;
        char userName[50], id[50], password[50];
        printf("please enter your User Name: ");
        do {
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
            scanf("%s", id);
            if (strcmp(id, m.id) == 0)
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
            scanf("%s", password);
            if (strcmp(password, m.password) == 0)
            {
                flag = 1;
                continue;
            }
            flag = 0;
            printf("Wrong Password, please try again: ");
        } while (flag == 0);

    }
    //switchcase


    void ManagerLogout()
    {
        //end switchcase exit system go to manager/client menu
    }

    //switchcase

    void ClubMember(Client c)
    {
        if (strcpy(c.clubMember, "club member") != 0)
        {
            char option;
            printf("do you want to be a club member? choose one of the options: \n ");
            printf("0 - yes \n ");
            printf("1 - no \n ");
            scanf("%c", &option);
            if (option == '0')
                strcpy(c.clubMember, "club member");

            // do a discount
        }
    }





 
