#include <stdio.h>

int main()
{
    int val[]={20,30,66,40,60};
    int wt[]={10,20,30,40,60};
    int i, j, n, w = 100;
    float temp;

    int ln = sizeof(val)/sizeof(val[0]);

    // printf("%d", ln);

    float r[100];
    for ( i = 0; i < ln; i++)
    {
        //ratio r
        r[i] = val[i]/wt[i];
    }

      for( i = 0; i < ln; i++)
    {
        printf("%f,  ", r[i]);
    }

    for (i = 0; i < ln; ++i) 
        {
            for (j = i + 1; j < ln; ++j) 
            {
                if (r[i] < r[j]) 
                {
                    temp = r[i];
                    r[i] = r[j];
                    r[j] = temp;
                }
            }
        }  
    
    for( i = 0; i < ln; i++)
    {
        printf("%f,  ", r[i]);
    }
    
    return 0;
    

}