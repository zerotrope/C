    // Preprocess
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TRUE
#define TRUE 0
#endif

#ifndef FALSE
#define FALSE 1
#endif

typedef int BOOL;

#define MAX_STR 256

// Structures
typedef struct
{
	int size;
	int **pResult;
	char **pOperation;
} Stack;

void swap(int *a, int *b);
void incr(int *a);
void tri(int t[], int size);
void printt(int t[], int size);
void quicksort(int t[], int size);
void drapeau(int t[], int size);

BOOL push(Stack *pStack, char *pResult,	char *pOperation);
BOOL empty(Stack *pStack);
void kill(Stack *pStack);

// Main 1
int main()
{
	// Passage de paramètres
	int x = 5;
	incr(&x);
	printf("x = %d\n", x);
	printf("\n\n");

	// Swap
	int a = 1;
	int b = 2;

	swap(&a, &b);
	printf("a = %i\tb = %i\n", a, b);
	swap(&a, &b);
	printf("a = %i\tb = %i\n", a, b);
	printf("\n\n");

	// Tri croissant
	int t[15] = { 5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8 };
	int dt = sizeof(t) / sizeof(t[0]);

	printf("t = ");
	printt(t, dt);
	tri(t, dt);
	printf("t = ");
	printt(t, dt);
	printf("\n\n");

	// Quicksort
	int q[15] = {5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8};
	int dq = sizeof(q) / sizeof(q[0]);

	printf("q = ");
	printt(q, dq);
	quicksort(q, dq);
	printf("q = ");
	printt(q, dq);
	printf("\n\n");

	// Drapeau hollandais
	int h[15] = { 5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8 };
	int dh = sizeof(h) / sizeof(h[0]);

	printf("h = ");
	printt(h, dh);
	drapeau(h, dh);
	printf("h = ");
	printt(h, dh);
	printf("\n\n");

	system("pause");
	return 0;
}

// Main 2
/*int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int *p1 = &a;
	int *p2 = &c;
	printf("a = %i  b = %i  c = %i  &a = %i  &b = %i  &c = %i  p1 = %i  p2 = %i  *p1 = %i  *p2 = %i\n", a, b, c, &a, &b, &c, p1, p2, *p1, *p2);

	// Operations
	//char d[MAX_STR] = "*p1=*p2";
	//printf("d = %c\n", d);

	p1 = &a;
	printf("a = %i  b = %i  c = %i  &a = %i  &b = %i  &c = %i  p1 = %i  p2 = %i  *p1 = %i  *p2 = %i\n", a, b, c, &a, &b, &c, p1, p2, *p1, *p2);
	p2 = &c;
	printf("a = %i  b = %i  c = %i  &a = %i  &b = %i  &c = %i  p1 = %i  p2 = %i  *p1 = %i  *p2 = %i\n", a, b, c, &a, &b, &c, p1, p2, *p1, *p2);
	*p1 = *p2;
	printf("a = %i  b = %i  c = %i  &a = %i  &b = %i  &c = %i  p1 = %i  p2 = %i  *p1 = %i  *p2 = %i\n", a, b, c, &a, &b, &c, p1, p2, *p1, *p2);
	(*p2)++;
	printf("a = %i  b = %i  c = %i  &a = %i  &b = %i  &c = %i  p1 = %i  p2 = %i  *p1 = %i  *p2 = %i\n", a, b, c, &a, &b, &c, p1, p2, *p1, *p2);
	p1 = p2;
	printf("a = %i  b = %i  c = %i  &a = %i  &b = %i  &c = %i  p1 = %i  p2 = %i  *p1 = %i  *p2 = %i\n", a, b, c, &a, &b, &c, p1, p2, *p1, *p2);
	p2 = &b;
	printf("a = %i  b = %i  c = %i  &a = %i  &b = %i  &c = %i  p1 = %i  p2 = %i  *p1 = %i  *p2 = %i\n", a, b, c, &a, &b, &c, p1, p2, *p1, *p2);
	(*p2)--;
	*p1 = *p2 - c;
	a = (2 + *p2) * *p1;
	p2 = &c;
	*p2 = *p1 / *p2;
	*p1 = a + b;
	a += *p1;
	b = *p1 + *p2;
	*p1 = 2 * a;
	a = *p2;
	*p2 = *p1 - *p2;
	*p1 = 1 - c;
	*p2 += *p1 + a;
	p2 = p1 = &a;
	p2++;
	p1 += 2;
	c = p2 == &c;
	//p1 = 0;

	printf("a = %i  b = %i  c = %i  &a = %i  &b = %i  &c = %i  p1 = %i  p2 = %i  *p1 = %i  *p2 = %i\n", a, b, c, &a, &b, &c, p1, p2, *p1, *p2);
	system("pause");
	return 0;
}*/

// Functions
void incr(int *a)
{
	*a = (*a)++;
}

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void printt(int t[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", t[i]);
	}
	printf("\n\n");
}

void tri(int t[], int size)							// Bubble
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (t[i] > t[j])
			{
				swap(&t[i], &t[j]);
				count++;
			}
		}
	}
	printf("Tri croissant apres %i iterations : ", count);
}

