#include "0_headers.h"
#include "0_functions.h"

// Swap deux valeurs
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