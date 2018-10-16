// Preprocess
#include "0_headers.h"
#include <time.h>

// Functions
void incr(int *a)
{
	*a = (*a)++;
}

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void affiche(int t[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", t[i]);
	}
	printf("\n");
}

int success(int t[], int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		if (t[i] > t[i + 1])
			return 0;
	} return 1;
}

void stupide(int t[], int size)
{
	printf("Avant stupide : ");
	affiche(t, size);

	int count = 1;
	srand(time(NULL)); // initialisation du Rand récupère le temps i -> variable

	while (success(t, size) == 0)					// Comparaison!
	{
		for (int i = 0; i < (size - 1); i++)
		{
			swap(&t[i],&t[rand()%15]);				// swap hasard total
			count++;
		}
	}
	printf("Apres stupide : ");
	affiche(t, size);
	printf("(En %i iterations)\n\n", count);
}

void bulles(int t[], int size)	// Tri à bulles
{
	printf("Avant bulles : ");
	affiche(t, size);

	int count2 = 0;
	int count = 1;

	while (count > 0)
	{
		count = 0;
		for (int i = 0; i < (size - 1); i++)
		{
			if (t[i] > t[i + 1])
			{
				swap(&t[i], &t[i + 1]);
				count++;
			}
			count2++;
		}
	}
	printf("Apres bulles : ");
	affiche(t, size);
	printf("(En %i iterations)\n\n", count2);
}

void selection(int t[], int size) // tri par sélection
{
	printf("Avant selection : ");
	affiche(t, size);

	int count = 1;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (t[i] > t[j])
			{
				swap(&t[i], &t[j]);
			} count++;
		}
	}
	printf("Apres selection : ");
	affiche(t, size);
	printf("(En %i iterations)\n\n", count);
}

void quicksort(int t[], int debut, int fin)			// Quicksort
{
	printf("Avant quicksort : ");
	affiche(t, fin);

	int gauche = debut - 1;							// Itérateur gauche
	int droite = fin + 1;							// Itérateur droit

	const int pivot = t[debut];						// Pivot
	int count = 0;									// Compteur

	// Essai 2
	while (1)
	{
		do droite--; while (t[droite] > pivot);
		do gauche++; while (t[gauche] < pivot);

		if (gauche < droite)
			swap(&t[gauche], &t[droite]);
		else break;
	}
	quicksort(t, debut, droite);
	quicksort(t, droite + 1, fin);

	// Essai 1
	/*while (i <= max)
	{
		if (t[i] < k)
			i++;
		if (t[max] > k)
			max--;
		if (t[i] >= k)
			swap(&t[i], &t[max]); i++; max--; count++;
	}*/
	printf("Apres quicksort : ");
	affiche(t, fin);
	printf("(En %i iterations)\n\n", count);
}


void drapeau(int t[], int size)
{
	printf("Avant drapeau : ");
	affiche(t, size);

	int i = 0;										// Itérateur gauche
	int j = 0;										// Pivot 1
	//int k = 6;										// Pivot 2
	//int max1 = 6;									// Itérateur droit
	//int max2 = size - 1;							// Itérateur final
	int max = size - 1;
	int count;										// Compteur
													// for (i = 0; i <= j; i++)
	do
	{
		count = 0;
		while (i <= max)
		{
			// Essai 4
			if (t[i] >= 3)
				i++;
			if (t[i] < 3)
				swap(&t[i], &t[j]); i++; j++; count++;
			if (t[i] >= 6)
				swap(&t[i], &t[max]); max--; count++;

			// Essai 3
			/*if (t[i] < j)
				i++;
			if (t[i] >= j)
				swap(&t[i], &t[k]); i++;  k--; count++;
			if (t[i] > k)
				swap(&t[i], &t[k]); swap(&t[i], &t[max2]); i++;  k--; max2--; count++;*/


			// Essai 2
			/*if (t[i] < j)
				i++;
			if (t[max1] >= j)
				max1--;
			if (t[max2] > k)
				max2--;
			if (t[i] >= j)
				swap(&t[i], &t[max1]); i++; max1--; count++;
			if (t[i] >= k)
				swap(&t[i], &t[max1]); swap(&t[i], &t[max2]); i++; max1--; max2--; count++;*/


			// Essai 1
			/*while (i <= j)						// Tant que (i <= j) Faire
			{										// En fonction de la valeur de T[i]
				if (t[i] < 3)						// Cas au début : tous les éléments dont la valeur est < 3 sont au début du tableau
				{
					i = i + 1;
				}
				if (t[i] > 3)						// Cas du milieu : tous les éléments dont 3 < valeur < 6 sont au milieu
				{
					// Echange t[i] et t[j]
					swap(&t[i], &t[j]);
					j = j - 1;
				}
				if (t[i] > 6)						// Cas de la fin :  tous les éléments dont la valeur > 6 sont à la fin
				{
					// Echange t[i] et t[k]
					swap(&t[i], &t[k]);
					// Echange t[i] et t[j]
					swap(&t[i], &t[j]);
					j = j - 1;
					k= k - 1;
				}


				}

			} while (count != 0);*/
		}
	} while (count != 0);
	printf("Apres drapeau : ");
	affiche(t, size);
	printf("(En %i iterations)\n\n", count);
}

