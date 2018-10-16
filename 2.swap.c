// Preprocess
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Swap function through pointers
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

// Main
int main()
{
    int a = 1;
	int b = 2;
	printf("Initiales : \n a = %i\tb = %i\n", a, b);

	swap(&a, &b);
	printf("Swappées : \n a = %i\tb = %i\n", a, b);

	swap(&a, &b);
	printf("Retour : \n a = %i\tb = %i\n", a, b);

	printf("\n\n");
	return 0;
}
