#include <stdio.h>
#include <stdlib.h>

/* 
    Do the same as pe06.c, but using a linked list.
*/

struct elem {
    float num;
    struct elem *next;
};

typedef struct elem Elem;
typedef struct elem *List;

/// Creates a new list.
List* CreateList();

/// Destroy a list, freeing the used memory.
void DestroyList(List *li);

/// Inserts a new float num into the end of the given list. 
/// Retuns 1 if insertion is successful and 0 otherwise.
int InsertFloatEnd(List *li, float num);

/// Prints the elements of a given list.
void PrintList(List *li);

/// Inserts N new floats into the end of the given list. Returns 1 if all the
/// ints are inserted, 0 otherwise.
int ReadNFloats(List *li, int n);

/// Sums the positive values of the given list. Also, counts the quantity of 
/// negative values.
float SumPositiveElems(List *li, int *negatives);

void main() {
    List *li = NULL;
    int pos1 = 1, pos2 = 3, negative = 0; 
    float sum = 0, sumPositive = 0;
    li = CreateList();
    printf("\n------- LIST 1 -------\n\n");
    ReadNFloats(li, 5);
    printf("\n------- OUTPUTS -------\n\n");
    printf("List elements: ");
    PrintList(li);
    sumPositive = SumPositiveElems(li, &negative);
    printf("Sum of positive elements = %.2f\n", sumPositive);
    printf("Number of negative elements = %d\n", negative);
    DestroyList(li);
    printf("\n------- END OF PROGRAM -------\n");
}

List* CreateList() {
    List *li = NULL;
    li = (List *) malloc(sizeof(List));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

void DestroyList(List *li) {
    if (li != NULL) {
        Elem *node = NULL;
        while ((*li) != NULL) {
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        free(li);
    }
}

int InsertFloatEnd(List* li, float num) {
    Elem *node = NULL, *aux = NULL;
    if (li == NULL) {
        return 0;
    }
    node->num = num;
    node->next = NULL;
    if (*li == NULL) {
        *li = node;
    } else {
        aux = *li;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
    } 
    return 1;
}

void PrintList(List *li) {
    Elem *node = NULL;
    if (li == NULL) {
        return;
    }
    node = *li;
    while (node != NULL) {
        printf("%.2f ", node->num);
        node = node->next;
    }
    printf("\n");
}

int ReadNFloats(List *li, int n) {
    Elem *node = NULL, *aux = NULL;
    float num = 0;
    if (li == NULL) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        node = (Elem *) malloc(sizeof(Elem));
        if (node == NULL) {
            return 0;
        }
        printf("Insert new int: ");
        scanf("%f", &num);
        node->num = num;
        node->next = NULL;
        if (*li == NULL) {
            *li = node;
        } else {
            aux = *li;
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = node;
        }
    }
    return 1;
}

float SumPositiveElems(List *li, int *negative) {
    Elem *node = NULL;
    float sum = 0;
    if (li == NULL) {
        printf("ERROR AT SumPositiveElems -> POINTER TO LIST IS NULL.\n");
        exit(0);
    }
    node = *li;
    while(node != NULL) {
        if (node->num >= 0) {
            sum += node->num;
        } else {
            *negative += 1;
        }
        node = node->next;
    }
    return sum;
}