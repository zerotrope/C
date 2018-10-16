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

// Dutch flag algorithm
flag(int t[], int size)
{
	printf("Before flag sorting : ");
	show(t, size);

	int i = 0;
	int j = 0;
	int max = size - 1;
	int count;

	do
	{
		count = 0;
		while (i <= max)
		{
			if (t[i] >= 3)
				i++;
			if (t[i] < 3)
				swap(&t[i], &t[j]); i++; j++; count++;
			if (t[i] >= 6)
				swap(&t[i], &t[max]); max--; count++;
		}
	} while (count != 0);
	printf("After flag sorting : ");
	show(t, size);
	printf("(In %i iterations)\n\n", count);
}

// MAIN
int main()
{
	int h[15] = { 5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8 };
	int dh = sizeof(h) / sizeof(h[0]);

	printf("h = ");
	show(h, dh);

	flag(h, dh);

	printf("h = ");
	show(h, dh);

	printf("\n\n");
	return 0;
}
