#include "0_headers.h"
#include "0_functions.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    // Exercice 1 : Matrice 5x5 rand()%100
    int **m;
    m = malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++)
    {
        m[i] = malloc(sizeof(int) * 5);
        for (int j = 0; j < 5; j++)
        {
            m[i][j] = rand()%100;
        }
    }
    afficheMatrice(m, 5, 5);

    // Appel de la fonction de récursivité
    printf("Chemin le plus court : %i\n\n", recursive(0, m, 0, 0, 5, 5));
    free(m);

/*
    EXERCICE : Résolution d'un labyrinthe d'entiers.
    Matrice 10x10 rand() O (sol) ou 1 (mur/vide)
       Départ = (0,0)
       Arrivée = (r,c)
       Multidirections = bas, droite
    -> affiche chemin remplaçant les 0 empruntés par des 2
    Cas sans solution?
*/
    // Création de la matrice aléatoire
    int **m2;
    int count = 0;
    m2 = malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++)
    {
        m2[i] = malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++)
        {
            m2[i][j] = 1;
            if (rand()%100 > 25)                          // P(m[i][j] = '0') = 75%
                m2[i][j] = 0;
            //m2[i][j] = rand()%2;                        // P(m[i][j] = '0') = 50%
        }
    }
    afficheMatrice(m2, 10, 10);

    // Appel de la fonction
    int result = labyrinthe2d(m2, 0, 0, 10, 10, &count);  // Stockée dans une variable
    if (result == 1)
        printf("Sortie atteinte en %i mouvements, voir ci-dessous :\n\n", count);
    else if (result == -1)
        printf("Aucun chemin possible!\n\n");
    else printf("Un mur sur la route!\n\n");

    afficheMatrice(m2, 10, 10);
    free(m2);

    return 0;
}