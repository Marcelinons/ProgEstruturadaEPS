#include <stdio.h>
#include <stdlib.h>

#define arrSize 5
typedef struct list {
    int qtd;
    int num[arrSize];
} List;

List* CreateList();

void FreeMemory(List* li);

void main() {

}

List* CreateList() 
{
    List *li = NULL;
    li = (List *) malloc(sizeof(List));
    if (li != NULL) 
    {
        li->qtd = 0;
    }
    return li;
}

void FreeMemory(List *li) 
{
    free(li);
}