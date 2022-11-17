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

int InserNewElemBeginning(List *li, int n) {
    if (li == NULL) {
        return 0;
    } else {
        Elem *node = NULL;
        node = (Elem *) malloc(sizeof(Elem));
        if (node == NULL) {
            return 0;
        } else {
            node->num = n;
            node->next = *li;
            *li = node;
        }
    }
}

int InsertNewElem(List *li, int n) {
    // Checks if its possible to insert a new element.
    if (li == NULL) {
        return 0;
    }
    Elem *node = NULL;
    node = (Elem *) malloc(sizeof(Elem));
    if (node == NULL) {
        return 0;
    }
    node->num = n;
    node->next = NULL;
    // If the list is empty, the last element is also the first.
    if (*li == NULL) {
        *li = node;
    } else {
        // Runs through the list searching for its last element.
        Elem *aux;
        aux = *li;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        // When it finds the last element of the list, set its pointer to the
        // newly created element.
        aux->next = node;
    }
    return 1;
}

int GetElemInPos(List *li, int pos) {
    if (li == NULL || pos < 0) {
        exit(0);
    }
    Elem *node = NULL;
    node = *li;

    int i = 1, resp = 0;
    while (node != NULL && i < pos) {
        node = node->next;
        i++;
    }
    if (node == NULL) {
        exit(0);
    } else {
        resp = node->num;
        return resp;
    }
}

float MeanFFive(List *li) {
    int sum = 0, i = 0;
    if (li == NULL) {
        exit(0);
    }
    for (i = 0; i < 5; i++) {
        sum += GetElemInPos(li, i+1);
    }
    return sum/(float)5;
}

void Head(List *li) {
    int i = 0;
    if (li == NULL) {
        exit(0);
    }
    for (i = 0; i < 5; i++) {
        printf("%d ", GetElemInPos(li, i+1));
    }
    printf("\n");
}

int CountPairElems(List *li) {
    int i, count = 0, elem;
    if (li == NULL) {
        exit(0);
    }
    for (i = 0; i < 5; i++) {
        elem = GetElemInPos(li, i+1);
        if (elem%2 == 0) {
            count++;
        }
    }
    return count;
}

int LargestAmongFFive(List *li, int *largPos) {
    int i, largest, elem;
    if (li == NULL) {
        exit(0);
    }
    for (i = 0; i < 5; i++) {
        elem = GetElemInPos(li, i+1);
        if (i == 0) {
            largest = elem;
        } else {
            if (elem > largest) {
                largest = elem;
                *largPos = i+1;
            }
        }
    }
    return largest;
}

int SumFFive(List *li) {
    int i, sum = 0, elem;
    if (li == NULL) {
        exit(0);
    } else {
        for (i = 0; i < 5; i++) {
            elem = GetElemInPos(li, i+1);
            sum += elem;
        }
    }
    return sum;
}
