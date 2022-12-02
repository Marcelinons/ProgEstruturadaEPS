#include <stdio.h>
#include <stdlib.h>

// Represents a element in the queue. In this case, the element is a int.
struct elem {
    int num;
    struct elem *next;
};
typedef struct queue {
    struct elem *start;
    struct elem *end;
    int size;
} Queue;

/// @brief Creates a queue.
/// @return Pointer to a element of type struct queue. 
Queue *CreateQueue(void);

/// @brief Destroys a queue and free its used space.
/// @param queue Pointer to a struct queue.
void DestroyQueue(Queue *queue);

/// @brief Adds a new element (number) to the queue.
/// @param queue Pointer to a struct queue.
/// @param num Number to be added.
/// @return 1 if insertion is successful, 0 otherwise.
int AddToQueue(Queue *queue, int num);

/// @brief Removes a element from a queue.
/// @param queue Pointer to the queue struct.
/// @return 1 if removal is successful, 0 otherwise.
int RemoveFromQueue(Queue *queue);

/// @brief Prints the elements of a queue.
/// @param queue Pointer to the queue struct.
void PrintQueue(Queue *queue);

void main() {
    Queue *queue = CreateQueue();
    if (queue == NULL) {
        exit(0);
    }
    AddToQueue(queue, 5);
    AddToQueue(queue, 1);
    AddToQueue(queue, 3);
    AddToQueue(queue, 6); 
    printf("Queue at start: ");
    PrintQueue(queue);
    for (int i = 0; i < 2; i++)
        RemoveFromQueue(queue);
    printf("Queue at end  : ");
    PrintQueue(queue);

    DestroyQueue(queue);
}

Queue *CreateQueue(void) {
    Queue *queue = NULL;
    queue = (Queue *) malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->start = NULL;
        queue->end = NULL;
        queue->size = 0;
    }
    return queue;
}

void DestroyQueue(Queue *queue) {
    struct elem *temp = NULL;
    if (queue == NULL) {
        return;
    }
    while (queue->start != NULL) {
        temp = queue->start;
        queue->start = (queue->start)->next;
        queue->size--;
        free(temp);
    }
    queue->end = NULL;
    free(queue);
}

int AddToQueue(Queue *queue, int num) {
    struct elem *temp = NULL;
    if (queue == NULL) {
        return 0;
    }
    temp = (struct elem *) malloc(sizeof(struct elem));
    if (temp == NULL) {
        return 0;
    }
    temp->num = num;
    temp->next = NULL;
    if (queue->start == NULL)
        queue->start = queue->end = temp;
    else {
        queue->end->next = temp;
        queue->end = temp; 
    }
    queue->size++;
    return 1;
}

int RemoveFromQueue(Queue *queue) {
    struct elem *temp = NULL;
    if (queue->start == NULL) {
        return 0;
    }
    temp = queue->start;
    queue->start = queue->start->next;
    free(temp);
}

void PrintQueue(Queue *queue) {
    struct elem *temp = NULL;
    if (queue == NULL) {
        return;
    }
    temp = queue->start;
    while (temp != NULL) {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}