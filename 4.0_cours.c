#include "0_headers.h"
#include "0_functions.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    // Exercice : rand matrice 10X10 lignes rangées par intervalle [0;9] ; [10;19] ; [20;29] ; [30;39] ...etc.
        // Version All in :
    int **m;
    m = malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++)
    {
        m[i] = malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++)
        {
            m[i][j] = (rand()%10) + (10 * i);
        }
    }
    afficheMatrice(m, 10, 10);
    free(m);

        // Version step-by-step par swaps inter-dimensionnels : quid n > 10 rand()%100 ?


    // Exercice de récursivité sur Matrice 5x5 rand()%100
        // Création de la matrice aléatoire
    int **m3;
    m3 = malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++)
    {
        m3[i] = malloc(sizeof(int) * 5);
        for (int j = 0; j < 5; j++)
        {
            m3[i][j] = rand()%100;
        }
    }
    afficheMatrice(m3, 5, 5);

        // Appel de la fonction de récursivité
    printf("%i\n", recursive(0, m3, 0, 0, 5, 5));
    free(m3);

    return 0;
}

/*
WRAP UP :
 - Exos matrice
 - Début récursivité avec exo des sommes
 - Exercice résolution labyrinthe

FORWARD :
 - Finir récursivité
 - Go Structures
 - Go Listes chaînées
*/
