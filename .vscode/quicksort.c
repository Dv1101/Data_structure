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

/* Driver code */
int main()
{
    long int n = 10000;
    int it = 0;
    double tim1[10];

    while (it++ < 10) {
        long int arr[n];

        // generating n random numbers
        // storing them in arrays a, b, c
        for (int i = 0; i < n; i++) 
        {
            long int no = rand() % n + 1;
            arr[i] = no;
        }
    
    clock_t start, end;

    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    start = clock();
    quicksort(arr,0,arr_size-1);
    end = clock();
    tim1[it] = ((double)(end - start));

    // type conversion to long int
    // for plotting graph with integer values
    printf("%li %li \n", n,(long int)tim1[it]);
            
            //For Saving in file. #Dhruv
            FILE *fp=NULL;
            fp=fopen("quickcomplexity.dat","a+");
            fprintf(fp,"%li\t %li\t\n",n,(long int)tim1[it]);
    // increases the size of array by 10000
        n += 10000;
    }
    system("gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'D:/SEM 5 programming/DAA Lab/.vscode/quickcomplexity.dat' using 1:2 w lp lc rgb 'green' lw 2 pt 7 title 'Quicksort'\"");
    return 0;
}