#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define BUBBLE 1000
int main()
{
	int myArray[BUBBLE];
	int i, j;
	int temp = 0;
	int num;
    double tim1;
    
    
	//fill array
	for (i = 0; i < BUBBLE; i ++)
	{    
		   num = i;
		   myArray[i] = num;
	}
	
	clock_t start, end;
  
        // Bubble sort
        start = clock();
       
	//sort array
	for(i = 0; i < BUBBLE; i++)
	{

		for (j = 0; j < BUBBLE-1; j++)
        {
            if (myArray[j] > myArray[j+1])
			{
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
			}
        }
	}
	end = clock();
	tim1 = ((double)(end - start));
	printf("%li \n",(long int)tim1);
   
	
	//print array
	for (i = 0; i < BUBBLE; i++)
	{
		printf("%d\n",myArray[i]);
	}

	
	system("PAUSE");	
	return 0;
}