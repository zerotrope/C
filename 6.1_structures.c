#include <stdio.h>
#include <stdlib.h>

// Structure = regroupement d'information = définition de variables/pointeurs, aucun code executable ne DOIT être à l'interieur (i.e. pas de 'int age = 50;')
typedef struct personnage
{
    int age;
    char *nom;
    char *prenom;
} personnage;

personnage *creer_personnage()
{
    personnage *nouveau_personnage;

    nouveau_personnage = malloc(sizeof(personnage));

    // Espace continu en mémoire addresse structure = addresse 1ère variable
    /*printf("Addresse de personnage : %x\n", nouveau_personnage);
    printf("Addresse de nom : %x\n", &nouveau_personnage->nom);
    printf("Addresse de prenom : %x\n", &nouveau_personnage->prenom);
    // printf("Addresse d'age : %x\n", &nouveau_personnage->age);*/

    // Nom
    nouveau_personnage->nom = malloc(sizeof(nouveau_personnage->nom));

    //(*nouveau_personnage).nom
    //nouveau_personnage->nom

    printf("Veuillez  entrer le nom de votre personnage :\n");
    if (scanf("%s", nouveau_personnage->nom) != 1)
    {
        printf("Pas d'information acquise\n");
        nouveau_personnage->nom = "Piton";
    }

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

    // Return
    return(nouveau_personnage);
}

void affichePersonnage (personnage *personnage)
{
    printf("%s %s, %i ans\n", personnage->prenom, personnage->nom, personnage->age);
}

void libererPersonnage (personnage *personnage)
{
    free(personnage->nom);
    free(personnage->prenom);
    free(personnage);
}

int main()
{
    personnage *hero;

    /*printf("Création de papa\n");
    papa = creer_personnage();

    personnage *maman;
    printf("Création de maman\n");
    maman = creer_personnage();

    personnage *bebe;
    printf("Création de bebe\n");
    bebe = creer_personnage();

    printf("L'age de papa (%s) est : %i\n", papa->prenom, papa->age);
    printf("L'age de maman (%s) est : %i\n", maman->prenom, maman->age);
    printf("L'age de bebe (%s) est : %i\n", bebe->prenom, bebe->age);*/

    // Mallocs ! sinon seg fault sur des choses non malloquées
    /*hero->nom = "Morane";
    hero->prenom = "Bob";
    hero->age = 33;*/

    // Alternative en statique ! (=> passage par l'adresse pour impression)
    /*personnage hero;
    hero.nom = "Morane"
    affichePersonnage(&hero);*/

    //hero = creer_personnage();
    printf("L'identité du hero est : ");
    affichePersonnage(hero);

    // Il faut toujours free les variables composant une structure avant la structure elle-même
    // Sinon l'adresse de la structure peut être à tout moment ré-utilisée entre-temps
    /*free(hero->prenom);
    free(hero->nom);
    free(hero);*/

    // Alternative par une seule fonction
    libererPersonnage(hero);

    return 0;
}

// Exercice 1 : Fonction qui libère la mémoire d'un personnage 'liberer_memoire' bebe puis maman puis papa
// -> que doit-on libérer et dans quel sens free(maman) suffit? ou plus?

// Exercie 2 : Simplifier lignes 72 à 74 par une seule fonction 'afficher_prenom_age'
// -> sans doute va prendre un paramètre à déterminer

// Plus loin : faire des connexions entre les personnages et se balader dedans 'listes chainées'