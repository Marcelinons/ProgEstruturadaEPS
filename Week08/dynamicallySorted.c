#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} Node;

/// @brief Create a new list.
/// @return Pointer to the first element of the list.
Node** CreateList(void);

/// @brief Reads elements to the list and adds them in the list following a 
/// sort algorithm. Note that for this to work properly the existing list must
/// either be empty or already sorted from the smallest to the largest.
/// @param list Pointer to pointer to the first element of the list.
/// @param listSize Number of elements to be added to the list.
/// @return 1 if the op is successful and 0 otherwise.
int ReadSortedList(Node **list, int listSize);

/// @brief Destroys the list and frees its used space.
/// @param list Pointer to pointer to the first element of the list.
void DestroyList(Node **list);

/// @brief Prints the elements of a given list.
/// @param list Pointer to pointer to the first element of the list.
void Print(Node **list);

void main() {
    Node **list = NULL;
    int size;
    list = CreateList();
    if (list == NULL) {
        exit(0);
    }
    printf("Tamanho da lista: ");
    scanf("%d", &size);
    ReadSortedList(list, size);
    Print(list);

    DestroyList(list);
}

Node **CreateList(void) {
    Node **list = NULL;
    list = (Node **) malloc(sizeof(Node *));
    if (list != NULL) {
        *list = NULL;
    }
    return list;
}

int ReadSortedList(Node **list, int listSize) {
    Node *temp = NULL, *aux = NULL, *secAux = NULL;
    int num;
    if (list == NULL) {
        return 0;
    }
    for (int i = 0; i < listSize; i++) {
        temp = (Node *) malloc(sizeof(Node));
        if (temp == NULL) {
            return 0;
        }
        printf("Insert new element: ");
        scanf("%d", &num);
        temp->num = num;
        temp->next = NULL;
        if (*list == NULL) {
            *list = temp;
        } else {
            if (temp->num < (*list)->num) {
                temp->next = *list;
                *list = temp;
            } else {
                aux = *list;

                while (aux->next != NULL) {
                    if (temp->num >= aux->num && aux->next->num > temp->num) {
                        break;
                    }
                    aux = aux->next;
                }
                if (aux->next == NULL) {
                    aux->next = temp;
                } else {
                    secAux = aux->next;
                    aux->next = temp;
                    temp->next = secAux;
                }
            }
        }
    }
    return 1;
}

void DestroyList(Node **list) {
    Node *temp = NULL;
    if (list == NULL) {
        return;
    } else {
        while (*list != NULL) {
            temp = *list;
            *list = (*list)->next;
            free(temp);
        }
        free(list);
    }
}

void Print(Node **list) {
    Node *temp = NULL;
    if (list == NULL) {
        return;
    }
    temp = *list;
    while (temp != NULL) {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}