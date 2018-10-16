// PREPROCESS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// FUNCTIONS
// Printing Char Matrix function
void show(char **t, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for(int j = 0; j < size2; j++)
		{
			printf("%3c ", t[i][j]);
		}
	printf("\n");
	}
	printf("\n");
}

// Shortest path recursive function
int recursive(int result, int **m, int i, int j, int r, int c)
{
    result = result + m[i][j];
    if (i == (r - 1) && j == (c - 1))
    {
        return result;
    }
    if (i == (r - 1))						// If reaching last row...
    {
        return recursive(result, m, i, j + 1, r, c);		// ...I call the recursive function on right case.
    }
    if (j == (c - 1))						// If I reach last column...
    {
        return recursive(result, m, i + 1, j, r, c);		// ...I call the recursive function on below case.
    }
    int right = recursive(result, m, i, j + 1, r, c);		// Right is a call of the function on the right.
    int low = recursive(result, m, i + 1, j, r, c);		// Low is a call of the function on the below.
    if(right < low)						// Smaller step is to be priviledged.
    {
        return right;
    }
    return low;
}

// MAIN
int main()
{
    // Initializing random function
    srand(time(NULL));

    // Matrix initializatin 5x5 rand()%100
    int **m;
    m = malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++)
    {
        m[i] = malloc(sizeof(int) * 5);
        for (int j = 0; j < 5; j++)
        {
            m[i][j] = rand()%100;
        }
    }
    show(m, 5, 5);

    // Calling the recursive function
    printf("Shortest path : %i\n\n", recursive(0, m, 0, 0, 5, 5));
    free(m);

    return 0;
}

