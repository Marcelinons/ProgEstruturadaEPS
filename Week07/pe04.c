#include <stdio.h>
#include <stdlib.h>

/* EP07_04

    Receives the number of lines and columns of a matrix; receives a int x;
    Reads from the keyboard the elements of the matrix; verifies the existence
    of x in the matrix.

    NicolasMSilva <03/11/22>
*/

/// @brief Reads a dynamic matrix (n x m) of ints.
/// @param lin Number of lines;
/// @param col Number of columns;
/// @param mat Pointer of pointer to the matrix;
void ReadMat(int n, int m, int **mat);

/// @brief Verifies the existence of a given int n on a matrix.
/// @param n Number of lines of the matrix;
/// @param m Number of columns of the matrix;
/// @param x Int whose existence inside the matrix will be verified;
/// @param mat Pointer of pointer to the the matrix;
void IsXInMat(int n, int m, int x, int **mat);

void main () 
{
    int n, m, x, **mat = NULL;
    scanf("%d%d%d", &n, &m, &x);

    // Allocate memory for an array of pointers.
    mat = (int **) malloc(n * m * sizeof(int *));    
    ReadMat(n, m, mat);
    IsXInMat(n, m, x, mat);

    // Free the used space.
    for (int i = 0; i < m; i++) 
    {
        free(*(mat + i));
    }
    free(mat);
    mat = NULL;
}

void ReadMat(int n, int m, int **mat) 
{
    // Allocate memory for each line of the matrix.
    for (int i = 0; i < m; i++) 
    {
        mat[i] = (int *) malloc(m * sizeof(int));
    }
    // Get the values.
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void IsXInMat(int n, int m, int x, int **mat) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (mat[i][j] == x) 
            {
                printf("SIM");
                return;
            }
        }
    }
    printf("NAO");
}