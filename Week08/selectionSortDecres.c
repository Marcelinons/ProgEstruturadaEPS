#include <stdio.h>
#include <stdlib.h>

/*
    EP02 - Semana 08

    Versao alternativa do algoritmo de ordenacao por selecao mostrado nas aulas.
    Nesta versao, o algoritmo ordena o array em ordem decrescente, inves de
    crescente.

    Nicolas Marcelino da Silva <10/11/22>
*/

/// Cria um array dinamicamente alocado de n inteiros e le do usuario cada 
/// elemento.
/// n -> Tamanho desejado para o array.
/// retorna: Ponteiro para o primeiro elemento do array.
int* CreateReadArray(int n);

/// Imprime cada um dos n inteiros dentro um array.
/// n -> Tamanho do array.
/// *vet -> Pointer para o primeiro elemento do vetor.
void PrintArray(int n, int *vet);

/// Ordena um vetor de n inteiros em ordem decrescente usando um algoritmo de
/// selecao.
/// n -> Tamanho do vetor.
/// *vet -> Ponteiro para o primeiro elemento do array.
void SelectSortDecre(int n, int *vet);

void main() 
{
    int n, *vet = NULL;
    scanf("%d", &n);
    vet = CreateReadArray(n);
    SelectSortDecre(n, vet);
    PrintArray(n, vet);

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

void PrintArray(int n, int *vet) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *(vet + i));
    }
    printf("\n");
}

void SelectSortDecre(int n, int *vet) 
{
    int aux;
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = i+1; j < n; j++) 
        {
            if (vet[i] < vet[j]) 
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}