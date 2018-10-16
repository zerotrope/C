#include <stdio.h>
#include <stdlib.h>

// Structure = regroupement d'information = définition de variables/pointeurs, aucun code executable ne DOIT être à l'interieur (i.e. pas de 'int age = 50;')
typedef struct personnage
{
    int age;
    char *prenom;

    struct personnage *Suivant;

} personnage;

personnage *creer_personnage()
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

void affichePersonnage (personnage *personnage)
{
    printf("%s, %i ans\n", personnage->prenom, personnage->age);
}

void libererPersonnage(personnage *personnage)
{
    free(personnage->prenom);
    free(personnage);
}

void afficheListe(personnage *liste)
{
    personnage *pointeur_temp = liste;
    while (pointeur_temp != NULL)
    {
        printf("%s, %i ans -> ", pointeur_temp->prenom, pointeur_temp->age);
        pointeur_temp = pointeur_temp->Suivant;
    }
    printf(" 'NULL'\n");
}

void supprimerPersonnage_fin(personnage *liste) // Je ne touche pas à Head lui-même, je parcours la liste
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
personnage *supprimerPersonnage_tete(personnage *liste)
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

// Version avec pointeur de pointeur : Là je touche à Head lui-même, liste = Head, les modifications sur liste impactent Head
void testsupprimerPersonnage_tete(personnage **liste)
{
    //printf("Liste : %x\n", &liste);
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

void ajouterPersonnage_fin(personnage **liste)
{
    if(*liste == NULL)
    {
        *liste = creer_personnage();
    }
    else
    {
        personnage *pointeur;
        pointeur = *liste;
        while(pointeur->Suivant != NULL)
        {
            pointeur = pointeur->Suivant;
        }
        pointeur->Suivant = creer_personnage();
    }
}

int main()
{
    int choix = 0;
    personnage *Head;
    Head = NULL;
    //1 - créer un personnage + ajoute au début de la liste
    //2 - supprimer le dernier personnage de la liste
    //3 - afficher la liste tel quel
    //4 - ajouter personnage en tete de liste
    //9 - sortir

    while(choix != 9)
    {
        printf("Que faire : \n1- créer personnage (FIFO)\n2- supprimer personnage (FIFO)\n3- afficher liste\n4- ajouter personnage (fin)\n5- supprimer personnage (tete)\n9- sortir\n");
        scanf("%i", &choix);
        if(choix == 1)
        {
            personnage *pers;
            pers = creer_personnage();
            pers->Suivant = Head;
            Head = pers;
        }
        else if (choix == 2)
        {
            supprimerPersonnage_fin(Head);
        }
        else if (choix == 3)
        {
            afficheListe(Head);
        }
        else if (choix == 4)
        {
            /*personnage *ajout;
            ajout = creer_personnage();
            ajout->Suivant = Head;
            Head = ajout;*/
            ajouterPersonnage_fin(&Head);
        }
        else if (choix == 5)
        {
            //printf("Head : %x\n", &Head);
            //Head = supprimerPersonnage_tete(Head);
            testsupprimerPersonnage_tete(&Head);
        }
    }

    return 0;
}

/*
Exercices
 - créer personnage FIFO en function (5min)
 - choix supprimer tous les éléments de la liste des < 18 ans (attention la liste peut : contenir que des < 18 ans ou pas ou ...etc. (30min+)
*/