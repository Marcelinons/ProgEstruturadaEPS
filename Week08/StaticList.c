#include "StaticList.h"

List* CreateList() {
    List *li = NULL;
    li = (List *) malloc(sizeof(List));
    if (li != NULL) {
        li->qtd = 0;
    } else {
        printf("ERROR -> CreateList: could not create the list. Please, check"
            " your memory usage.\n");
    }
    return li;
}

int InsertNewElem(List *li, int n) {
    if (li == NULL) {
        printf("ERROR -> InsertNewElem: the pointer to the list is NULL.\n");
        return 0;
    } else { 
        if (li->qtd == arraySize) {
            printf("ERROR -> InsertNewElem: list is already full.");
            return 0;
        } else {
            li->num[li->qtd] = n;
            li->qtd++;
            return 1;
        }
    }
}

void FreeMemory(List *li) {
    if (li != NULL) {
        free(li);
    } else {
        printf("ERROR -> FreeMemory: the pointer to the list is NULL.\n");
    }
}

void PrintList(List *li) {
    if (li != NULL) {
        for (int i = 0; i < li->qtd; i++) {
            printf("%d ", li->num[i]);
        }
        printf("\n");
    } else {
        printf("ERROR -> PrintList: the pointer to the list is NULL.\n");
    }
}

List* ConcatLists(List *li1, List *li2) {
    List* liConcat = NULL;
    liConcat = CreateList();
    if (li1 == NULL || li2 == NULL) {
        printf("ERROR -> ConcatLists: one or two lists' pointers are NULL.\n");
    } else {
        if (li1->qtd + li2->qtd > 20) {
            printf("ERROR -> ConcatLists: the total elements of the lists must"
                " be 20 at most.\n");
        } else {
            if (liConcat != NULL) {
                for (int i = 0; i < li1->qtd; i++) {
                    InsertNewElem(liConcat, li1->num[i]);
                }
                for (int i = 0; i < li2->qtd; i++) {
                    InsertNewElem(liConcat, li2->num[i]);
                }
            } else {
                printf("ERROR -> ConcatLists: there was an error while creating"
                    " the third list.\n");
            }
        }
    }
    return liConcat;
}

int RemoveFirstN(List *li, int n) {
    if (li == NULL || li->qtd == 0) {
        printf("ERROR -> RemoveFirstN: the list is either NULL or it is" 
            " empty.\n");
        return 0;
    }
    do {
        for (int i = 0; i < li->qtd - 1; i++) {
            li->num[i] = li->num[i+1];
        }
        li->qtd--;
        n--;
    } while (n > 0);
    return 1;
}

int SwitchInts(List* li, int n1, int n2) {
    int aux;
    if (li == NULL) {
        printf("ERROR -> SwitchInts: the pointer to the list is NULL.\n");
        return 0;
    }
    for (int i = 0; i < li->qtd; i++) {
        if (li->num[i] == n1) {
            for (int j = 0; j < li->qtd; j++) {
                if (li->num[j] == n2) {
                    aux = li->num[i];
                    li->num[i] = li->num[j];
                    li->num[j] = aux;
                    return 1;
                }
            }
        }
    }
    printf("ERROR -> SwitchInts: N1 or N2 (or both) are not on the list.\n");
    return 0;
}

int RemoveFromBeginning(List *li) {
    if (li == NULL) {
        printf("ERROR -> RemoveFromBeginning: the pointer to the list"
        " is NULL.\n");
        return 0;
    } else if (li->qtd == 0) {
        printf("ERROR -> RemoveFromBeginning: the list is already empty.\n");
        return 0;
    } else {
        for (int i = 0; i < li->qtd-1; i++) {
            li->num[i] = li->num[i+1];
        }
        li->qtd--;
        return 1;
    }
}

