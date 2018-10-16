#include "0_headers.h"
#include "0_functions.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    // Exercice : rand matrice 10X10 lignes rangées par intervalle [0;9] ; [10;19] ; [20;29] ; [30;39] ...etc.
        // Version All-in :
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
    int **m2;
    m2 = malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++)
    {
        m2[i] = malloc(sizeof(int) * 10);
        /*if (m2[i] > m2[i + 1])
            swap(&m2[i], &m2[i + 1]);*/
        for (int j = 0; j < 10; j++)
        {
            m2[i][j] = rand()%100;
            if (m2[j] > m2[j + 1])
                swap(&m2[j], &m2[j + 1]);
        }
        bulles(m2[i],10);
    }
    afficheMatrice(m2, 10, 10);
    free(m2);

    return 0;
}