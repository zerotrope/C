#include "0_headers.h"
#include "0_functions.h"

// Passage de paramètres par adresse
int main()
{
	int x = 5;

	incr(&x);
	printf("x = %d\n", x);

	printf("\n\n");
	return 0;
}