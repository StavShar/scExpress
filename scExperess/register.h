#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct
{
	char name[50];
	char id[50];
	char password[50];
	char status[50];
	char clubMember[50];
} Client;

typedef struct
{
	char name[50];
	char id[50];
	char password[50];
} Manager;

//Client Register(Members* list, int size, int sn);
void ClientRegister();
int ClientLogin();
void ClientLogout();
Manager* Add_Manager(Manager* list, int* size, char* name, int id, int pas);
void ManagerRegister();
void ManagerLogin();
void ManagerLogout();
void ActionsOnClient(Client c);
void set_All_Data_Client(Client* list, int size);
void get_All_Data_Client(Client* list, int size);
void set_All_Data_Manager(Manager* list, int size);
void get_All_Data_Manager(Manager* list, int size);
void ClubMember(Client c);