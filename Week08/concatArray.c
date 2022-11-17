#include <stdio.h>
#include <stdlib.h>

/*
    Cria três listas, para as duas primeiras le-se o comprimento desejado e os
    seus elementos. A terceira lista eh uma concatenacao das duas primeiras.

    Nicolas Marcelino da Silva <11/11/2022>
*/

#define tamArray 20
typedef struct lista 
{
    int qtd;
    int num[tamArray];
} Lista;

/// Cria uma lista de inteiros de tamanho 20.
Lista* CriaLista();

/// Le o comprimento e elementos de duas listas e as concatena em uma terceira
/// lista. Caso nao seja possivel concatenar as duas listas (por falta de
/// espaco no vetor), retorna um ponteiro Lista* NULL.
Lista* Concatenar(Lista* li_1, Lista* li_2);

/// Insere um novo inteiro na lista.
int InsereLista(Lista* li, int n);

/// Mostra os elementos da lista.
void PrintaLista(Lista* li);

/// Libera a memoria usada por uma lista.
void FreeList(Lista* li);

void main() 
{
    int num, tam1, tam2;
    Lista *li3 = NULL, *li1 = NULL, *li2 = NULL;
    li1 = CriaLista();
    li2 = CriaLista();

    li3 = Concatenar(li1, li2);

    PrintaLista(li3);

    FreeList(li1);
    FreeList(li2);
    FreeList(li3);
}

Lista* CriaLista() 
{
    Lista* li;
    li = (Lista *) malloc(sizeof(Lista));

    if (li != NULL) 
    {
        li->qtd = 0;
    }
    return li;
}

Lista* Concatenar(Lista* li_1, Lista* li_2) 
{
    int tam1, tam2, num;
    Lista* li_3 = NULL;
    scanf("%d%d", &tam1, &tam2);
    for (int i = 0; i < tam1; i++) 
    {
        scanf("%d", &num);
        InsereLista(li_1, num);
    }
    for (int i = 0; i < tam2; i++) 
    {
        scanf("%d", &num);
        InsereLista(li_2, num);
    }
    if (tam1 + tam2 > 20) 
    {
        printf("As listas são grandes demais para serem concatenadas.\n");
    } else 
    {
        li_3 = CriaLista();
        for (int i = 0; i < tam1; i++) 
        {
            InsereLista(li_3, li_1->num[i]);
        }
        for (int i = 0; i < tam2; i++) 
        {
            InsereLista(li_3, li_2->num[i]);
        }
    }
    return li_3;
}

int InsereLista(Lista* li, int n) 
{
    // Se houver problema na criacao da lista, retorna 0.
    if (li == NULL) 
    {
        return 0;    
    } 
    // Se a lista estiver cheia, retorna 0. Senao, adiciona o numero na lista e
    // aumenta li->qtd em 1.
    if (li->qtd == tamArray) 
    {
        return 0;
    } else 
    {
        li->num[li->qtd] = n;
        li->qtd++;
        return 1;
    }   
}

void PrintaLista(Lista* li) 
{
    for (int i = 0; i < li->qtd; i++) 
    {
        printf("%d ", li->num[i]);
    }
}

void FreeList(Lista* li) 
{
    free(li);
}