#include "0_headers.h"					// contient stdlib.h *Attention au nesting de .h qui call des include superflus?*
#include "0_functions.h"
#include <time.h>						// pour la fonction random

/* Malloc
Trois solutions pour se défaire du nb fixe d'éléments dans un malloc :
	0/ t = malloc(sizeof(t));								t mesure sa propre taille
	   t = realloc(t, n * sizeof(int));						qui est réallouée à la fin de l'input : dangereux et requiert la propriété du code

	1/ t = malloc(sizeof(t));								t mesure sa propre taille
	   t[i] = realloc(t, j * sizeof(int));					qui est réalloué par itération avec son propre indice j = i+2

	2/ t = malloc(sizeof(int) * 1);							t mesure 1 fois la taille d'un entier
	   t[i] = realloc(t, sizeof(t) + 1 * sizeof(int));		qui est réalloué par addition à sa propre taille évite une boucle sur j

	3/ liste chaînée -> plus élaboré, faire des recherches
*/

// Fonctions de tri sur pointeurs
int main()
{
    int *t;												// initialisation pointeur t d'entiers
	t = malloc(sizeof(int) * 15);						// allocation fixe
  //t = malloc(sizeof(t));								// allocation modulaire 1 - dangereuse & fastidieuse
  //t = malloc(sizeof(int) * 1);						// allocation modulaire 2 - sécure & fastidieuse
	if (t != NULL)										// test allocation
	{
		t[0] = 9;										// assignation à l'arrache -> comment boucler?
	  //t[0] = realloc(t, 2 * sizeof(int));				// réallocation modulaire 1 par j = i+2 soit ici = 2
	  //t[0] = realloc(t, sizeof(t) + 1 * sizeof(int)	// réallocation modulaire 2 par t = t+1
		t[1] = 8;
		t[2] = 7;
		t[3] = 6;
		t[4] = 5;
		t[5] = 4;
		t[6] = 3;
		t[7] = 2;
		t[8] = 1;
		t[9] = 0;
		t[10] = 1;
		t[11] = 2;
		t[12] = 3;
		t[13] = 4;
		t[14] = 5;
	  //t = realloc(t, 15 * sizeof(int));				// réallocation finale - dangereuse & réservée au propriétaire du code "je vois combien d'inputs n" ici n = 15

		printf("%i\n", *t);				// imprime la valeur de t[0]
		affichePointeur(t, 15);			// imprime toutes les valeurs en incrémentant le pointeur
		bulles(t, 15);					// surprise, ça marche donc : t[] = *(t+i)
		affichePointeur(t, 15);

		free(t);						// libération mem alloc à t -> comment vérifier que ça marche?
		affichePointeur(t, 15);			// free différent de flush : t est toujours là tant que non réalloué par system d'où la mémoire rémanante éventuelle
	}

	int *r;								// initialisation pointeur r
	r = malloc(sizeof(int) * 5);		// mem alloc
	srand(time(NULL));					// initialisation du Rand récupère le temps i -> variable
	if (r != NULL)						// test allocation
	{
		r[0] = rand()%100;				// assignation à l'arrache de d'un rand [0;100]
		r[1] = rand()%100;
		r[2] = rand()%100;
		r[3] = rand()%100;
		r[4] = rand()%100;

		for (int i = 0; i < 5; i++)		// boucle pour générer des rand [0;100]
		{
			r[i] = rand()%100;
		}

		affichePointeur(r, 5);			// impressions
		bulles(r, 5);
		affichePointeur(r, 5);

		free(r);						// libération mem alloc à r
	}

	char c[4] = {'c','b','a'};			// tableau de charactères
	printf("%s\n\n", c);				// affiche tableau de charactères
	afficheChar(c, 4);					// affiche avec fonction adaptée (même résultat puisque tableau)
	alphabet(c, 4);						// tri alphabétiquement (adaptation du tri à bulles)
	afficheChar(c, 4);					// ré affiche le tableau trié ou non

	char *s;
	s = malloc(sizeof(char) * 4);
	if (s != NULL)
	{
		s[0] = 'c';						// assignation à l'arrache -> comment boucler? tables ASCII?
		s[1] = 'b';
		s[2] = 'a';

	printf("%s\n\n", s);
	afficheChar(s, 4);
	alphabet(s, 4);
	afficheChar(s, 4);

	}

	return 0;
}