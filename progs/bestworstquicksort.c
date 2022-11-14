#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int arr[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last);

   }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
   int i,n;
   int it = 0;
   double tim1[10];

   printf("Enter no. of elements u want to sort : ");
   scanf("%d",&n);
    
   int arr[n];

   printf("Enter %d Element : ",n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
 
   printf("\nYour array is : ");
   for(int i=0;i<n;i++)
   {
      printf(", %d ",arr[i]);
   }

   int arr_size = sizeof(arr) / sizeof(arr[0]);
    
   quicksort(arr,0,arr_size-1);
   printf("\n\nSorted array is : \n");
   printArray(arr, arr_size);
    

}