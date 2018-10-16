// Preprocesseurs système
#include <stdio.h>
#include <stdlib.h>

// Preprocesseurs code
#include "7.2_headers.h"

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
        nouveau_personnage->prenom = "Personne";
    }

    // Âge
    printf("Veuillez  entrer l'age de votre personnage :\n");
    if (scanf("%i", &nouveau_personnage->age) != 1)
    {
        printf("Pas d'information acquise\n");
        nouveau_personnage->age = 0;
    }

    nouveau_personnage->Suivant = NULL;
    nouveau_personnage->Precedent = NULL;

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
    printf(" 'NULL' -> ");
    while (pointeur != NULL)
    {
        printf("%s, %i ans -> ", pointeur->prenom, pointeur->age);
        pointeur = pointeur->Suivant;
    }
    printf(" 'NULL'\n");
}

void afficherListeReverse(personnage *liste)
{
    personnage *pointeur = liste;
    printf(" 'NULL' <- ");
    while (pointeur != NULL)
    {
        printf("%s, %i ans <-> ", pointeur->prenom, pointeur->age);
        pointeur = pointeur->Precedent;
    }
    printf(" 'NULL'\n");
}

void supprimerFIFO(personnage **head, personnage **tail)
{
    if (*head == NULL)
    {
        return;
    }
    else
    {
        personnage *pointeur = *tail;
        *tail = (*tail)->Precedent;           // Si après décallage
        if(*tail == NULL)                     // la liste est vide
            *head = *tail;                    // alors ajuster tail
        else
            (*tail)->Suivant = NULL;
        libererPersonnage(pointeur);
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

// Version avec double pointeur de pointeur
void supprimerFILO(personnage **head, personnage **tail)
{
    if (*head == NULL)
    {
        return;
    }
    else
    {
        personnage *pointeur = *head;
        *head = (*head)->Suivant;           // Si après décallage
        if(*head == NULL)                   // la liste est vide
            *tail = *head;                  // alors ajuster tail
        else
            (*head)->Precedent = NULL;
        libererPersonnage(pointeur);
    }
}

void creerFILO(personnage **head, personnage **tail)
{
    if(*head == NULL)
    {
        *head = creerPersonnage();
        *tail = *head;
    }
    else
    {
        (*tail)->Suivant = creerPersonnage();
        (*tail)->Suivant->Precedent = *tail;
        *tail = (*tail)->Suivant;
    }
}

void creerFIFO(personnage **head, personnage **tail)
{
    if(*head == NULL)
    {
        *head = creerPersonnage();
        *tail = *head;
    }
    else
    {
        (*head)->Precedent = creerPersonnage();
        (*head)->Precedent->Suivant = *head;
        *head = (*head)->Precedent;
    }
}