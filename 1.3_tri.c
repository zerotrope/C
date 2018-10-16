#include "0_headers.h"
#include "0_functions.h"

// Fonctions de tri
int main()
{
    int b[15] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5 };
	int db = sizeof(b) / sizeof(b[0]); // pas nécessaire
	printf("t = ");
	affiche(b, db);
	bulles(b, db);
	printf("t = ");
	affiche(b, db);

	int t[15] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5 };
	int dt = sizeof(t) / sizeof(t[0]); // pas nécessaire
	printf("t = ");
	affiche(t, dt);
	selection(t, dt);
	printf("t = ");
	affiche(t, dt);
	printf("\n\n");

	return 0;

	int s[15] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5 };
	int ds = sizeof(s) / sizeof(s[0]);
	printf("s = ");
	affiche(s, ds);
	stupide(s, ds);
	printf("s = ");
	affiche(s, ds);

	printf("\n\n");
	return 0;
}