//#include "searchProduct.h"
//#include <stdio.h>
//#include <string.h>
//
//char Name_search(Product* list,int size ,char* name)
//{
//    int i ,x=0;
//    if(name == NULL)
//    {
//        printf("EROR");
//        return 0;
//    }
//
//    for(i=0; i<size; i++)
//    {
//        if(strcmp(list[i].name, name) == 0)
//        {
//            x++;
//            return *list[i].name;
//        }
//    }
//    if(x == 0)
//    {
//        printf("the product not exist");
//    }
//    return 0;
//}
//
//int Serial_num_search(Product* list,int size ,int num)
//{
//    int i;
//    if(num == 0)
//    {
//        printf("EROR");
//        return 0;
//    }
//
//    for(i=0; i<size; i++)
//    {
//        if(list[i].sn == num)
//        {
//            return list[i].sn;
//        }
//    }
//    return 0;
//    
//}
//
////printing the average rating
//void Print_Rating(int total_rate, int rating_count)
//{
//    float temp = ((float)total_rate / (float)rating_count);
//    printf("The average rating of our site is: %.1f\n", temp);
//}
//
//void Website_ranking(int* total ,int* count)
//{
//    int number;
//    printf("Please enter a number from one to five");
//    scanf("%d" ,&number);
//    
//    if(number > 0 && number <= 5)
//    {
//        *total+= number;
//        *count = *count + 1;
//    }
//    else
//    {
//        printf("wrong number");
//    }
//    
//}
//
//void Low_to_high(Product* list,int size)
//{
//    int i ,temp = 0 ,j;
//    
//    if(size == 0)
//    {
//        printf("eror");
//        return;
//    }
//    
//    
//    for(i = 0; i < size - 1; i++)
//    {
//        for(j = 0; i < size - 1; j++)
//        {
//            if(list[j].price > list[j + 1].price)
//            {
//                temp = list[j].price;
//                list[j].price = list[j + 1].price;
//                list[j + 1].price = temp;
//            }
//        }
//    }
//    for(i = 0; i < size ; i++)
//    {
//        Print_Product(list[i]);
//    }
//}