void affichePointeur(int *t, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%i ", *(t+i));
	}
	printf("\n\n");
}

void afficheChar(char *c, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c ", *(c+i));
	}
	printf("\n\n");
}

void swapChar(char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

void alphabet(char c[], int size)	// Tri à bulles sur char = alphabétique
{
	printf("Avant alphabet : ");
	afficheChar(c, size);

	int count = 1;
	int count2 = 0;

	while (count > 0)
	{
		count = 0;
		for (int i = 0; i < (size - 1); i++)
		{
			if (c[i] > c[i+1])
			{
				swapChar(&c[i], &c[i+1]);
				count++;
			}
			count2++;
		}
	}
	printf("Apres alphabet : ");
	afficheChar(c, size);
	printf("(En %i iterations)\n\n", count2);
}

void afficheMatrice(int **t, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for(int j = 0; j < size2; j++)
		{
			printf("%3i ", t[i][j]);		// %3d : Attention debug! Peut tronquer la valeur!
		}
	printf("\n");
	}
	printf("\n");
}

void afficheMatriceChar(char **t, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for(int j = 0; j < size2; j++)
		{
			printf("%3c ", t[i][j]);
		}
	printf("\n");
	}
	printf("\n");
}

// Chemin le plus court
int recursive(int result, int **m, int i, int j, int r, int c)
{
    result = result + m[i][j];
    if (i == (r - 1) && j == (c - 1))
    {
        return result;
    }
    if (i == (r - 1))												// Si j'arrive à la dernière ligne...
    {
        return recursive(result, m, i, j + 1, r, c);				// ...je call la fonction sur la case de droite
    }
    if (j == (c - 1))												// Si j'arrive à la dernière colonne...
    {
        return recursive(result, m, i + 1, j, r, c);				// ...je call la fonction sur la case inférieure
    }
    int droite = recursive(result, m, i, j + 1, r, c);				// Droite est un appel de la fonction sur la case de droite
    int bas = recursive(result, m, i + 1, j, r, c);					// Bas est un appel de la fonction sur la case inférieure
    if(droite < bas)												// Si droite plus intéressant que bas...
    {
        return droite;												// ...je prends à droite...
    }
    return bas;														// ...sinon je prends en bas
}

int labyrinthe2d(int **m, int i, int j, int r, int c, int *count)
{
    if (i < 0 || j < 0 || i == r || j == c							// Si je suis hors du labyrinthe...
     || m[i][j] != 0)												// ...ou que je me prends un mur...
    {
		return 0;													// ...Game over.
	}
    if ((i == (r - 1) && j == (c - 1))								// Si j'accède à la sortie...
      || labyrinthe2d(m, i + 1, j, r, c, count) == 1				// ...ou qu'elle se trouve vers le bas...
      || labyrinthe2d(m, i, j + 1, r, c, count) == 1)				// ...ou vers la droite...
     {
	    m[i][j] = 2;												// ...je marque mon passage...
		*count = *count + 1;										// ...tiens le compte...
		return 1;													// ...et Game on !
     }
	return -1;														// Si rien de tout ça, alors c'est sans espoir.
}

/* 1er essai non corrigé
int labyrinthe4d(int **m, int i, int j, int r, int c, int *count)
{
    if (i < 0 || j < 0 || i == r || j == c							// Si je suis hors du labyrinthe...
     || m[i][j] != 0)												// ...ou que je me prends un mur...
    {
		return 0;													// ...Game over.
	}
    if ((i == (r - 1) && j == (c - 1))								// Si j'accède à la sortie...
      || labyrinthe4d(m, i - 1, j, r, c, count) == 1				// ...ou qu'elle se trouve vers le haut...
      || labyrinthe4d(m, i + 1, j, r, c, count) == 1				// ...ou vers le bas...
      || labyrinthe4d(m, i, j - 1, r, c, count) == 1				// ...ou vers la gauche...
      || labyrinthe4d(m, i, j + 1, r, c, count) == 1)				// ...ou vers la droite...
    {
		m[i][j] = 5;												// ...je marque mon passage...
		*count = *count + 1;										// ...tiens le compte...
		return 1;													// ...et Game on !
    }
	return -1;														// Si rien de tout ça, alors c'est sans espoir.
}*/