int RemoveFromEnd(List *li) {
    if (li == NULL) {
        printf("ERROR -> RemoveFromEnd: the pointer to the list is NULL.\n");
        return 0;
    } else if (li->qtd == 0) {
        printf("ERROR -> RemoveFromEnd: the list is already empty.\n");
        return 0;
    } else {
        li->qtd--;
        return 1;
    }
}

int SizeOfList(List *li) {
    if (li == NULL) {
        printf("ERROR -> SizeOfList: the pointer to the list is NULL.\n");
        return -1;
    } else {
        return li->qtd;
    }
}

int InsertNewElemBeginning(List *li, int n) {
    if (li == NULL) {
        printf("ERROR -> InsertNewElemBeginning: the pointer to the list is"
            " NULL.\n");
        return 0;
    } else {
        if (li->qtd == arraySize) {
            printf("ERROR -> InsertNewElemBeginning: the list is already" 
                " full.\n");
            return 0;
        } else {
            for (int i = 0; i < li->qtd-1; i++) {
                li->num[i+1] = li->num[i];
            }
            li->num[0] = n;
            li->qtd++;
            return 1;
        }
    }
}

int Remove(List *li, int n) {
    int i = 0, k;
    if (li == NULL) {
        printf("ERROR -> Remove: the pointer to the list is NULL.\n");
        return 0;
    }
    if (li->qtd == 0) {
        printf("ERROR -> Remove: the list is already empty.\n");
        return 0;
    } else {
        // Finding the index of the first appearance of n.
        while (i < li->qtd && li->num[i] != n) {
            i++;
        }
        if (i == li->qtd) {
            printf("Remove: n is not in the list.\n");
            return 0;
        }
        for (k = i; k < li->qtd-1; k++) {
            li->num[k] = li->num[k+i];
        }
        li->qtd--;
        return 1;
    }
}

int GetElemInPos(List *li, int pos) {
    if (li == NULL) {
        printf("ERROR -> GetNInPos: the pointer to the list is NULL.\n");
        exit(0);
    } else if (pos < 0 || pos > li->qtd) {
        printf("ERROR -> GetNInPos: pos must be larger than 0 and smaller than"
        " the size of the list.\n");
        exit(0);
    } else {
        return li->num[pos-1];
    }
}

int GetPosOfElem(List *li, int elem) {
    int i = 0;
    if (li == NULL) {
        printf("ERROR -> GetPosOfElem: the pointer to the list is NULL.\n");
        return -1;
    } else {
        while (i < li->qtd && li->num[i] != elem) {
            i++;
        }
        if (i == li->qtd) {
            printf("GetPosOfElem: %d is not in the list.\n", elem);
            return -1;
        }
        return i+1;
    }
}

int BubbleSort(List *list) {
    int i = 0, run = 0, n = list->qtd, aux;
    if (list == NULL) {
        return 0;
    }
    do {
        run = 0;
        for (i = 0; i < n-1; i++) {
            if (list->num[i] > list->num[i+1]) {
                aux = list->num[i];
                list->num[i] = list->num[i+1];
                list->num[i+1] = aux;
                run = 1;
            }
        }
        n--;
    } while (run);
    return 1;
}

int SelectionSort(List *list) {
    int i, j, aux, swap, largPos, largest;
    if (list == NULL) {
        return 0;
    }
    for (i = 0; i < list->qtd-1; i++) {
        swap = 0;
        largest = list->num[i];
        for (j = i+1; j < list->qtd; j++) {
            if (largest > list->num[j]) {
                largest = list->num[j];
                swap = 1;
                largPos = j;
            }
        }
        if (swap) {
            aux = list->num[i];
            list->num[i] = list->num[largPos];
            list->num[largPos] = aux;
        }
    }
    return 1;
}

int InsertionSort(List *list) {
    int i, j, actual;
    if (list == NULL) {
        return 0;
    }
    for (i = 0; i < list->qtd; i++) {
        actual = list->num[i];
        j = i;
        while (j > 0 && actual < list->num[j - 1]) {
            list->num[j] = list->num[j-1];
            j--;
        }
        list->num[j] = actual;
    }
}   