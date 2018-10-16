// Preprocess
#include <stdio.h> // entrées/sorties clavier, sorties
#include <stdlib.h> // gère malloc, free, realloc, calloc
#include <string.h>

#ifndef TRUE
#define TRUE 0
#endif

#ifndef FALSE
#define FALSE 1
#endif

typedef int BOOL;

#define MAX_STR 256

#define NO_SORTIE -1
#define MUR 0
#define SORTIE 1
#define DEJA_VU 2

// Signatures
void incr(int *a);
void affiche(int t[], int size);
void swap(int *a, int *b);
int success(int t[], int size);
void stupide(int t[], int size);
void bulles(int t[], int size);
void selection(int t[], int size);
void quicksort(int t[], int debut, int fin);
void drapeau(int t[], int size);
void affichePointeur(int *t, int size);
void afficheChar(char *c, int size);
void swapChar(char *a, char *b);
void alphabet(char c[], int size);
void afficheMatrice(int **t, int size1, int size2);
void afficheMatriceChar(char **t, int size1, int size2);
int recursive(int result, int **m, int i, int j, int r, int c);
int labyrinthe2d(int **m, int i, int j, int r, int c, int *count);
int labyrinthe4d(int **m, int i, int j, int r, int c, int *count);
int laby(int **m, int i, int j, int er, int ec, int sr, int sc, int *count);
int maze(char **m, int i, int j, int er, int ec, int sr, int sc, int *count);