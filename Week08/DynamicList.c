#include "DynamicList.h"

/*
    METHODS USED TO CONTROL CHAINED LISTS.

    AUTHOR: Nicolas Marcelino da Silva.
*/

List* CreateList() {
    List* li;
    // Allocating memory space for the list.
    li = (List *) malloc(sizeof(List));
    if (li != NULL) {
        *li = NULL;
    } else {
        printf("ERROR -> CreateList: could not allocate memory to create"
            " the list.\n");
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

int InsertBeginning(List *li, int n) {
    if (li == NULL) {
        printf("ERROR -> InsertBeginning: the pointer to the list is NULL.\n");
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
    return 1;
}

int InsertEnd(List *li, int n) {
    // Checks if its possible to insert a new element.
    if (li == NULL) {
        printf("ERROR -> InsertEnd: the pointer to the list is NULL.\n");
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

float Mean(List *li) {
    int sum = 0, elementsCount = 0;
    Elem *node = NULL;
    if (li == NULL) {
        printf("ERROR -> Mean: the pointer to the list is NULL.\n");
        exit(0);
    }
    node = *li;
    while (node != NULL) {
        sum += node->num;
        node = node->next;
        elementsCount++;
    }
    return sum/(float)elementsCount;
}

void Head(List *li) {
    int i = 1;
    Elem *node = NULL;
    if (li == NULL) {
        printf("ERROR -> Head: the pointer to the list is NULL.\n");
        return;
    }
    node = *li;
    while (node != NULL && i < 6) {
        printf("%d ", node->num);
        node = node->next;
        i++;
    }
    printf("\n");
}

int CountPairElems(List *li) {
    int count = 0;
    Elem *node = NULL;

    if (li == NULL) {
        printf("ERROR -> CountPairElems: the pointer to the list is NULL.\n");
        exit(0);
    }
    node = *li;
    while (node != NULL) {
        if (node->num%2 == 0) {
            count++;
        }
        node = node->next;
    }
    return count;
}

int Largest(List *li, int *largPos) {
    int i = 1, largest;
    Elem *node = NULL;
    
    if (li == NULL) {
        printf("ERROR -> LargestAmongFFive: the pointer to the list is NULL.\n");
        exit(0);
    }
    node = *li;
    while (node != NULL) {
        if (i == 1) {
            largest = node->num;
        } else {
            if (node->num > largest) {
                largest = node->num;
                *largPos = i;
            }
        }
        node = node->next;
        i++;
    }
    return largest;
}

int Sum(List *li) {
    int sum = 0;
    Elem *node = NULL;
    
    if (li == NULL) {
        printf("ERROR -> Sum: the pointer to the list is NULL.\n");
        exit(0);
    } else {
        node = *li;
        while (node != NULL) {
            sum += node->num;
            node = node->next;
        }
    }
    return sum;
}

void Calculations(List *li) {
    int i = 1, sum = 0, largest, largestPos, elem, pairCount = 0;
    float mean;
    Elem *node = NULL;
    
    if (li == NULL) {
        printf("ERROR -> Calculations: the pointer to the list is NULL.\n");
        exit(0);
    } else {
        node = *li;
        while (node != NULL) {
            elem = node->num;
            sum += elem;
            if (elem % 2 == 0) {
                pairCount++;
            }
            if (i == 1) {
                largest = elem;
            } else {
                if (elem > largest) {
                    largest = elem;
                    largestPos = i;
                }
            }
            node = node->next;
            i++;
        }
    }
    // Print results.
    printf("a) Qtd. pares: %d\n", pairCount);
    printf("b) Media: %.2f\n", sum/(float)5);
    printf("c) Maior: %d\n", largest);
    printf("d) Posicao (Maior): %d\n", largestPos);
    printf("e) Soma: %d\n", sum);
}

int EqualLists(List *li_1, List *li_2) {
    Elem *node1 = NULL, *node2 = NULL;

    if (li_1 == NULL || li_2 == NULL) {
        printf("ERROR -> AreTheyEqual: one or two pointers are NULL.\n");
        exit(0);
    }
    node1 = *li_1;
    node2 = *li_2;
    while (node1 != NULL && node2 != NULL) {
        printf("%d ", node1->num);
        
        if (node1->num != node2->num) {
            return 0;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    return 1;
}

int RemoveFirstN(List *li, int n) {
    int i = 0;
    Elem *node = NULL;
    if (li == NULL) {
        printf("ERROR -> RemoveFirstN: pointer to the list is NULL.\n");
        return 0;
    }
    // Repeats N times.
    for (i = 0; i < n; i++) {
        // Get the first element of the list.
        node = *li;
        // Move *li pointer to the next element.
        *li = node->next;
        // Free the previous element.
        free(node);
    }
    return 1;
}

int RemoveLastN(List *li, int n) {
    Elem *node = NULL, *previous = NULL;
    if (li == NULL || *li == NULL) {
        printf("ERROR -> RemoveLastN: pointer to the list is NULL.\n");
        return 0;
    }
    // Repeat N times or while the start of the list (*li) is not NULL.
    while (*li != NULL && n > 0) {
        // First element of the list.
        node = *li;
        if (node == NULL) {
            break;
        }
        // Find the last element and the last but one elements of the list.
        while (node->next != NULL) {
            previous = node;
            node = node->next;
        }
        if (node == *li) {
            // If the last element is the first, then set the *li to NULL.
            *li = node->next;
        } else {
            // Otherwise, set the last but one element's next component to NULL.
            previous->next = NULL;
        }
        // Release the used memory of the last node.
        free(node);
        n--;
    }
    return 1;
}

void SwitchElems(List* li, int pos1, int pos2) {
    Elem *node1 = NULL, *node2 = NULL, *ant1 = NULL, *ant2 = NULL, *aux = NULL;
    int i = 1;
    if (li == NULL || pos1 < 1 || pos2 < 1 || pos1 == pos2) {
        return;
    }
    node1 = *li;
    node2 = *li;
    while (node1->next != NULL && i < pos1) {
        ant1 = node1;
        node1 = node1->next;
        i++;
    }
    i = 1;
    while (node2->next != NULL && i < pos2) {
        ant2 = node2;
        node2 = node2->next;
        i++;
    }
    if (ant1 == NULL) {
        *li = node2;
    } else { 
        ant1->next = node2;
    }

    if (ant2 == NULL) {
        *li = node1;
    } else {
        ant2->next = node1;
    }
    aux = node1->next;
    node1->next = node2->next;
    node2->next = aux;
    return;
}

void Sublists(List *li, int pos, List *sub1, List *sub2) {
    int i = 0;
    Elem *node = NULL, *node1 = NULL, *node2 = NULL, *aux = NULL;
    if (li == NULL || sub1 == NULL || sub2 == NULL || pos < 0) {
        return;
    }
    node = *li;
    while (node != NULL) {
        if (i < pos) {
            node1 = (Elem *) malloc(sizeof(Elem));
            if (node1 == NULL) {
                return;
            }
            node1->num = node->num;
            node1->next = NULL;
            if (*sub1 == NULL) {
                *sub1 = node1;
            } else {
                aux = *sub1;
                while (aux->next != NULL) {
                    aux = aux->next;
                }
                aux->next = node1;
            }
        } else {
            node2 = (Elem *) malloc(sizeof(Elem));
            if (node2 == NULL) {
                return;
            }
            node2->num = node->num;
            node2->next = NULL;
            if (*sub2 == NULL) {
                *sub2 = node2;
            } else {
                aux = *sub2;
                while (aux->next != NULL) {
                    aux = aux->next;
                }
                aux->next = node2;
            }
        }
        node = node->next;
        i++;
    }
    return;
}

void InvertElems(List *li, List *secList) {
    Elem *node = NULL, *secNode = NULL, *aux = NULL;
    if (li == NULL || secList == NULL) {
        printf("The pointer to some of the lists is null.\n");
        return;
    }
    node = *li;
    // Runs through the list.
    while (node != NULL) {
        // Add a element to the beginning of the sec list.
        secNode = (Elem *) malloc(sizeof(Elem));
        if (secNode == NULL) {
            return;
        }
        secNode->num = node->num;
        secNode->next = *secList;
        if (*secList == NULL) {
            *secList = secNode;
        } else {
            *secList = secNode;
        }
        node = node->next;       
    }
}

void GetPairs(List *li, List *secList) {
    Elem *node = NULL, *node1 = NULL, *aux = NULL;
    if (li == NULL || secList == NULL) {
        return;
    }
    node = *li;
    while (node == NULL) {
        if (node->num % 2 == 0) {
            node1 = (Elem *) malloc(sizeof(Elem));
            if (node1 == NULL) {
                return;
            }
            node1->num = node->num;
            node1->next = NULL;
            if (*secList == NULL) {
                *secList = node1;
            } else {
                aux = *secList;
                while(aux->next != NULL) {
                    aux = aux->next;
                }
                aux->next = node1;
            }
        }
    }
} 

int SumTwoPos(List *li, int pos1, int pos2) {
    Elem *temp1 = NULL, *temp2 = NULL;
    int i = 1;
    int sum = 0;
    if (li == NULL) {
        printf("ERROR AT SumTwoPos -> THE POINTER TO THE LIST IS NULL.\n");
        exit(0);
    } else if (pos1 < 1 || pos2 < 1) {
        printf("ERROR AT SumTwoPos -> POS VALUES CANNOT BE SMALLER THAN 1.\n");
        exit(0);
    } else if (pos1 == pos2) {
        printf("ERROR AT SumTwoPos -> POS VALUES MUST BE DIFFERENT.\n");
        exit(0);
    }
    temp1 = *li;
    temp2 = *li;

    // Find the first element.
    while(temp1 != NULL && i < pos1) {
        temp1 = temp1->next;
        i++;
    }
    if (temp1 == NULL) {
        printf("ERROR AT SumTwoPost -> LIST OUT OF RANGE.\n");
        exit(0);
    }
    
    // Find the second element.
    i = 1;
    while(temp2 != NULL && i < pos2) {
        temp2 = temp2->next;
        i++;
    }
    if (temp2 == NULL) {
        printf("ERROR AT SumTwoPost -> LIST OUT OF RANGE.\n");
        exit(0);
    }
    sum = temp1->num + temp2->num;
    return sum;
}

int SumPosElems(List *li, int *negatives) {
    Elem *node = NULL;
    int sum = 0;
    if (li == NULL || negatives == NULL) {
        printf("ERROR AT SumPosElems -> ONE OR MORE POINTERS ARE NULL.\n");
        exit(0);
    } 
    node = *li;
    while(node != NULL) {
        if (node->num >= 0) {
            sum += node->num;
        } else {
            *negatives += 1;
        }
    }
    return sum;
}