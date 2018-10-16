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

// Selection sort algorithm
void selection(int t[], int size) // tri par sélection
{
	printf("Before selection sorting : ");
	show(t, size);

	int count = 1;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (t[i] > t[j])
			{
				swap(&t[i], &t[j]);
			} count++;
		}
	}
	printf("After selection sorting : ");
	show(t, size);
	printf("(In %i iterations)\n\n", count);
}

// MAIN
int main()
{
	int t[15] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5 };
	int dt = sizeof(t) / sizeof(t[0]);
	printf("t = ");
	show(t, dt);
	selection(t, dt);
	printf("t = ");
	show(t, dt);
	printf("\n\n");

	return 0;
}
