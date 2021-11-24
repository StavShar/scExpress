#include "ConfrimOrCancel.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

orders* ChangeStatus(orders* Allorders)
{
	int i, serial;
	char YN;//Yes and No to approve or cancel
	puts("Please enter the customer's id: ");
	scanf("%d", &serial);
	while (serial != Allorders->id)
	{
		puts("Worng id, try again.");
	}
	printf("Y = Confrim\nN = Cancel\n");
	printf("User details:\nName: %s :: ID: %d", Allorders[i].username, Allorders[i].id);
	scanf("%c", &YN);
	if (YN == "Y")
	{
		Allorders[i].status = "Y";
	}
	else
	{
		Allorders[i].status = "N";
	}
	return Allorders;
}