#include <stdio.h>
#include <stdlib.h>

/*
    Reads the elements of a 5 int list and a int N. Then, removes the first N 
    elements of the list.

    Nicolas Marcelino da Silva <12/11/2022>
*/

#define arraySize 5
typedef struct list 
{
    int qtd;
    int num[arraySize];
} List;

/// @brief Creates a list out of the List struct.
List* CreateList();

/// @brief Prints the elements of a given list.
/// @param li Pointer to a List list.
int PrintList(List *li);

/// @brief Inserts a new number onto a list. The new number will occupy the
/// first available position. 
/// @param li Pointer to a List list.
/// @param n Integer which will be inserted onto the list.
/// @return 0 if the pointer is null or if the list is full. 1 otherwise. 
int InsertNum(List *li, int n);

/// @brief Free the allocated memory used by the list.
/// @param li Pointer to a List list.
int FreeList(List *li);

/// @brief Removes the first N elements of a given static list.
/// @param li Pointer to a list of type List.
/// @param N Quantity of numbers which will be removed, starting on the
/// beginning of the list.
/// @return 1 if the removal is successful. 0 otherwise.
int RemoveFirstN(List *li, int N);

void main() 
{
    List* li = NULL;
    int num;
    li = CreateList();
    // Read the elements of the 5 element array.
    for (int i = 0; i < 5; i++) 
    {
        scanf("%d", &num);
        InsertNum(li, num);
    }
    
    printf("Before: ");
    PrintList(li);
    
    // Will remove the first 3 elements of the list.
    RemoveFirstN(li, 3);
    printf("After: ");
    PrintList(li);
    
    FreeList(li);
}

List* CreateList() 
{
    List* li = NULL;
    li = (List *) malloc(sizeof(List));
    if (li != NULL) 
    {
        li->qtd = 0;
    }
    return li;
}

int PrintList(List *li) 
{   
    if (li == NULL) 
    {
        return 0;
    } else {
        for (int i = 0; i < li->qtd; i++) 
        {
            printf("%d ", li->num[i]);
        }
        printf("\n");
        return 1;
    }
}

int InsertNum(List *li, int n) 
{
    if (li == NULL) 
    {
        return 0;
    }
    if (li->qtd == arraySize) 
    {
        return 0;
    } else 
    {
        li->num[li->qtd] = n;
        li->qtd++;
        return 1;
    }
}

int FreeList(List *li) 
{
    if (li == NULL) 
    {
        return 0;
    } else {
        free(li);    
        return 1;
    }
}

int RemoveFirstN(List *li, int N) 
{
    if (li == NULL || li->qtd == 0) 
    {
        return 0;
    } else 
    {
        do 
        {
            for (int i = 0; i < li->qtd - 1; i++) 
            {
                li->num[i] = li->num[i+1];
            }
            li->qtd--;
            N--;
        } while (N > 0);
    }
}