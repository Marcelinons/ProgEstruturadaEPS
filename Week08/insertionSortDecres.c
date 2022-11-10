#include <stdio.h>
#include <stdlib.h>

/*  
    EP03 - Semana 08

    Versao alternativa do algoritmo de ordenacao por insercao mostrado em aula.
    Nesta versao, o algoritmo ordena os elementos de um array de maneira 
    decrescente, inves de crescente.

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

/// Ordena os elementos de um array de n inteiros usando algoritmo de insercao.
/// n -> Tamanho do array.
/// *vet -> Pointer para o primeiro elemento do vetor.
void InsertSortDecres(int n, int *vet);

void main()
{
    int n, *vet = NULL;
    scanf("%d", &n);
    vet = CreateReadArray(n);
    InsertSortDecres(n, vet);
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

void InsertSortDecres(int n, int *vet) 
{
    int j, atual;
    // Percorre cada elemento do array.
    for (int i = 0; i < n; i++) 
    {
        // Salva o elemento da posicao i do vetor, pois no loop while o
        // o elemento da posicao i sera alterado.
        atual = vet[i];
        j = i;
        // Move os elementos à esquerda de atual para a direita enquanto houver
        // elementos maiores do que ele à esquerda.
        while (j > 0 && atual > vet[j-1]) 
        {
            vet[j] = vet[j-1];
            j--;
        }
        // Atualiza a posicao do atual (antigo elemento do indice i).
        vet[j] = atual;
    }
}