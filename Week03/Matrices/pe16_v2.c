#include <stdio.h>
#include <stdlib.h>

/*
    Another version of pe16.c. This time, I used dynamically allocated matrices
    and only one function to calculate the diagonals's sum.

    Author: Nicolas Marcelino da Silva <09/11/2022>
*/

/// @brief Creates a pointer to pointer of a dynamically allocated integer
/// matrix with size n by n.
/// @param n Dimensions of the matrix.
/// @return Pointer to pointer of a integer matrix with size n by n.
int** CreateSquareMatrix(int n);

/// @brief Reads the int values for a n by n matrix.
/// @param n Dimensions of the matrix.
/// @param mat Pointer to pointer of a int matrix.
void ReadSquareMatrix(int n, int **mat);

/// @brief Frees the memory used by a dynamic n by n int matrix.
/// @param n Dimensions of the matrix.
/// @param mat Pointer to pointer of a int matrix.
void FreeSqrMatMemory(int n, int **mat);

/// @brief Calculates the sum of the numbers on the main diagonal and on the
/// secondary diagonal of the given matrix.
/// @param mainDiag Int pointer to store the sum of the main diagonal.
/// @param secDiag Int pointer to store the sum of the secondary diagonal.
/// @param n Dimensions of the matrix.
/// @param mat Pointer to pointer of a int matrix.
void SumOfDiagonal(int *mainDiag, int *secDiag, int n, int **mat);

/// @brief Prints the elements of a n by n int matrix.
/// @param n Dimensions of the matrix.
/// @param mat Pointer to pointer of a int matrix.
void PrintSqrMatrix(int n, int **mat);

void main () 
{
    int mainDiag = 0, secDiag = 0, **mat = NULL, n;
    printf("Enter size of the matrix: ");
    scanf("%d", &n);

    mat = CreateSquareMatrix(n);
    ReadSquareMatrix(n, mat);
    SumOfDiagonal(&mainDiag, &secDiag, n, mat);

    printf("------ Entered matrix ------\n");
    PrintSqrMatrix(n, mat);
    printf("\nSum of main diagonal = %d\n", mainDiag);
    printf("Sum of secondary diagonal = %d\n", secDiag);

    FreeSqrMatMemory(n, mat);
}

int** CreateSquareMatrix(int n) 
{
    int **mat = NULL;
    mat = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) 
    {
        mat[i] = (int *) malloc(n * sizeof(int));
    }
    return mat;
}

void ReadSquareMatrix(int n, int **mat) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void FreeSqrMatMemory(int n, int **mat) 
{
    for (int i = 0; i < n; i++) 
    {
        free(mat[i]);
    }
    free(mat);
    mat = NULL;
}

void SumOfDiagonal(int *mainDiag, int *secDiag, int n, int **mat) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == j) 
            {
                *mainDiag += mat[i][j];
            } 
            if (i + j == n-1) 
            {
                *secDiag += mat[i][j];
            }
        }
    }
}

void PrintSqrMatrix(int n, int **mat) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (mat[i][j] >= 10) 
            {
                printf("%d ", mat[i][j]);
            } else 
            {
                printf("%d  ", mat[i][j]);
            }
        }
        printf("\n");
    }
}