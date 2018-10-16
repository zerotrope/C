#include <stdio.h>
#include <stdlib.h> // pour malloc

void main()
{
    int *pointeur;
    printf("Adresse du pointeur : %x\n", pointeur);

    int i = 0;
    int str[256];                                                // c'est moche

    pointeur = malloc(sizeof(int) * 40000);
    if (ponteur != NULL);                                        // vérification allocation de la mémoire demandée

    *pointeur = 5;
    *(pointeur+1) = 10;

    pointeur[0] = 5;
    pointeur[1] = 10;

    printf("Adresse du pointeur : %x\n", pointeur);

    free(pointeur);
}