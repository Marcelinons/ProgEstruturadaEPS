#include <stdio.h>
#include <stdlib.h>

#define arrSize 20
struct list 
{
    int qtd;
    int num[arrSize];
};
typedef struct list List;

/* Cria uma lista a partir da struct list e retorna um ponteiro para ela. */
List *CreateList(void);

/* Insere um novo elemento no final da lista. */
int InsertEnd(List *list, int num);

/* Destroi uma lista e libera a memoria por ela usada. */
void DestroyList(List *list);

/* Printa os elementos de uma lista. */
void Print(List *list);

/* Ordena os valores de uma lista do maior para o menor usando o algoritmo 
selection sort.
*/
int SelectionSort(List *list);

void main() 
{
    List *list = NULL;
    int num;
    list = CreateList();
    if (list != NULL) 
        printf("-> CreateList: lista criada.\n");
    for (int i = 0; i < 5; i++) 
    {
        printf("Entre com novo valor: ");
        scanf("%d", &num);
        if (InsertEnd(list, num))
            printf("-> InsertEnd: elemento inserido.\n");
    }
    printf("\nLista: ");
    Print(list);
    printf("\nLista ordenada: ");
    SelectionSort(list);
    Print(list);
    DestroyList(list);
}

List *CreateList(void) 
{
    List *list = NULL;
    list = (List *) malloc(sizeof(List));
    if (list != NULL) 
    {
        list->qtd = 0;
    }
    return list;
}

int InsertEnd(List *list, int num) 
{
    if (list == NULL) 
        return 0;
    if (list->qtd != arrSize) 
    {
        list->num[list->qtd] = num;
        list->qtd++;
    } 
    else
        return 0;
    return 1;
}

void DestroyList(List *list) 
{
    free(list);
    printf("-> DestroyList: lista destruida.\n");
}

void Print(List *list) {
    if (list == NULL) 
        return;
    for (int i = 0; i < list->qtd; i++) 
    {
        printf("%d ", list->num[i]);
    }
    printf("\n");
}

int SelectionSort(List *list) 
{
    int maior, maiorPos, swap, aux;
    if (list == NULL) 
        return 0;
    for (int i = 0; i < list->qtd-1; i++) 
    {
        swap = 0;
        /* Encontra o maior valor da lista, considerando os elemento da posicao
        i ate o fim.
        */
        for (int j = i+1; j < list->qtd; j++) 
        {
            maior = list->num[i];
            if (list->num[j] > maior) 
            {   
                maior = list->num[j];
                maiorPos = j;
                swap = 1;
            } 
        }
        // Se for encontrado um elemento maior que i, realiza a troca.
        if (swap) 
        {
            aux = list->num[maiorPos];
            list->num[maiorPos] = list->num[i];
            list->num[i] = aux;
        }
    }
    return 1;
}