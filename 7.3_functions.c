// Preprocesseurs système
#include <stdio.h>
#include <stdlib.h>

// Preprocesseurs code
#include "7.3_headers.h"

// Functions
node *creerNode()
{
    node *nouveau_node;
    nouveau_node = malloc(sizeof(node));

    // Valeur
    printf("Merci de rentrer la valeur :\n");
    if (scanf("%i", &nouveau_node->val) != 1)
    {
        printf("Pas d'information acquise\n");
        nouveau_node->val = 0;
    }

    nouveau_node->gauche = NULL;
    nouveau_node->droit = NULL;

    // Return
    return(nouveau_node);
}

void insertion(node **arbre)
{
    node *nouvelle_node = creerNode();
    if (*arbre == NULL)
    {
        *arbre = nouvelle_node;
        return;
    }
    node *pointeur = *arbre;
    while (pointeur != NULL)
    {
        if (nouvelle_node->val <= pointeur->val)
        {
            if (pointeur->gauche == NULL)
            {
                pointeur->gauche = nouvelle_node;
                printf("%i ajoute a gauche de %i\n", nouvelle_node->val, pointeur->val);
                return;
            }
            pointeur = pointeur->gauche;
        }
        else
        {
            if (pointeur->droit == NULL)
            {
                pointeur->droit = nouvelle_node;
                printf("%i ajoute a droite de %i\n", nouvelle_node->val, pointeur->val);
                return;
            }
            pointeur = pointeur->droit;
        }
    }
}

void afficherNodeRecursive(node *middle)
{
    if (middle == NULL)
        return;
    afficherNodeRecursive(middle->gauche);
    printf("%i -> ", middle->val);
    afficherNodeRecursive(middle->droit);
    return;
}

noeud *creerNoeud()
{
    noeud *nouveau_noeud;
    nouveau_noeud = malloc(sizeof(noeud));

    printf("Merci de rentrer la valeur :\n");
    if (scanf("%i", &nouveau_noeud->val) != 1)
    {
        printf("Pas d'information acquise\n");
        nouveau_noeud->val = 0;
    }

    nouveau_noeud->gauche = NULL;
    nouveau_noeud->droit = NULL;
    nouveau_noeud->haut = NULL;

    return(nouveau_noeud);
}

void insertionRecursive(noeud **middle)
{
    noeud *nouveau_noeud = creerNoeud();
    if(*middle == NULL)
       middle = nouveau_noeud;
    noeud *pointeur = *middle;
    if (middle->gauche->val <= pointeur->val)
        insertionRecursive(noeud **middle->gauche);
    insertionRecursive(noeud **middle->droite);
}

void afficherNoeudIterative(noeud **arbre)
{
    if (arbre == NULL)
        return;
    noeud *pointeur = *arbre;
    if (pointeur->gauche == NULL)
    {
        printf("%i -> ", pointeur);
        if (pointeur->droite == NULL)
        {
            if (pointeur->gauche == NULL)
            {
                printf("%i -> ", pointeur);
            }
            pointeur = pointeur->gauche;
            pointeur = pointeur->droite;
            printf("%i -> ", pointeur);
        }
    }
    pointeur = pointeur->gauche;
}