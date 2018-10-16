// Preprocess                         
#include <stdio.h>                    
#include <stdlib.h>                   
#include <string.h>                   
#include <time.h>                     
                                      
// FUNCTIONS
// Swap function
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
                          
// Printing function                  
void show(int t[], int size)          
{                                     
        for (int i = 0; i < size; i++)
        {                             
                printf("%d ", t[i]);  
        }                             
        printf("\n");                 
}                                     

// Bubble sort function
void bubble(int t[], int size)	// Tri à bulles
{
	printf("Before bubble sort : ");
	show(t, size);

	int count2 = 0;
	int count = 1;

	while (count > 0)
	{
		count = 0;
		for (int i = 0; i < (size - 1); i++)
		{
			if (t[i] > t[i + 1])
			{
				swap(&t[i], &t[i + 1]);
				count++;
			}
			count2++;
		}
	}
	printf("After bubble sort : ");
	show(t, size);
	printf("(In %i iterations)\n\n", count2);
}

int main()
{
    	int b[15] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5 };
	int db = sizeof(b) / sizeof(b[0]);
	printf("t = ");
	show(b, db);
	bubble(b, db);
	printf("t = ");
	show(b, db);

	return 0;
}
