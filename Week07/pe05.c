#include <stdio.h>
#include <stdlib.h>

/* EP07_05

    Receives the size N of a array; creates a dynamic int array of N elements;
    Reads the values of the array from the keyboard;

    NicolasMSilva <04/11/2022>
*/

/// @brief Returns a pointer to the first element of a dynamic int array.
/// @param n Size of the array;
/// @return Int pointer to the first element of the array.
int* GetVet(int n);

int main (void) 
{
    int n;
    scanf("%d", &n);

    int *vet = GetVet(n);

    for (int i = 0; i<n; i++) 
    {
        printf("%d ", *(vet + i));
    } 

    free(vet);
    vet = NULL;
}

int* GetVet(int n) 
{
    int *p = NULL;
    p = (int *) malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", p + i);
    }
    
    return p;
}