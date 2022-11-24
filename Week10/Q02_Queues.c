#include <stdio.h>
#include <stdlib.h>

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
int InsertEnd(Fila *queue, int num);

/// Destroi uma fila, liberando o espaco usado na memoria.
void DestroyQueue(Fila *queue);

/// Printa os elementos de uma fila.
void PrintQueue(Fila *queue);

int main()
{
    Fila *queue = NULL;
    int queueSize, num, i;

    queue = CreateQueue();
    if (queue == NULL) {
        exit(0);
    }
    printf("Tamanho da lista: ");
    scanf("%d", &queueSize);
    for (i = 0; i < queueSize; i++) {
        printf("\nInsira novo numero: ");
        scanf("%d", &num);
        InsertEnd(queue, num);
    }
    PrintQueue(queue);

    DestroyQueue(queue);
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

int InsertEnd(Fila *queue, int num) {
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
    free(queue);
}

void PrintQueue(Fila *queue) {
    struct elem *node = NULL;
    int i;
    if (queue == NULL) {
        return;
    }
    node = queue->start;
    while (node != queue->end->next) {
        printf("%d ", node->num);
        node = node->next;
    }
    printf("\n");
}
