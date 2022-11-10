#include <stdio.h>
#include <stdlib.h>

/* EP07_09

    Receives a 3 by 3 integers matrix as a one-dimensional array; returns a
    pointer to a dynamically allocated array of 3 ints, where each element is
    composed by the sum of the numbers in each column of the matrix.

    Author: Nicolas Marcelino da Silva <05/11/2022>
*/

/// @brief Returns a pointer to a dynamic 3 elements array, where each element
/// of the array is composed by the sum of the numbers of each columns of the
/// given matrix.
/// @param mat_A Pointer to the first element of the 3x3 matrix (this being a
/// one-dimensional array);
/// @return Pointer to a dynamic 3 int array.
int* funcao(int *mat_A);

void main() 
{
    int *p = NULL;

    int mat[9] = {-8, -3, -4, 1, 2, 3, 8, -4, -1};

    p = funcao(mat);

    for (int i = 0; i < 3; i++) 
    {
        printf("%d ", *(p + i));
    }

    free(p);
    p = NULL;
}

int* funcao(int *mat_A) 
{
    int *p = NULL, count = 0;;
    p = (int *) calloc(3, sizeof(int));

    for (int i = 0; i < 9; i++) 
    {
        if (count > 2) 
        {
            count = 0;
        }
        *(p + count++) += *(mat_A + i);
    }
    return p;
}