/* 2eme essai non corrigé
int labyrinthe4d(int **m, int i, int j, int r, int c, int *count)
{
    if (i < 0 || j < 0 || i == r || j == c							// Si je suis hors du labyrinthe...
     || m[i][j] == 9												// ...ou que je me prends un mur...
     || m[i][j] == 5)												// ...ou que je suis déjà passé par là...
    {
		return 0;													// ...j'y vais pas.
	}
    if ((i == (r - 1) && j == (c - 1))								// Si j'accède à la sortie...
    ||  labyrinthe4d(m, i + 1, j, r, c, count) == 1					// ...ou que c'est libre vers le bas...
    ||  labyrinthe4d(m, i, j + 1, r, c, count) == 1					// ...ou encore libre vers la droite...
    || (i >= 1 && labyrinthe4d(m, i - 1, j, r, c, count) == 1)		// ...ou si je ne suis pas sur la 1ère ligne ET que c'est libre au-dessus...
    || (j >= 1 && labyrinthe4d(m, i, j - 1, r, c, count) == 1))		// ...ou si je ne suis pas sur la 1ère colonne ET que c'est libre en-dessous...
    {
	    m[i][j] = 5;												// ...je marque mon passage...
		*count = *count + 1;										// ...je tiens le compte...
		return 1;													// ...et go!
	}
	return -1;														// Si rien de tout ça, alors c'est sans espoir.
}*/

// Correction
int labyrinthe4d(int **m, int i, int j, int r, int c, int *count)
{
	printf("i = %i & j = %i\n", i, j);
	if (i == 9 && j == 9)
	{
		return SORTIE;
	}
	if (i < 0 || j < 0 || i > 9 || j > 9 || m[i][j] == 9)
	{
		return MUR;
	}
	if(m[i][j] == 5)
	{
		return DEJA_VU;
	}
	m[i][j] = 5;
	if (labyrinthe4d(m, i + 1, j, r, c, count) == SORTIE)
	{
		m[i][j] = 5;
		return SORTIE;
	}
	if (labyrinthe4d(m, i, j + 1, r, c, count) == SORTIE)
	{
		m[i][j] = 5;
		return SORTIE;
	}
	if (labyrinthe4d(m, i, j - 1, r, c, count) == SORTIE)
	{
		m[i][j] = 5;
		return SORTIE;
	}
	if (labyrinthe4d(m, i - 1, j, r, c, count) == SORTIE)
	{
		m[i][j] = 5;
		return SORTIE;
	}
	return NO_SORTIE;
}

// 1er essai après correction
int laby(int **m, int i, int j, int er, int ec, int sr, int sc, int *count)
{
	printf("i = %i & j = %i\n", i, j);
	if (i < 0 || j < 0 || i > 9 || j > 9 || m[i][j] == 9)
		return MUR;
	if(m[i][j] == 5)
		return DEJA_VU;
	if ((i == 9 && j == 9)
	  || laby(m, i + 1, j, er, ec, sr, sc, count) == SORTIE
	  || laby(m, i, j + 1, er, ec, sr, sc, count) == SORTIE
	  || laby(m, i, j - 1, er, ec, sr, sc, count) == SORTIE
	  || laby(m, i - 1, j, er, ec, sr, sc, count) == SORTIE)
	{
		m[i][j] = 5;
		*count = *count + 1;
		return SORTIE;
	}
	m[i][j] = 5;
	return NO_SORTIE;
}

// 1er essai en char après correction
int maze(char **m, int i, int j, int er, int ec, int sr, int sc, int *count)
{
	printf("i = %i & j = %i\n", i, j);
	if (i == sr && j == sc)
	{
		return SORTIE;
	}
	if (i < 0 || j < 0 || i > 9 || j > 9 || m[i][j] == '#')
	{
		return MUR;
	}
	if(m[i][j] == 'x')
	{
		return DEJA_VU;
	}
	m[i][j] = 'x';
	if (maze(m, i + 1, j, er, ec, sr, sc, count) == SORTIE)
	{
		m[i][j] = 'x';
		return SORTIE;
	}
	if (maze(m, i, j + 1, er, ec, sr, sc, count) == SORTIE)
	{
		m[i][j] = 'x';
		return SORTIE;
	}
	if (maze(m, i, j - 1, er, ec, sr, sc, count) == SORTIE)
	{
		m[i][j] = 'x';
		return SORTIE;
	}
	if (maze(m, i - 1, j, er, ec, sr, sc, count) == SORTIE)
	{
		m[i][j] = 'x';
		return SORTIE;
	}
	return NO_SORTIE;
}