#include "DynamicList.h"

List* CreateList() {
    List* li;
    // Allocating memory space for the list.
    li = (List *) malloc(sizeof(List));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}


void FreeMemory(List *li) {
 
    if (li != NULL) {
        Elem *no = NULL;
        /* Runs through the list until the content of *li (a memory address) is 
        NULL (until it finds the end of the list).
        */
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->next;
            free(no);
        }
        free(li);
    }
}

int SizeofList(List *li) {
    int count = 0;
    if (li == NULL) {
        return -1;
    } else {
        // Points to the first element of the list.
        Elem *node = *li;
        while (node != NULL) {
            count++;
            node = node->next;
        }
        return count;
    }
}

int EmptyList(List *li) {
    if (li == NULL) {
        return 1;
    } else {
        if (*li == NULL) {
            return 1;
        } else {
            return 0;
        }
    }
}