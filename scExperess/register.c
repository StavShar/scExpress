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
            scanf("%d", id);
            if (id>=0 && id<1000000000)
           


        printf("please enter your Password: ");
            flag = 1;
            int count = 0;
            scanf("%s", password);
            if (password >= 0 && password < 1000000000)

            
        } while (flag == 0);
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





 
