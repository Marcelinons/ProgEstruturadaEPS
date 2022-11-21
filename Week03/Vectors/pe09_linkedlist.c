#include <stdio.h>
#include <stdlib.h>

/*
    Reads a list of ints where no int repeats (a list of unique elements).

    > Does the exact same thing as PE09, but this time using a dynamic linked 
    list.

    Author: Nicolas Marcelino da Silva.
*/
struct elem {
    int num;
    struct elem *next;
};
typedef struct elem Node;
typedef struct elem *List;

/// Creates a new list. Returns a pointer to the first element of the list.
List* CreateList();

/// Reads N unique elements for the list. Returns 1 is all the inserts are 
/// successful, and 0 otherwise.
int ReadNUnique(List *list, int N);

void Print(List *list);

/// Checks whether a int exists or not inside a given list. Returns 1 if yes, 0
/// if no.
int CheckExistenceInList(List *list, int num);

/// Destroys the list.
void DestroyList(List *list);

void main() {
    List *list = CreateList();
    printf("------ READING ELEMENTS ------\n\n");
    ReadNUnique(list, 5);
    printf("\n------ OUTPUT ------\n\n");
    printf("Elements of the list: ");
    Print(list);
    printf("\n------ END OF PROGRAM ------\n");
    DestroyList(list);
}

List* CreateList() {
    List *list = NULL;
    list = (List *) malloc(sizeof(List));
    if (list != NULL) {
        *list = NULL;
    }
    return list;
}

int ReadNUnique(List *list, int N) {
    Node *node = NULL, *temp = NULL;
    int num, i = 0;
    if (list == NULL) {
        return 0;
    }
    
    while(i < N) {
        printf("Insert new element: ");
        scanf("%d", &num);
        if (CheckExistenceInList(list, num)) {
            printf("ERROR: This element is already in the list.\n");
            continue;
        }
        node = (Node *) malloc(sizeof(Node));
        if (node == NULL) {
            return 0;
        }
        node->num = num;
        node->next = NULL;
        if (*list == NULL) {
            *list = node;
        } else {
            temp = *list;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
        i++;
    }
    return 1;
}

int CheckExistenceInList(List *list, int num) {
    Node *node = NULL;
    if (list == NULL) {
        exit(0);
    } else if (*list == NULL) {
        // If it is the first element of the list, then there are no equal
        // elements.
        return 0;
    }
    node = *list;
    while(node != NULL) {
        if (node->num == num) {
            return 1;
        }
        node = node->next;
    }
    if (node == NULL) {
        return 0;
    }
}

void DestroyList(List *list) {
    if (list != NULL) {
        Node *node = NULL;
        while (*list != NULL) {
            node = *list;
            *list = (*list)->next;
            free(node);
        }
        free(list);
    }
}

void Print(List *list) {
    Node *node = NULL;
    if (list == NULL) {
        return;
    }
    node = *list;
    while(node != NULL) {
        printf("%d ", node->num);
        node = node->next;
    }
    printf("\n");
    return;
}