// Preprocess
#include <stdio.h>
#include <stdlib.h>
#include "7.0_headers.h"

// Functions
personnage *creerPersonnage()
{
    personnage *nouveau_personnage;
    nouveau_personnage = malloc(sizeof(personnage));

    // Prénom
    nouveau_personnage->prenom = malloc(sizeof(nouveau_personnage->prenom));
    printf("Veuillez  entrer le prenom de votre personnage :\n");
    if (scanf("%s", nouveau_personnage->prenom) != 1)
    {
        printf("Pas d'information acquise\n");
        nouveau_personnage->prenom = "Florence";
    }

    // Âge
    printf("Veuillez  entrer l'age de votre personnage :\n");
    if (scanf("%i", &nouveau_personnage->age) != 1)
    {
        printf("Pas d'information acquise\n");
        nouveau_personnage->age = 50;
    }

    nouveau_personnage->Suivant = NULL;

    // Return
    return(nouveau_personnage);
}

void afficherPersonnage (personnage *personnage)
{
    printf("%s, %i ans\n", personnage->prenom, personnage->age);
}

void libererPersonnage(personnage *personnage)
{
    free(personnage->prenom);
    free(personnage);
}

void afficherListe(personnage *liste)
{
    personnage *pointeur = liste;
    while (pointeur != NULL)
    {
        printf("%s, %i ans -> ", pointeur->prenom, pointeur->age);
        pointeur = pointeur->Suivant;
    }
    printf(" 'NULL'\n");
}

void supprimerFIFO(personnage *liste) // Je ne touche pas à Head lui-même, je parcours la liste
{
    if (liste == NULL)
    {
        return;
    }
    if (liste->Suivant == NULL)
    {
        libererPersonnage(liste);
        liste = NULL;
        return;
    }
    else
    {
        personnage *pointeur = liste;
        while (pointeur->Suivant->Suivant != NULL)
        {
            pointeur = pointeur->Suivant;
        }
        libererPersonnage(pointeur->Suivant);
        pointeur->Suivant = NULL;
    }
}

// Fonction retournant un pointeur sur une struct personnage, liste pointe au même endroit que Head mais ne le modifie pas
personnage *returnSupprimer_FILO(personnage *liste)
{
    //printf("Liste : %x\n", &liste);
    if (liste == NULL)
    {
        return NULL;
    }
    else
    {
        personnage *pointeur = liste;
        liste = liste->Suivant;
        libererPersonnage(pointeur);
    }
    return liste;
}

// Version avec double pointeur de pointeur : Là je touche à Head lui-même, liste = Head, les modifications sur liste impactent Head
void supprimerFILO(personnage **liste)
{
    if (liste == NULL)
    {
        return;
    }
    else
    {
        personnage *pointeur = *liste;
        *liste = (*liste)->Suivant;
        libererPersonnage(pointeur);
    }
}

void creerFILO(personnage **liste)
{
    if(*liste == NULL)
    {
        *liste = creerPersonnage();
    }
    else
    {
        personnage *pointeur;
        pointeur = *liste;
        while(pointeur->Suivant != NULL)
        {
            pointeur = pointeur->Suivant;
        }
        pointeur->Suivant = creerPersonnage();
    }
}

void creerFIFO(personnage **liste)
{
    // Pointeur
    personnage *pointeur;
    pointeur = creerPersonnage();

    // Connexion
    pointeur->Suivant = *liste;
    *liste = pointeur;
}

void pegi18(personnage **liste)
{
    // Supprimer tous les éléments de tête inférieurs à 18 ans
    while (*liste != NULL && (*liste)->age < 18)
    {
        supprimerFILO(liste);
    }
    // Abandon si tous supprimés
    if (*liste == NULL)
    {
        return;
    }
    // Sinon parcours de la liste
    personnage *pointeur = *liste;
    while (pointeur->Suivant != NULL)
    {
        if (pointeur->Suivant->age < 18)
        {
            personnage *pointeur_supprimer = pointeur->Suivant;
            pointeur->Suivant = pointeur->Suivant->Suivant;
            libererPersonnage(pointeur_supprimer);
        }
        else
        {
            pointeur = pointeur->Suivant;
        }
    }
}