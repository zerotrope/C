#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void quickSort(int tableau[], int debut, int fin);
void echanger(int tableau[], int a, int b);

int main(void)
{
    //int tab[5] = {5, 3, 4, 1, 2};
    int tab[15] = { 5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8 };
    int i;

    quickSort(tab, 0, 14);

    for(i = 0; i < 15; i++)
    {
	printf("%d ", tab[i]);
    }
    putchar('\n');

    return 0;
}

void echanger(int tableau[], int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(int tableau[], int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];

    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;

    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}
