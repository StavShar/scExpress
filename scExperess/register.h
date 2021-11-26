#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct
{
	char* name;
	int id;
	int password;
	char status;
	char clubMember;
} Client;

typedef struct
{
	char* name;
	int id;
	int password;
} Manager;

//Client Register(Members* list, int size, int sn);
void ClientRegister(Client* list, int* size);
int ClientLogin(Client* list, int* size);
Manager* Add_Manager(Manager* list, int* size, char* name, int id, int pas);
Client* Add_Client(Client* list, int* size, char* name, int id, int pas, char status, char clubmember);
void ManagerRegister(Manager* list, int* size);
int ManagerLogin(Manager* list, int* size);
void ActionsOnClient();
void set_All_Data_Client(Client* list, int size);
Client* get_All_Data_Client(Client* list, int* size);
void set_All_Data_Manager(Manager* list, int size);
Manager* get_All_Data_Manager(Manager* list, int* size);
void ClubMember(Client* list, int* size, int clientIndex);