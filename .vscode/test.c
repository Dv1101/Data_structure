#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[100], n, c; 
    printf("Enter number of elements\n"); 
    scanf("%d", &n);
    printf("Enter %d integers\n", n); 
    for (c = 0; c < n; c++) 
    {
        scanf("%d", &a[c]);
    }

    for ( c = 0; c < n; c++)
    {
        printf(", %d", a[c]);
    }
    return 0;
}