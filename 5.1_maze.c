#include "0_headers.h"
#include "0_functions.h"
#include <time.h>

int main()
{
    srand(time(NULL));

/*
    EXERCICE : Résolution d'un labyrinthe de caractères (par table ascii).
    Matrice 10x10 rand() '.' (sol) ou '#' (mur/vide)
       Départ = valeur d'une case = 'E'
       Arrivée = valeur d'une case = 'S'
       Multidirections = haut, bas, gauche, droite
    -> affiche chemin remplaçant les 0 empruntés par des 'x'
    Cas sans solution?
*/
    // Création de la matrice aléatoire
    char **m;
    int count;
    m = malloc(sizeof(char*) * 10);
    for (int i = 0; i < 10; i++)
    {
        m[i] = malloc(sizeof(char) * 10);
        for (int j = 0; j < 10; j++)
        {
            //m[i][j] = rand()%2 + '0';             // P(m[i][j] = '.') = 50%
            m[i][j] = '#';                          // Etat de départ = '1' SAUF SI
            if (rand()%10 > 2)                      // P(m[i][j] = '.') = 70%
                m[i][j] = '.';
        }
    }

    // Initialisation Entrée aléatoire stockée en variables er et ec, param d'entrée de la fonction récursive
    int er = rand()%10;
    int ec = rand()%10;
    m[er][ec] = 'E';

    // Initialisation Sortie aléatoire stockée en variables sr et sc, param d'entrée de la fonction récursive
    int sr = rand()%10;
    int sc = rand()%10;
    m[sr][sc] = 'S';
    afficheMatriceChar(m, 10, 10);

    // Appel de la fonction
    maze(m, er, ec, sr, sc, 10, 10, &count);
    afficheMatriceChar(m, 10, 10);
    free(m);

    // Appel de la fonction dans une variable
    int result = maze(m, er, ec, sr, sc, 10, 10, &count);

    // Analyse du retour de la fonction
    if (result == SORTIE)
        printf("Sortie atteinte en %i mouvements, voir ci-dessous :\n\n", count);
    else if (result == NO_SORTIE)
        printf("Aucun chemin possible!\n\n");
    else if (result == MUR)
        printf("Un mur sur la route!\n\n");
    else if (result == DEJA_VU)
        printf("On tourne en rond:\n\n");
    else
        printf("Cas impossible\n\n");

    return 0;
}