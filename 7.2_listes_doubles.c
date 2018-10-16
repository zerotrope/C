// Preprocesseurs système
#include <stdio.h>
#include <stdlib.h>

// Preprocesseurs code
#include "7.2_headers.h"
#include "7.2_functions.c"

// Main
int main()
{
    int choix = 0;
    personnage *Head;
    personnage *Tail;
    Head = NULL;
    Tail = NULL;

    while(choix != 9)
    {
        printf("Que faire : \n1- créer personnage (FIFO)\n2- supprimer personnage (FIFO)\n3- afficher liste\n4- ajouter personnage (FILO)\n5- supprimer personnage (FILO)\n9- sortir\n");
        scanf("%i", &choix);
        if(choix == 1)
        {
            creerFIFO(&Head, &Tail);
        }
        else if (choix == 2)
        {
            supprimerFIFO(&Head, &Tail);
        }
        else if (choix == 3)
        {
            afficherListe(Head);
            afficherListeReverse(Tail);
        }
        else if (choix == 4)
        {
            creerFILO(&Head, &Tail);
        }
        else if (choix == 5)
        {
            supprimerFILO(&Head, &Tail);
        }
    }
    return 0;
}

/*
Exercice :
 - creer personnage début de liste : OK
 - supprimer personnage en fin de liste : contraint aux **pointeurs pour s'affranchir d'une erreur de suppression sur afficherListeReverse uniquement
 - arbre de tri
 */