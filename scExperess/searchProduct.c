#include "searchProduct.h"
#include <stdio.h>
#include <string.h>

void Name_search(Product* list,int size ,char* name)
{
    int i ,x=0;
    if(name == NULL)
    {
        printf("EROR\n");
        return 0;
    }

    for(i=0; i<size; i++)
    {
        if(strcmp(list[i].name, name) == 0)
        {
            x++;
            printf("\n\n");
            Print_Product(list[i]);
            printf("\n\n");
        }
    }
    if(x == 0)
    {
        printf("the product not exist\n");
    }
    return 0;
}

void Serial_num_search(Product* list,int size ,int num)
{
    int i;
    if(num == 0)
    {
        printf("EROR\n");
    }

    for(i=0; i<size; i++)
    {
        if(list[i].sn == num)
        {
            printf("\n\n");
            Print_Product(list[i]);
            printf("\n\n");
        }
    }
}

//printing the average rating
void Print_Rating(int total_rate, int rating_count)
{
    float temp = ((float)total_rate / (float)rating_count);
    printf("The average rating of our site is: %.1f\n", temp);
}

void Website_ranking(int* total ,int* count)
{
    int number;
    printf("Please enter a number from one to five");
    scanf("%d" ,&number);
    
    if(number > 0 && number <= 5)
    {
        (*total)+= number;
        (*count)++;
    }
    else
    {
        printf("wrong number\n");
    }
    
}

void Low_to_high(Product* list,int size)
{
    int i ,temp = 0 ,j;
    
    if(size == 0)
    {
        printf("eror");
        return;
    }
    
    
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; i < size - 1; j++)
        {
            if(list[j].price > list[j + 1].price)
            {
                temp = list[j].price;
                list[j].price = list[j + 1].price;
                list[j + 1].price = temp;
            }
        }
    }
    for(i = 0; i < size ; i++)
    {
        Print_Product(list[i]);
    }
}
void Select_cat(Product* list,int size)
{
    int x = 0;
    char* cat,str[50];
    printf("Please select the category name: ");
    getchar();
    gets(str);
    cat = (char*)malloc((strlen(str) + 1) * sizeof(char));
    if(cat == NULL)
    {
        printf("eror\n");
        return;
    }
    
    for(int i = 0; i < size; i++)
    {
        if(strcmp(list[i].category,cat))
        {
            printf("\n\n");
            Print_Product(list[i]);
            printf("\n\n");
            x++;
        }
        
    }
    if(x == 0)
    {
        printf("This category does not exist\n");
    }
    
}

