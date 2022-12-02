#include <stdio.h>
#include <stdlib.h>

/*
    Recebe do usuario o tamanho de uma fila e seus elementos. Entao remove cinco
    elementos desta fila e os adiciona a uma fila secundaria. Por fim printa
    essas duas listas e as destroi.

    Nicolas Marcelino da Silva, 11202021107, 24/11/2022
*/

struct elem {
    int num;
    struct elem *next;
};
struct fila {
    struct elem *start;
    struct elem *end;
    int qtd;
};
typedef struct fila Fila;

/// Cria uma nova fila e retorna um ponteiro para seu primeiro elemento.
Fila *CreateQueue(void);

/// Insere um novo elemento no final da fila. Retorna 1 caso a insercao seja
/// bem sucedida e 0 caso contrario.
int InsertQueue(Fila *queue, int num);

/// Destroi uma fila, liberando o espaco usado na memoria.
void DestroyQueue(Fila *queue);

/// Printa os elementos de uma fila.
void PrintQueue(Fila *queue);

/// Remove o primeiro elemento de uma dada lista e o adiciona a uma lista
/// secundaria. Retorna 1 caso o processo seja um sucesso e 0 caso contrario. 
int RemoveQueue(Fila *queue, Fila *secQueue);

int main()
{
    Fila *queue = NULL, *secQueue = NULL;
    int queueSize, num, i;

    queue = CreateQueue();
    secQueue = CreateQueue();
    if (queue == NULL || secQueue == NULL) {
        exit(0);
    }
    printf("\n----- PRIMEIRA FILA -----\n\n");

    printf("\nTamanho da fila: ");
    scanf("%d", &queueSize);
    for (i = 0; i < queueSize; i++) {
        printf(">> Insira novo numero: ");
        scanf("%d", &num);
        InsertQueue(queue, num);
    }
    printf("\n----- OUTPUTS -----\n\n");
    printf("Fila recebida: ");
    PrintQueue(queue);

    if (queue->qtd < 5) {
        printf("A lista e muito pequena para realizar o processo.\n");
    } else {
        for (i = 0; i < 5; i++) {
            RemoveQueue(queue, secQueue);
        }
        printf("Fila principal ao final: ");
        PrintQueue(queue);
        printf("Fila secundaria ao final: ");
        PrintQueue(secQueue);
    }
    
    DestroyQueue(queue);
    DestroyQueue(secQueue);
    printf("\n----- FIM DO PROGRAMA -----\n\n");
    return 0;
}

Fila *CreateQueue(void) {
    Fila *queue = NULL;
    queue = (Fila *) malloc(sizeof(Fila));
    if (queue != NULL) {
        queue->qtd = 0;
        queue->start = NULL;
        queue->end = NULL;
    }
    return queue;
}

int InsertQueue(Fila *queue, int num) {
    struct elem* node = NULL;
    struct elem* aux = NULL;
    if (queue == NULL) {
        return 0;
    }
    node = (struct elem*) malloc(sizeof(struct elem));
    if (node == NULL) {
        return 0;
    }
    node->num = num;
    node->next = NULL;
    if (queue->start == NULL) {
        queue->start = node;
    } else {
        aux = queue->start;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
    }
    queue->end = node;
    queue->qtd++;
}

void DestroyQueue(Fila *queue) {
    struct elem* node = NULL;
    if (queue == NULL) {
        return;
    }
    while (queue->start != NULL) {
        node = queue->start;
        queue->start = (queue->start)->next;
        free(node);
    }
    queue->start = NULL;
    queue->end = NULL;
    free(queue);
}

void PrintQueue(Fila *queue) {
    struct elem *node = NULL;
    int i;
    if (queue == NULL || queue->start == NULL) {
        printf("\n");
        return;
    }
    node = queue->start;
    while (node != queue->end->next) {
        printf("%d ", node->num);
        node = node->next;
    }
    printf("\n");
}

int RemoveQueue(Fila *queue, Fila *secQueue) {
    struct elem *temp = NULL;
    if (queue == NULL || secQueue == NULL) {
        return 0;
    }
    temp = queue->start;
    InsertQueue(secQueue, temp->num);
    // Caso seja o ultimo elemento da lista.
    if (queue->start == queue->end) {       
        queue->start = NULL;
        queue->end = NULL;
        free(temp);
    } else {
        queue->start = queue->start->next;
        free(temp);
    }
}
