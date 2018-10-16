// Defines
#ifndef HEADERS2_H
#define HEADERS2_H

// Structures
typedef struct personnage
{
    int age;
    char *prenom;
    struct personnage *Suivant;
    struct personnage *Precedent;
} personnage;

// Signatures

// Purpose :
// Return :
// Parameters :
personnage *creerPersonnage();

void afficherPersonnage (personnage *personnage);
void libererPersonnage(personnage *personnage);
void afficherListe(personnage *liste);
void supprimerFIFO(personnage **head, personnage **tail);
personnage *returnSupprimer_FILO(personnage *liste);
void supprimerFILO(personnage **head, personnage **tail);
void creerFILO(personnage **head, personnage **tail);
personnage *returnCreerFIFO(personnage *liste);
void creerFIFO(personnage **head, personnage **tail);

#endif