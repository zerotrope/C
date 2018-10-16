#include "0_headers.h"
#include "0_functions.h"

// Algorithme du drapeau hollandais
int main()
{
	int h[15] = { 5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8 };
	int dh = sizeof(h) / sizeof(h[0]);

	printf("h = ");
	affiche(h, dh);

	drapeau(h, dh);

	printf("h = ");
	affiche(h, dh);

	printf("\n\n");
	return 0;
}
