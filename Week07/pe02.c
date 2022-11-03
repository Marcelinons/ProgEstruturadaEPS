#include <stdio.h>
#include <stdlib.h>

/* EP07_02
 *
 * Reads from the keyboard a the size n of a int array; creates a dynamic array
 * and reads from the keyboard its values; prints the array.
 * 
 * NicolasMSilva <03/11/22> 
*/


/// @brief Reads a array of n ints.
/// @param n Number of elements;
/// @param vet Pointer to the first element of the array
void ReadArray(int n, int *vet);

/// @brief Prints the n elements of a int array;
/// @param n Number of elements;
/// @param vet Pointer to the first element of the array;
void PrintArray(int n, int *vet);

void main () 
{
    int n, *vet = NULL;
    scanf("%d", &n);
    // Create a dynamic array
    vet = (int *) malloc(n * sizeof(int));

    // Read and print the array;
    ReadArray(n, vet);
    PrintArray(n, vet);

    // Free the allocated memory and setting the pointer to a NULL
    free(vet);
    vet = NULL;
}

void ReadArray(int n, int *vet) 
{
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", vet + i);
    }
}

void PrintArray(int n, int *vet) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *(vet + i));
    }
    printf("\n");
}