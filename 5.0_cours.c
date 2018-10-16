#include "0_headers.h"
#include "0_functions.h"
#include <time.h>

int main()
{
    //srand(time(NULL));

/*
    EXERCICE : Résolution d'un labyrinthe de caractères (par table ascii).
    Matrice 10x10 rand() 'O' (sol) ou '1' (mur/vide)
       Départ = valeur d'une case = 'e'
       Arrivée = valeur d'une case = 's'
       Multidirections = haut, bas, gauche, droite
    -> affiche chemin remplaçant les 0 empruntés par des 'x'
    Cas sans solution?
*/
    // Création de la matrice aléatoire
    char **m;
    m = malloc(sizeof(char*) * 10);
    for (int i = 0; i < 10; i++)
    {
        m[i] = malloc(sizeof(char) * 10);
        for (int j = 0; j < 10; j++)
        {
            //m[i][j] = rand()%2 + '0';             // P(m[i][j] = '0') = 50%
            m[i][j] = '1';                          // Etat de départ = '1' SAUF SI
            if (rand()%10 > 3)                      // P(m[i][j] = '0') = 60%
            {
                m[i][j] = '0';
            }
        }
    }

    // Initialisation Entrée aléatoire stockée en variables er et ec, param d'entrée de la fonction récursive
    int er = rand()%10;
    int ec = rand()%10;
    m[er][ec] = 'e';

    // Initialisation Sortie aléatoire
    m[rand()%10][rand()%10] = 's';
    afficheMatriceChar(m, 10, 10);

    // Appel de la fonction
    //maze(0, m, er, ec, 10, 10);
    //afficheMatriceChar(m, 10, 10);
    free(m);

    return 0;
}