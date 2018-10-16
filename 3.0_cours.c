#include "0_headers.h"
#include "0_functions.h"
#include <time.h>

int main()
{
    // Observer la correspondance d'un char en table ASCII
    char c = 'D';
    printf("Position ASCII de 'D' = %i\n\n",c);

    srand(time(NULL));                                          // initialisation du rand

    // Reprise des déclarations malloc
    // classique
    int *p;
    p = malloc(sizeof(int) * 15);
    for (int i = 0; i < 15; i++)                                // boucle du tableau
    {
        p[i] = rand()%100;
    }
    printf("Methode classique (deternimiste) :\n");
    bulles(p, 15);
    free(p);

    // Méthode 0
    /*int *p0;
    p0 = malloc(sizeof(p0));
    for (int i = 0; i < 15; i++)
    {
        p0[i] = rand()%100;
    }
    p0 = realloc(p0, 15 * sizeof(int));
    printf("Methode 0 :\n");
    bulles(p0, 15);
    free(p0);*/

    // Méthode 1
    int *p1;
    p1 = malloc(sizeof(p1));
    for (int i = 0; i < 15; i++)
    {
        p1[i] = rand()%100;
        p1 = realloc(p1, (i+2) * sizeof(int));
    }
    printf("Methode 1 :\n");
    bulles(p1, 15);
    free(p1);

    // Méthode 2
    /*int *p2;
    p2 = malloc(sizeof(int) * 1);
    for (int i = 0; i < 15; i++)
    {
        p2[i] = rand()%100;
        p2 = realloc(p2, sizeof(p2) + 1 * sizeof(int));
    }
    printf("Methode 2 :\n");
    bulles(p2, 15);
    free(p2);*/

    // Exercice 1 : remplir une matrice 5x10 (50 nombres aléatoires) puis trier chaque ligne
    int **m1;
    m1 = malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++)
    {
        m1[i] = malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++)
        {
            m1[i][j] = rand()%10;
        }
        bulles(m1[i], 10);
    }
    afficheMatrice(m1, 5, 10);

    // Boucle realloc si lignes supplémentaires
    m1 = realloc(m1, sizeof(int*) * 8);
    for (int i = 5; i < 8; i++)
    {
        m1[i] = malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++)
        {
            m1[i][j] = rand()%10;
        }
        //bulles(m1[i], 10);
    }
    afficheMatrice(m1, 8, 10);
    free(m1);

    // Exercice 2 : remplir une matrice 10X10 aux lignes rangées par dizaines croissantes [0;9] ; [10;19] ; [20;29] ; [30;39] ...etc.
    // Swap entre dimensions
    // Quid d'un rand()%100 : trop de nombres pour ligne i ?!
    int **m2;
    m2 = malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++)
    {
        m2[i] = malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++)
        {
            /*if (i == 0)
            {
                m2[i][j] = rand()%(9 + 1 - 0) + 0;
            }
            else
            {
                m2[i][j] = rand()%((10*i+(10*i)-1) + 1 - (10*i)) + (10*i);
            }*/
            m2[i][j] = (rand()%10) + (10 * i); // APPRENDS
        }
    }
    afficheMatrice(m2, 10, 10);
    free(m2);

    int **m3;
    m3 = malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4; i++)
    {
        m3[i] = malloc(sizeof(int) * 4);
        for (int j = 0; j < 4; j++)
        {
            m3[i][j] = rand()%20;
        }
    }
    afficheMatrice(m3, 4, 4);
    printf("%i\n", recursive(0, m3, 0, 0, 4, 4));

    free(m3);

    return 0;
}
