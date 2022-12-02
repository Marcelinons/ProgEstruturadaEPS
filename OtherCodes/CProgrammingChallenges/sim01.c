#include <stdio.h>
#include <stdlib.h>

struct elem {
    int num;
    struct elem *next;
};
typedef struct elem Node;

/// Creates a new list and returns a double pointer to it.
Node **CreateList(void);

/// Destroys the list and free the used memory space.
void DestroyList(Node **list);

/// Inserts a new element at the end of the list. Returns 1 if successful and 0
/// otherwise.
int InsertEnd(Node **list, int n);

/// Inserts a new element at the beginning of the list. Returns 1 if successful
/// and 0 otherwise.
int InsertBeginning(Node **list, int n);

/// Prints the elements of the list.
void Print(Node **list);

/// Removes the first element of the list. Returns 1 if successful and 0 
/// otherwise.
int RemoveBeginning(Node **list);

/// Removes the last element of the list. Returns 1 if successful and 0 
/// otherwise.
int RemoveEnd(Node **list);

/// Sorts the list using selection sort algorithm. Returns 1 if successful and  
/// 0 otherwise. Crescent = 1: Sorts the list in crescent order; otherwise, sort
/// the list in decrescent order.
int SelectionSort(Node **list, int crescent);

/// Inserts test values in the list.
int TestInsert(Node **list);

void main() 
{
    Node **list = NULL;
    list = CreateList();
    if (list == NULL)
        exit(0);

    TestInsert(list);
    printf("Start: ");
    Print(list);
    SelectionSort(list, 1);
    printf("End:   ");
    Print(list);

    // Destroys the list and ends the program.
    DestroyList(list);
}

Node **CreateList(void) 
{
    Node **list = NULL;
    list = (Node **) malloc(sizeof(Node *));
    if (list != NULL) 
    {
        *list = NULL;
    }
    return list;
}

void DestroyList(Node **list) 
{
    Node *temp = NULL;
    if (list == NULL)
        return;
    
    while (*list != NULL) 
    {
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    free(list);
}

int InsertEnd(Node **list, int n) 
{
    Node *temp = NULL, *aux = NULL;
    if (list == NULL)
        return 0;
    
    temp = (Node *) malloc(sizeof(Node));
    if (temp == NULL) 
        return 0;
    
    temp->num = n;
    temp->next = NULL;
    if (*list == NULL)
        *list = temp;
    else {
        aux = *list;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = temp;
    }
    return 1;
}

int InsertBeginning(Node **list, int n) 
{
    Node *temp = NULL;
    if (list == NULL) 
        return 0;
    
    temp = (Node *) malloc(sizeof(Node));
    if (temp == NULL) 
        return 0;
    
    temp->num = n;
    temp->next = NULL;
    if (*list == NULL)
        *list = temp;
    else {
        temp->next = *list;
        *list = temp;
    }
}

void Print(Node **list) 
{
    Node *temp = NULL;
    if (list == NULL)
        return;
    
    temp = *list;
    while (temp != NULL) 
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

int RemoveBeginning(Node **list) 
{
    Node *temp = NULL;
    if (list == NULL || *list == NULL)
        return 0;
    
    temp = *list;
    *list = (*list)->next;
    free(temp);
    return 1;
}

int RemoveEnd(Node **list) 
{
    Node *temp = NULL, *aux = NULL;
    if (list == NULL || *list == NULL)
        return 0;
    
    // Find the last and the last but one elements of the list.
    temp = *list;
    while (temp->next != NULL) 
    {
        aux = temp;
        temp = temp->next;
    }
    // If the last element is also the first, set *list to NULL. Otherwise, set
    // aux->next to be NULL.
    if (temp == *list)
        *list = temp->next;
    else
        aux->next = NULL;
    
    free(temp);
    return 1;
}

int SelectionSort(Node **list, int crescent) 
{
    Node *current = NULL, *temp = NULL, *aux = NULL, *largest = NULL;
    Node *secTemp = NULL;
    int swap = 0;
    if (list == NULL)
        return 0;
    
    current = *list;
    while (current != NULL)
    {
        temp = current->next;
        largest = current;
        while (temp != NULL) 
        {
            // Whether the user wants to sort the list in a crescent way or not.
            if (crescent) 
            {
                if (largest->num > temp->num) 
                {
                    largest = temp;
                    swap = 1;
                }
            } 
            else 
            {
                if (largest->num < temp->num) 
                {
                    largest = temp;
                    swap = 1;
                }
            }
            
            temp = temp->next;
        }
        if (swap) 
        {
            // Find the previous element of the largest one.
            temp = *list;
            while (temp->next != largest) 
            {
                temp = temp->next;
            }
            // Whether current is the first element of the list or not.
            if (current == *list) 
            {
                aux = current->next;
                temp->next = current;
                *list = largest;
                current->next = largest->next;
                largest->next = aux;
                current = largest;
            }
            else
            {
                secTemp = *list;
                while (secTemp->next != current) 
                {
                    secTemp = secTemp->next;
                }
                secTemp->next = temp->next;
                temp->next = current;
                aux = largest->next;
                largest->next = current->next;
                current->next = aux;
                current = largest;
            }
        }
        current = current->next;
    }
    return 1;
}

int TestInsert(Node **list) {
    if (list == NULL)
        return 0;
    
    InsertEnd(list, 5);
    InsertBeginning(list, 3);
    InsertEnd(list, 9);
    InsertEnd(list, 1);
    InsertEnd(list, -4);
    InsertEnd(list, -1);
    InsertBeginning(list, 2);
    return 1;
}