// Preprocesseurs système
#include <stdio.h>
#include <stdlib.h>

// Preprocesseurs code
#include "7.0_headers.h"
#include "7.0_functions.c"

// Main
int main()
{
    int choix = 0;
    personnage *Head;
    Head = NULL;

    while(choix != 9)
    {
        printf("Que faire : \n1- créer personnage (FIFO)\n2- supprimer personnage (FIFO)\n3- afficher liste\n4- ajouter personnage (FILO)\n5- supprimer personnage (FILO)\n6- supprimer les pioupious\n9- sortir\n");
        scanf("%i", &choix);
        if(choix == 1)
        {
            creerFIFO(&Head);
        }
        else if (choix == 2)
        {
            supprimerFIFO(Head);
        }
        else if (choix == 3)
        {
            afficherListe(Head);
        }
        else if (choix == 4)
        {
            creerFILO(&Head);
        }
        else if (choix == 5)
        {
            supprimerFILO(&Head);
        }
        else if (choix == 6)
        {
            pegi18(&Head);
        }
    }
    return 0;
}

/*
Exercice :
Inclure Precedent dans les fonctions.
*/