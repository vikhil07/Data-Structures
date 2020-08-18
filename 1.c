#include<stdio.h>
void getarr(int somearr[],int size)
{
    int k;
    for(k=0;k<size;k++)
        scanf("%d",&somearr[k]);
}

float average(int arr[],int size)
{
    int sum=0;
    for(int i=0; i<size; i++)
        sum = sum + arr[i];
    float avg = sum/size;
    return avg;
}
int main()
{
    int N;
    printf("Enter the size of an array-");
    scanf("%d",&N);
    int arr[N];
    printf("Enter elements into array\n");
    getarr(arr,N);
    float avg = average(arr,N);
    printf("Average is : %f\n",avg);
    return 0;
}
