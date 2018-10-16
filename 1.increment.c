// Preprocess
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Incrementing function through pointer
void incr(int *a)
{
	*a = (*a)++;
}

// Main
int main()
{
	int x = 5;

	incr(&x);
	printf("x = %d\n", x);

	printf("\n\n");
	return 0;
}
