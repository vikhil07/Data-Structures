#include<stdio.h>
int getarray(int arr[],int N)
{
    for(int k=0; k<N; k++)
        scanf("%d",&arr[k]);
    return 1;
}
int putarray(int arr[],int N)
{
    for(int k=0; k<N; k++)
        printf("%3d",arr[k]);

}
void swap(int *a,int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}
void bubble_sort(int a[], int N)
{
     swap(&a[0],&a[1]);
     printf("\n\nAfter Changing position inside Sort function : ");
		putarray(a,N);
     for(int i=0;i<N;i++)
        for(int j=0;j<N-i-1;j++)
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
}
 int main()
 {
     int N;
     printf("Enter the size of array - ");
     scanf("%d",&N);
     int a[N];
     printf("Enter an array of numbers of Size %d\n",N);
		getarray(a,N);
  
     printf("\nBefore Calling Sort : ");
		putarray(a,N);


     bubble_sort(a,N);
     printf("\n\nAfter Sorting  : ");

     for(int i=0;i<N;i++)
     printf("%3d",a[i]);

     printf("\n");
     return 0;
 }
