#include <stdio.h>
#include <stdlib.h>

/* 
    Another version of PE19.c, this time using dynamically allocated memory and
    pointer-to-pointer matrices.

    Author: Nicolas Marcelino da Silva
*/

/// @brief Dynamically allocate a matrix of n by m int elements.
/// @param n Number of lines;
/// @param m Number of columns;
/// @return Pointer to pointer to a matrix of n by m.
int** CreateMat(int n, int m);

/// @brief Free the memory space used by the matrix.
/// @param n Number of lines;
/// @param mat Pointer to pointer to a matrix of n by m.
void FreeMat(int n, int **mat);

/// @brief Reads the elements of a n by m int matrix.
/// @param n Number of lines;
/// @param m Number of columns;
/// @param mat Pointer to pointer of the first element of the matrix;
void ReadMat(int n, int m, int **mat);

/// @brief Prints the elements of a n by m int matrix.
/// @param n Number of lines;
/// @param m Number of columns;
/// @param mat Pointer to pointer to the first element of the matrix;
void PrintMat(int n, int m, int **mat);

/// @brief Verifies wether a given n by n matrix is a upper/lower triangular
/// matrix, diagonal matrix or none of these.
/// @param n Dimensions of the matrix;
/// @param mat Pointer to pointer to the first element of the matrix;
void IsTriangular(int n, int **mat);

void main() 
{
    int **matrix = NULL;
    int n, m;
    
    scanf("%d%d", &n, &m);

    matrix = CreateMat(n, m);

    ReadMat(n, m, matrix);
    PrintMat(n, m, matrix);
    
    if (n == m) 
    {
        IsTriangular(n, matrix);
    }
    
    // Free used space;
    FreeMat(n, matrix);
}

int** CreateMat(int n, int m) 
{
    int** mat = NULL;
    mat = (int **) malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) 
    {
        mat[i] = (int *) malloc(m * sizeof(int));
    }
    return mat;
}

void FreeMat(int n, int **mat) 
{
    for (int i = 0; i < n; i++) 
    {
        free(mat[i]);
    }
    free(mat);
    mat = NULL;
}

void ReadMat(int n, int m, int **mat) 
{
    printf("\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
}

void PrintMat(int n, int m, int **mat) 
{
    for (int i = 0; i < n; i ++) 
    {
        for (int j = 0; j < m; j++) 
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void IsTriangular(int n, int **mat) 
{
    int upper = 1, lower = 1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i < j && mat[i][j] != 0) 
            {
                lower = 0;
            } else if (i > j && mat[i][j] != 0) 
            {
                upper = 0;
            }
        }
    }
    if (upper && lower) 
    {
        printf("The matrix is diagonal.\n");
    } else if (upper) 
    {
        printf("The matrix is Upper Triangular.\n");
    } else if (lower) 
    {
        printf("The matrix is lower triangular.\n");
    } else 
    {
        printf("The matrix is neither upper/lower triangular nor diagonal.\n");
    }
}

/* Test inputs.
- Diagonal
3
3
1
0
0
0
1
0
0
0
1
- Upper
3
3
1
1
1
0
1
1
0
0
1
- Lower
3
3
1
0
0
1
1
0
1
1
1
- Upper
4
4
1
2
3
4
0
5
6
7
0
0
8
9
0
0
0
10
*/