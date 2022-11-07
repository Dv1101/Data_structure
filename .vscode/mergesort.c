/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
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
        }       p    
    
    clock_t start, end;

    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    start = clock();
    mergeSort(arr, 0, arr_size - 1);
    end = clock();
    tim1[it] = ((double)(end - start));

    // type conversion to long int
    // for plotting graph with integer values
    printf("%li %li \n", n,(long int)tim1[it]);
            
            //For Saving in file. #Dhruv
            FILE *fp=NULL;
            fp=fopen("mergecomplexity.dat","a+");
            fprintf(fp,"%li\t %li\t\n",n,(long int)tim1[it]);
    // increases the size of array by 10000
        n += 10000;
    }
    system("gnuplot -p -e \"set ylabel 'mileseconds' ; set xlabel 'data set' ; p 'D:/SEM 5 programming/DAA Lab/.vscode/mergecomplexity.dat' using 1:2 w lp lc rgb 'red' lw 2 pt 7 title 'merge'\"");
    return 0;
}