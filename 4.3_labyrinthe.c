#include "0_headers.h"
#include "0_functions.h"
#include <time.h>

int main()
{
    srand(time(NULL));

/*
    EXERCICE : Résolution d'un labyrinthe d'entiers.
    Matrice 10x10 rand() O (sol) ou 9 (mur/vide)
       Départ = valeur d'une case = 1
       Arrivée = valeur d'une case = 2
       Multidirections = haut, bas, gauche, droite
    -> affiche chemin remplaçant les 0 empruntés par des 5
    Cas sans solution?
*/
    // Création de la matrice aléatoire
    int **m;
    int count = 0;
    m = malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++)
    {
        m[i] = malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++)
        {
             m[i][j] = 9;
            if (rand()%100 > 10)
                m[i][j] = 0;
        }
    }

    /*int count = 0;
    int m[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,9,9,9,9,9,9,9,9,0},
    {0,0,0,0,0,0,0,0,9,0},
    {0,0,9,9,9,9,9,0,9,0},
    {0,9,0,0,0,0,0,0,9,0},
    {0,9,9,9,9,9,9,9,9,9},
    {0,9,0,0,0,0,0,0,0,0},
    {0,9,0,9,0,0,0,0,0,0},
    {0,0,0,9,0,0,0,0,0,0}};*/

    // Initialisation Entrée aléatoire
    int er = rand()%10;
    int ec = rand()%10;
    m[er][ec] = 1;

    // Initialisation Sortie aléatoire
    m[rand()%10][rand()%10] = 2;
    afficheMatrice(m, 10, 10);

    // Appel de la fonction dans une variable
    int result = labyrinthe4d(m, 3, 2, 10, 10, &count);

    // Analyse du retour de la fonction
    if (result == SORTIE)
        printf("Sortie atteinte en %i mouvements, voir ci-dessous :\n\n", count);
    else if (result == NO_SORTIE)
        printf("Aucun chemin possible!\n\n");
    else if (result == MUR)
        printf("Un mur sur la route!\n\n");
    else
        printf("Cas impossible\n\n");

    afficheMatrice(m, 10, 10);
    //free(m);

    return 0;
}