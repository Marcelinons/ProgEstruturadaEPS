#include <stdio.h>
#include <stdlib.h>

/* EP07_03
 *
 * Reads a positive n from the keyboard; reads a array of ints >= 2; prints
 * the array.
 * 
 * NicolasMSilva <03/11/22>
*/

/// @brief Reads an int n from the keyboard. If n < 0, shows error message and
/// asks for new input.
/// @return Positive integer.
int ReadPosNum();

/// @brief Reads an int n from the keyboard until n >= 2.
/// @return Integer greater than 2.
int GetTPlus();

/// @brief Reads an array of n ints.
/// @param n Number of elements;
/// @param vet Pointer to the first element of the array;
void ReadArray(int n, int *vet);

/// @brief Prints an array of n ints.
/// @param n Number of elements;
/// @param vet Pointer to the first element of the array;
void PrintArray(int n, int *vet);

void main () 
{
    int n, *vet = NULL;

    n = ReadPosNum();

    vet = (int *) malloc(n * sizeof(int));

    // All the elements of this array are ints greater than 2.
    ReadArray(n, vet);
    PrintArray(n, vet);

    free(vet);
    vet = NULL;
}

int ReadPosNum() 
{
    int n = -1;
    while (n < 0) 
    {
        scanf("%d", &n);
        if (n < 0) 
        {
            //printf("N must be positive!\n");
            printf("Numero deve ser POSITIVO! Digite um numero VALIDO!!\n");
        }
    }
    return n;
}

int GetTPlus() 
{
    int n = 0;
    while (n < 2) 
    {
        scanf("%d", &n);
        if (n < 2) 
        {
            //printf("N must be greater than 2!\n");
            printf("Digite um numero >=2!\n");
        }
    }
    return n;
}

void ReadArray(int n, int *vet) 
{
    for (int i = 0; i < n; i++) 
    {
        *(vet + i) = GetTPlus();
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