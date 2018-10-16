// Defines
#ifndef HEADERS_H
#define HEADERS_H

// Structures
typedef struct personnage
{
    int age;
    char *prenom;

    struct personnage *Suivant;

} personnage;

// Signatures

// Purpose :
// Return :
// Parameters :
personnage *creerPersonnage();

void afficherPersonnage (personnage *personnage);
void libererPersonnage(personnage *personnage);
void afficherListe(personnage *liste);
void supprimerFIFO(personnage *liste);
personnage *returnSupprimer_FILO(personnage *liste);
void supprimerFILO(personnage **liste);
void creerFILO(personnage **liste);
personnage *returnCreerFIFO(personnage *liste);
void creerFIFO(personnage **liste);
void pegi18(personnage **liste);

#endif