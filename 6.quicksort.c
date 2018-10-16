// PREPROCESS
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
                                      
// Quicksort algorithm
void quicksort(int t[], int start, int end)
{
	printf("Before quicksort : ");
	show(t, end);

	int left = start - 1;
	int right = end + 1;

	const int pivot = t[start];
	int count = 0;

	while (1)
	{
		do right--; while (t[right] > pivot);
		do left++; while (t[left] < pivot);

		if (left < right)
			swap(&t[left], &t[right]);
		else break;
	}
	quicksort(t, start, right);
	quicksort(t, right + 1, end);

	printf("After quicksort : ");
	affiche(t, end);
	printf("(In %i iterations)\n\n", count);
}

// MAIN
int main()
{
	int q[15] = {5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8};
	int dq = sizeof(q) / sizeof(q[0]) - 1;
	int dt = 0;

	printf("q = ");
	show(q, dq);

	quicksort(q, dt, dq);

	printf("q = ");
	show(q, dq);

	printf("\n\n");
	return 0;
}
