#include<stdio.h>
#include<stdlib.h>
struct hotel
{
  char item[20];
  int qty;
  float price;
  struct hotel *link;
}*ptrhotel, *head;
int main()
{
 ptrhotel=NULL;
 printf("\n enter the number of items");int num;
 scanf("%d",&num);
 ptrhotel=(struct hotel *)malloc(num * sizeof(struct hotel));
 head=ptrhotel;
 for(int i=0;i<num;i++)
 {
   printf("\n enter name of item#%d",i+1);
   scanf("%s",ptrhotel->item);
   printf("\nenter price of item#%d",i+1);
   scanf("%f",&ptrhotel->price);
   printf("\n enter the quantity of item#%d",i+1);
   scanf("%d",&ptrhotel->qty);
   ptrhotel->link=ptrhotel +1;
   ptrhotel=ptrhotel->link;
   
  }
  for(int j=0;j<num;j++)
  {
   printf("\nitem #%d details are:",j+1);
   printf("\n item name :%s, item price %f,item qty %d",head->item,head->price,head->qty);
   head=head->link;
  }
  printf("\n");
 }     
