#include <stdio.h>
#include <stdlib.h>

/* EP07_06

    Receives the size N of a int array; if N <= 0, returns a null pointer,
    otherwise returns the pointer to a dynamic int array.

    Author: Nicolas Marcelino da Silva <04/11/2022>
*/

/// @brief Returns a pointer to a dynamic int array of N elements.
/// @param N Number of elements;
/// @return If N <= 0, returns a NULL pointer. Otherwise, returns a pointer to a
/// N elements dynamic int array.
int* funcao(int N);

void main(void) 
{
    int n, *vet;
    scanf("%d", &n);
    vet = funcao(n);
    if (vet == NULL) 
    {
        printf("The pointer is NULL\n");
    } else 
    {
        printf("The pointer is not NULL\n");
    }

    free(vet);
    vet = NULL;
}

int* funcao(int N) 
{
    int *p = NULL;
    if (N < 0) 
    {
        return p;
    }
    p = (int *) malloc(N * sizeof(int));
    return p;
}