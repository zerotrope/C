#include "0_headers.h"
#include "0_functions.h"

// Algorithme de quicksort
int main()
{
	int q[15] = {5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8};
	int dq = sizeof(q) / sizeof(q[0]) - 1;
	int dt = 0;

	printf("q = ");
	affiche(q, dq);

	quicksort(q, dt, dq);

	printf("q = ");
	affiche(q, dq);

	printf("\n\n");
	return 0;
}
