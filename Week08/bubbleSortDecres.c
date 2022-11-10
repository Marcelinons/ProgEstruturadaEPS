#include <stdio.h>
#include <stdlib.h>

/*
    EP01 - Semana 08

    Versao alternativa do metodo BubbleSort apresentado em aula. Nesta versao,
    o metodo ordena o array em ordem decrescente, inves de crescente.

    Nicolas Marcelino da Silva <10/11/22>
*/

/// Cria um array de inteiros, de tamanho n, e retorna um ponteiro para o
/// primeiro elemento.
int* CreateReadArray(int n);

/// Algoritmo de ordenacao do tipo bolha. Ordena um dado array de n inteiros em
/// ordem decrescente.
void BubbleSortDecres(int n, int *vet);

/// Printa os elementos de um array de n inteiros.
void PrintArray(int n, int *vet);

void main() 
{
    int n, *vet = NULL;
    scanf("%d", &n);

    vet = CreateReadArray(n);
    BubbleSortDecres(n, vet);
    PrintArray(n, vet);
    
    // Liberar o ponteiro após o fim do programa.
    free(vet);
    vet = NULL;
}

int* CreateReadArray(int n) 
{
    int *p = NULL;
    p = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", p+i);
    }
    return p;
}

void BubbleSortDecres(int n, int *vet) 
{
    int running, aux;
    do 
    {
        running = 0;
        for (int i = 0; i < n-1; i++) 
        {
            if (vet[i] < vet[i+1]) 
            {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                running = 1; 
            }
        }
        n--;
    } while (running == 1);
}

void PrintArray(int n, int *vet) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *(vet + i));
    }
    printf("\n");
}