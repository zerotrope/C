// Preprocesseurs système
#include <stdio.h>
#include <stdlib.h>

// Preprocesseurs code
#include "7.3_headers.h"
#include "7.3_functions.c"

// Main
int main()
{
    node *arbre;
    arbre = NULL;
    int choix = 0;

    while(choix != 9)
    {
        printf("Que faire : \n");
        printf("1- insérer node\n");
        printf("2- afficher arbre trie\n");
        printf("9- sortir\n");
        scanf("%i", &choix);
        if(choix == 1)
        {
            insertion(&arbre);
        }
        else if (choix == 2)
        {
            afficherNodeRecursive(arbre);
            printf("\n");
        }
    }
    return 0;
}

/*
Exercice :
 - insertion récursive
 - affichage itératif
 - labyrinthe en arbre (2 décisions d'abord puis 4)

Next : C++

Plus tard :
 - Socket
 - Threads
 */