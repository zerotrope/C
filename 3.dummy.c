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

// Boolean value check function
int success(int t[], int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		if (t[i] > t[i + 1])
			return 0;
	} return 1;
}

// Dummy sort function
void stupide(int t[], int size)
{
	printf("Before dummy sorting : ");
	show(t, size);

	int count = 1;
	srand(time(NULL)); // initializes random function

	while (success(t, size) == 0) // This is a comparison not an affectation
	{
		for (int i = 0; i < (size - 1); i++)
		{
			swap(&t[i],&t[rand()%15]); // fully random swapping
			count++;
		}
	}
	printf("After dummy sorting : ");
	affiche(t, size);
	printf("(In %i iterations)\n\n", count);
}

// MAIN
int main()
{
	int s[15] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5 };
	int ds = sizeof(s) / sizeof(s[0]);
	printf("s = ");
	show(s, ds);
	dummy(s, ds);
	printf("s = ");
	show(s, ds);

	printf("\n\n");
	return 0;
}