void quicksort(int t[], int size)					// Quicksort
{
	int i = 0;										// Itérateur gauche
	int k = 6;										// Pivot 1
	int max = size - 1;								// Itérateur droit
	int count = 0;									// Compteur

	while (i <= max)
	{
		if (t[i] < k)
			i++;
		if (t[max] > k)
			max--;
		if (t[i] >= k)
			swap(&t[i], &t[max]); i++; max--; count++;
	}
	printf("Quicksort apres %i interations : ", count);
}


void drapeau(int t[], int size)
{
	int i = 0;										// Itérateur gauche
	int j = 3;										// Pivot 1
	int k = 6;										// Pivot 2
	int max1 = 6;									// Itérateur droit
	int max2 = size - 1;							// Itérateur final
	int count;										// Compteur

													/*for (i = 0; i <= j; i++)*/
	do
	{
		count = 0;
		while (i <= max2)
		{
			/*if (t[i] < j)
				i++;
			if (t[max1] >= j)
				max1--;
			if (t[max2] > k)
				max2--;
			if (t[i] >= j)
				swap(&t[i], &t[max1]); i++; max1--; count++;
			if (t[i] >= k)
				swap(&t[i], &t[max1]); swap(&t[i], &t[max2]); i++; max1--; max2--; count++;*/

			if (t[i] < j)
				i++;
			if (t[i] >= j)
				swap(&t[i], &t[k]); i++;  k--; count++;
			if (t[i] > k)
				swap(&t[i], &t[k]); swap(&t[i], &t[max2]); i++;  k--; max2--; count++;
		}
		printf("Drapeau apres %i interations : ", count);
	} while (count != 0);
}

	/*while (i <= j)								// Tant que (i <= j) Faire
	{												// En fonction de la valeur de T[i]
		if (t[i] < 3)								// Cas au début : tous les éléments dont la valeur est < 3 sont au début du tableau
		{
			i = i + 1;
		}
		if (t[i] > 3)								// Cas du milieu : tous les éléments dont 3 < valeur < 6 sont au milieu
		{
			// Echange t[i] et t[j]
			swap(&t[i], &t[j]);
			j = j - 1;
		}
		if (t[i] > 6)								// Cas de la fin :  tous les éléments dont la valeur > 6 sont à la fin
		{
			// Echange t[i] et t[k]
			swap(&t[i], &t[k]);
			// Echange t[i] et t[j]
			swap(&t[i], &t[j]);
			j = j - 1;
			k= k - 1;
		}
	}
}*/

/*BOOL empty(Stack *pStack)
{
	BOOL empty = FALSE;
	if (pStack->size == 0
		&& pStack->pResult == NULL
		&& pStack->pOperation == NULL)
	{
		empty = TRUE;
	}
	return empty;
}

BOOL push(Stack *pStack,
	char *pResult,
	char *pOperation)
{
	BOOL pushed = TRUE;
	char *pushResult = (int*)malloc(sizeof(int) * strlen(pResult) + 1);
	char *pushOperation = (char*)malloc(sizeof(char) * strlen(pOperation) + 1);

	strcpy(pushResult, pResult);
	strcpy(pushOperation, pOperation);

	if (empty(pStack) == TRUE)
	{
		pStack->pResult = (int**)malloc(sizeof(int*));
		pStack->pOperation = (char**)malloc(sizeof(char*));

		if ((pStack->pResult == NULL) || (pStack->pOperation == NULL))
		{
			pushed = FALSE;
		}
		else
		{
			pStack->pResult[pStack->size] = (int*)malloc(sizeof(int) * strlen(pResult) + 1);
			pStack->pOperation[pStack->size] = (char*)malloc(sizeof(char) * strlen(pOperation) + 1);

			pStack->pResult[pStack->size] = pushResult;
			pStack->pOperation[pStack->size] = pOperation;
			pStack->size = pStack->size + 1;
		}
	}
	else
	{
		char **ipResult = pStack->pResult;
		char **ipOperation = pStack->pOperation;

		char **pAddedResult = NULL;
		char **pAddedOperation = NULL;

		pAddedResult = (int**)malloc(sizeof(int*) * (pStack->size + 1));
		pAddedOperation = (char**)malloc(sizeof(char*) * (pStack->size + 1));

		if (((pAddedResult == NULL)
			|| (pAddedOperation == NULL)))
		{
			int i;
			for (i = 0; i < pStack->size; i++)
			{
				pAddedResult[i] = ipResult[i];
				pAddedOperation[i] = ipOperation[i];
			}
			pAddedResult[i] = (char*)malloc(sizeof(char) * strlen(pResult) + 1);
			pAddedOperation[i] = (char*)malloc(sizeof(char) * strlen(pOperation) + 1);

			pAddedResult[i] = pushResult;
			pAddedOperation[i] = pushOperation;

			pStack->size = pStack->size + 1;
			pStack->pResult = pAddedResult;
			pStack->pOperation = pAddedOperation;

			free(ipResult);
			free(ipOperation);

			ipResult = NULL;
			ipOperation = NULL;
		}
		else
		{
			pushed = FALSE;
		}
	}
	return pushed;
}

void kill(Stack *pStack)
{
	if (pStack->pResult != NULL)
	{
		free(pStack->pResult);
		free(pStack->pOperation);

		pStack->pResult = NULL;
		pStack->pOperation = NULL;
	}
	pStack->size = 0;
}*/
