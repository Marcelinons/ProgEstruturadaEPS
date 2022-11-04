#include <stdio.h>
#include <stdlib.h>

/// @brief Returns the pointer for a dynamic int matrix.
/// @param N Dimensions of the matrix;
/// @return Pointer of pointer to a matrix.
int** funcao(int N);

/// @brief Prints the elements of a given N by N matrix.
/// @param N Dimensions of the matrix;
/// @param mat Pointer to Pointer of a N by N matrix.
void PrintMat(int N, int **mat);

void main(void) 
{
    int **mat = NULL;
    int N = 19;

    mat = funcao(N);

    PrintMat(N, mat);

    // Free used space
    for (int i = 0; i < N; i++) 
    {
        free(mat[i]);
    }
    free(mat);
    mat = NULL;
}

int** funcao(int N) 
{
    int **mat = NULL;

    mat = (int **) malloc(N * N * sizeof(int));
    for (int i = 0; i < N; i++) 
    {
        mat[i] = (int *) malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (i == j) 
            {
                mat[i][j] = 0;
            } else if (i < j) 
            {
                mat[i][j] = 1;
            } else 
            {
                mat[i][j] = -1;
            }
        }
    }
    return mat;
}

void PrintMat(int N, int **mat) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (mat[i][j] < 0) 
            {
                printf("%d ", mat[i][j]);
            } else 
            {
                printf(" %d ", mat[i][j]);
            }
        }
        printf("\n");
    }
}