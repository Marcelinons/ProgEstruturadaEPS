#include "DynamicList.h"

/*
    METHODS USED TO CONTROL LINKED LISTS (INT TYPE ONLY FOR NOW).

    AUTHOR: Nicolas Marcelino da Silva.
*/

List* CreateList() 
{
    List* li;
    // Allocating memory space for the list.
    li = (List *) malloc(sizeof(List));
    if (li != NULL) 
    {
        *li = NULL;
    } 
    else
    {
        printf("ERROR -> CreateList: could not allocate memory to create"
            " the list.\n");
    }
    return li;
}

void FreeMemory(List *li) 
{

    if (li != NULL) 
    {
        Elem *no = NULL;
        /* Runs through the list until the content of *li (a memory address) is
        NULL (until it finds the end of the list).
        */
        while ((*li) != NULL) 
        {
            no = *li;
            *li = (*li)->next;
            free(no);
        }
        free(li);
    }
}

int SizeofList(List *li) 
{
    int count = 0;
    if (li == NULL) 
    {
        return -1;
    } 
    else 
    {
        // Points to the first element of the list.
        Elem *node = *li;
        while (node != NULL) 
        {
            count++;
            node = node->next;
        }
        return count;
    }
}

int EmptyList(List *li) 
{
    if (li == NULL) 
    {
        return 1;
    } 
    else 
    {
        if (*li == NULL) 
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
    }
}

int InsertBeginning(List *li, int n) 
{
    if (li == NULL) 
    {
        printf("ERROR -> InsertBeginning: the pointer to the list is NULL.\n");
        return 0;
    } 
    else 
    {
        Elem *node = NULL;
        node = (Elem *) malloc(sizeof(Elem));
        if (node == NULL) 
        {
            return 0;
        } 
        else 
        {
            node->num = n;
            node->next = *li;
            *li = node;
        }
    }
    return 1;
}

int InsertEnd(List *li, int n) 
{
    // Checks if its possible to insert a new element.
    if (li == NULL) 
    {
        printf("ERROR -> InsertEnd: the pointer to the list is NULL.\n");
        return 0;
    }
    Elem *node = NULL;
    node = (Elem *) malloc(sizeof(Elem));
    if (node == NULL) 
    {
        return 0;
    }
    node->num = n;
    node->next = NULL;
    // If the list is empty, the last element is also the first.
    if (*li == NULL) 
    {
        *li = node;
    } 
    else 
    {
        // Runs through the list searching for its last element.
        Elem *aux;
        aux = *li;
        while (aux->next != NULL) 
        {
            aux = aux->next;
        }
        // When it finds the last element of the list, set its pointer to the
        // newly created element.
        aux->next = node;
    }
    return 1;
}

int GetElemInPos(List *li, int pos) 
{
    if (li == NULL || pos < 0) 
        exit(0);
    Elem *node = NULL;
    node = *li;

    int i = 1, resp = 0;
    while (node != NULL && i < pos) 
    {
        node = node->next;
        i++;
    }
    if (node == NULL) 
    {
        exit(0);
    }
    else 
    {
        resp = node->num;
        return resp;
    }
}

float Mean(List *li) 
{
    int sum = 0, elementsCount = 0;
    Elem *node = NULL;
    if (li == NULL) 
    {
        printf("ERROR -> Mean: the pointer to the list is NULL.\n");
        exit(0);
    }
    node = *li;
    while (node != NULL) 
    {
        sum += node->num;
        node = node->next;
        elementsCount++;
    }
    return sum/(float)elementsCount;
}

void PrintList(Elem **list) 
{
    Elem *temp = NULL;
    if (list == NULL) 
    {
        return;
    }
    temp = *list;
    while (temp != NULL) 
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

void Head(List *li) 
{
    int i = 1;
    Elem *node = NULL;
    if (li == NULL) 
    {
        printf("ERROR -> Head: the pointer to the list is NULL.\n");
        return;
    }
    node = *li;
    while (node != NULL && i < 6) 
    {
        printf("%d ", node->num);
        node = node->next;
        i++;
    }
    printf("\n");
}

int CountPairElems(List *li) 
{
    int count = 0;
    Elem *node = NULL;

    if (li == NULL) 
    {
        printf("ERROR -> CountPairElems: the pointer to the list is NULL.\n");
        exit(0);
    }
    node = *li;
    while (node != NULL) 
    {
        if (node->num%2 == 0) 
        {
            count++;
        }
        node = node->next;
    }
    return count;
}

int Largest(List *li, int *largPos) 
{
    int i = 1, largest;
    Elem *node = NULL;
    
    if (li == NULL) 
    {
        printf("ERROR -> LargestAmongFFive: the pointer to the list is NULL.\n");
        exit(0);
    }
    node = *li;
    while (node != NULL)
    {
        if (i == 1) 
        {
            largest = node->num;
        } 
        else 
        {
            if (node->num > largest) 
            {
                largest = node->num;
                *largPos = i;
            }
        }
        node = node->next;
        i++;
    }
    return largest;
}

int Sum(List *li) 
{
    int sum = 0;
    Elem *node = NULL;
    
    if (li == NULL) 
    {
        printf("ERROR -> Sum: the pointer to the list is NULL.\n");
        exit(0);
    } 
    else 
    {
        node = *li;
        while (node != NULL) 
        {
            sum += node->num;
            node = node->next;
        }
    }
    return sum;
}

void Calculations(List *li) 
{
    int i = 1, sum = 0, largest, largestPos, elem, pairCount = 0;
    float mean;
    Elem *node = NULL;
    
    if (li == NULL) 
    {
        printf("ERROR -> Calculations: the pointer to the list is NULL.\n");
        exit(0);
    } 
    else 
    {
        node = *li;
        while (node != NULL) 
        {
            elem = node->num;
            sum += elem;
            if (elem % 2 == 0) 
                pairCount++;
            if (i == 1) 
            {
                largest = elem;
            } 
            else 
            {
                if (elem > largest) 
                {
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

int EqualLists(List *li_1, List *li_2) 
{
    Elem *node1 = NULL, *node2 = NULL;

    if (li_1 == NULL || li_2 == NULL) 
    {
        printf("ERROR -> AreTheyEqual: one or two pointers are NULL.\n");
        exit(0);
    }
    node1 = *li_1;
    node2 = *li_2;
    while (node1 != NULL && node2 != NULL) 
    {
        printf("%d ", node1->num);
        
        if (node1->num != node2->num) 
        {
            return 0;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    return 1;
}

int RemoveFirstN(List *li, int n) 
{
    int i = 0;
    Elem *node = NULL;
    if (li == NULL) 
    {
        printf("ERROR -> RemoveFirstN: pointer to the list is NULL.\n");
        return 0;
    }
    // Repeats N times.
    for (i = 0; i < n; i++) 
    {
        // Get the first element of the list.
        node = *li;
        // Move *li pointer to the next element.
        *li = node->next;
        // Free the previous element.
        free(node);
    }
    return 1;
}

int RemoveLastN(List *li, int n) 
{
    Elem *node = NULL, *previous = NULL;
    if (li == NULL || *li == NULL) 
    {
        printf("ERROR -> RemoveLastN: pointer to the list is NULL.\n");
        return 0;
    }
    // Repeat N times or while the start of the list (*li) is not NULL.
    while (*li != NULL && n > 0) 
    {
        // First element of the list.
        node = *li;
        if (node == NULL)
            break;
        // Find the last element and the last but one elements of the list.
        while (node->next != NULL) 
        {
            previous = node;
            node = node->next;
        }
        if (node == *li) 
            // If the last element is the first, then set the *li to NULL.
            *li = node->next;
        else
            // Otherwise, set the last but one element's next component to NULL.
            previous->next = NULL;
        // Release the used memory of the last node.
        free(node);
        n--;
    }
    return 1;
}

void SwitchElems(List* li, int pos1, int pos2) 
{
    Elem *node1 = NULL, *node2 = NULL, *ant1 = NULL, *ant2 = NULL, *aux = NULL;
    int i = 1;
    if (li == NULL || pos1 < 1 || pos2 < 1 || pos1 == pos2)        
        return;
    node1 = *li;
    node2 = *li;
    while (node1->next != NULL && i < pos1) 
    {
        ant1 = node1;
        node1 = node1->next;
        i++;
    }
    i = 1;
    while (node2->next != NULL && i < pos2) 
    {
        ant2 = node2;
        node2 = node2->next;
        i++;
    }

    if (ant1 == NULL)
        *li = node2;
    else 
        ant1->next = node2;

    if (ant2 == NULL)
        *li = node1;
    else
        ant2->next = node1;

    aux = node1->next;
    node1->next = node2->next;
    node2->next = aux;
    return;
}

void Sublists(List *li, int pos, List *sub1, List *sub2) 
{
    int i = 0;
    Elem *node = NULL, *node1 = NULL, *node2 = NULL, *aux = NULL;
    if (li == NULL || sub1 == NULL || sub2 == NULL || pos < 0)        
        return;
    
    node = *li;
    while (node != NULL) 
    {
        if (i < pos) 
        {
            node1 = (Elem *) malloc(sizeof(Elem));
            if (node1 == NULL) 
                return;

            node1->num = node->num;
            node1->next = NULL;
            if (*sub1 == NULL) 
            {
                *sub1 = node1;
            }
            else
            {
                aux = *sub1;
                while (aux->next != NULL) 
                {
                    aux = aux->next;
                }
                aux->next = node1;
            }
        } 
        else 
        {
            node2 = (Elem *) malloc(sizeof(Elem));
            if (node2 == NULL) 
            {
                return;
            }
            node2->num = node->num;
            node2->next = NULL;
            if (*sub2 == NULL) 
            {
                *sub2 = node2;
            }
            else 
            {
                aux = *sub2;
                while (aux->next != NULL) 
                {
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

void InvertElems(List *li, List *secList) 
{
    Elem *node = NULL, *secNode = NULL, *aux = NULL;
    if (li == NULL || secList == NULL) 
    {
        printf("The pointer to some of the lists is null.\n");
        return;
    }
    node = *li;
    // Runs through the list.
    while (node != NULL) 
    {
        // Add a element to the beginning of the sec list.
        secNode = (Elem *) malloc(sizeof(Elem));
        if (secNode == NULL)
            return;
        
        secNode->num = node->num;
        secNode->next = *secList;
        if (*secList == NULL)
            *secList = secNode;
        else
            *secList = secNode;
        
        node = node->next;       
    }
}

void GetPairs(List *li, List *secList) 
{
    Elem *node = NULL, *node1 = NULL, *aux = NULL;
    if (li == NULL || secList == NULL)
        return;

    node = *li;
    while (node == NULL) 
    {
        if (node->num % 2 == 0) 
        {
            node1 = (Elem *) malloc(sizeof(Elem));
            if (node1 == NULL) 
                return;
            
            node1->num = node->num;
            node1->next = NULL;
            if (*secList == NULL) 
            {
                *secList = node1;
            } 
            else 
            {
                aux = *secList;
                while(aux->next != NULL) 
                {
                    aux = aux->next;
                }
                aux->next = node1;
            }
        }
    }
} 

int SumTwoPos(List *li, int pos1, int pos2) 
{
    Elem *temp1 = NULL, *temp2 = NULL;
    int i = 1;
    int sum = 0;
    if (li == NULL) 
    {
        printf("ERROR AT SumTwoPos -> THE POINTER TO THE LIST IS NULL.\n");
        exit(0);
    } 
    else if (pos1 < 1 || pos2 < 1) 
    {
        printf("ERROR AT SumTwoPos -> POS VALUES CANNOT BE SMALLER THAN 1.\n");
        exit(0);
    } 
    else if (pos1 == pos2) 
    {
        printf("ERROR AT SumTwoPos -> POS VALUES MUST BE DIFFERENT.\n");
        exit(0);
    }
    temp1 = *li;
    temp2 = *li;

    // Find the first element.
    while(temp1 != NULL && i < pos1) 
    {
        temp1 = temp1->next;
        i++;
    }
    if (temp1 == NULL) 
    {
        printf("ERROR AT SumTwoPost -> LIST OUT OF RANGE.\n");
        exit(0);
    }
    
    // Find the second element.
    i = 1;
    while(temp2 != NULL && i < pos2) 
    {
        temp2 = temp2->next;
        i++;
    }
    if (temp2 == NULL) 
    {
        printf("ERROR AT SumTwoPost -> LIST OUT OF RANGE.\n");
        exit(0);
    }
    sum = temp1->num + temp2->num;
    return sum;
}

int SumPosElems(List *li, int *negatives) 
{
    Elem *node = NULL;
    int sum = 0;
    if (li == NULL || negatives == NULL) 
    {
        printf("ERROR AT SumPosElems -> ONE OR MORE POINTERS ARE NULL.\n");
        exit(0);
    } 
    node = *li;
    while(node != NULL) 
    {
        if (node->num >= 0) 
        {
            sum += node->num;
        } 
        else 
        {
            *negatives += 1;
        }
    }
    return sum;
}

int ListSize(Elem **list) 
{
    Elem *temp = NULL;
    int count = 0;
    if (list == NULL) 
    {
        exit(0);
    }
    temp = *list;
    while (temp != NULL) 
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int SelectionSort(Elem **list) 
{
    Elem *current = NULL, *temp = NULL, *smallest = NULL, *aux = NULL;
    Elem *antLarg = NULL, *antCurr = NULL;
    int swap, i = 0;
    
    // Case which the list is empty.
    if (list == NULL)
        return 0;

    // The current element starts pointing to the beginning of the list.
    current = *list;
    // While the current doesn't reach the end of the list.
    while (current != NULL) 
    {
        i++;    // Iteration counter.
        swap = 0;
        // Find the smallest element in the list (from the current elem).
        smallest = current;
        temp = current->next;
        while (temp != NULL) 
        {
            if (smallest->num > temp->num) 
            {
                smallest = temp;
                swap = 1;
            }
            temp = temp->next;
        }
        // If it finds an element that is larger than the current element,
        if (swap) 
        {
            /* Find the anterior of the current and the anterior of the smallest
            elements.
            */
            antLarg = *list;
            antCurr = *list;
            
            /* If the current element is at the beginning of the list, it does
            not have an previous element.
            */
            if (current != *list) 
            {
                while (antCurr->next != current) 
                {
                    antCurr = antCurr->next;
                }
            }
            while (antLarg->next != smallest) 
            {
                antLarg = antLarg->next;
            }

            /* In the case where the current elem is the first in the list, must
            make the *list pointer point to the smallest element. Otherwise, the
            element that comes before the current element must point to the
            smallest element.
            */
            if (i == 1) 
                *list = smallest;
            else 
                antCurr->next = smallest;
    
            /* The element that comes before the smallest element must point to
            the current element.
            */
            antLarg->next = current;

            /* The current->next element must point to the smallest->next 
            element and vice-versa.
            */
            temp = current;
            aux = temp->next;
            temp->next = smallest->next;
            smallest->next = aux;
            // Finally, makes the current be the smallest element.
            current = smallest;
        }
        // Go to the next element in the list.
        current = current->next;
    }
}

int SelectionSortElem(Elem **list, int listSize) 
{
    Elem *node = NULL, *temp = NULL, *largest = NULL;
    int swap, aux;
    if (list == NULL)
        return 0;
    
    node = *list;
    for (int i = 0; i < listSize-1; i++) 
    {
        swap = 0;
        largest = node;
        temp = node->next;
        // Find the largest num in the list (that come after node).
        while (temp != NULL) 
        {
            if (largest->num > temp->num) 
            {
                largest = temp;
                swap = 1;
            }
            temp = temp->next;
        }
        if (swap) 
        {
            aux = node->num;
            node->num = largest->num;
            largest->num = aux;
        }
        node = node->next;
    }
    return 1;
}

int BubbleSort(Elem **list) 
{
    Elem *temp = NULL, *current = NULL, *aux = NULL, *nextT = NULL;
    int run = 0, i = 0, listSize = 0;;
    if (list == NULL) 
        return 0;
    
    // Find the size of the list.
    temp = *list;
    while (temp != NULL) 
    {
        temp = temp->next;
        listSize++;
    }

    do {
        current = *list;
        if (current == NULL)
            break;
        
        run = 0;
        for (int i = 0; i < listSize-1; i++) 
        {
            temp = current;
            nextT = temp->next;
            if (nextT == NULL) 
                break;
            
            if (temp->num > nextT->num) 
            {
                run = 1;
                if (current == *list) 
                {
                    *list = nextT;
                    current = nextT;
                } 
                else 
                {
                    aux = *list;
                    while (aux->next != current) 
                    {
                        aux = aux->next;
                    }
                    aux->next = nextT;
                    current = nextT;
                }
                aux = nextT->next;
                nextT->next = temp;
                temp->next = aux; 
            }
            current = current->next;
        }
        listSize--;
    } while (run);
}

int ReadNSort(Elem **list, int n) 
{
    Elem *temp = NULL, *aux = NULL, *secAux = NULL, *end = NULL;
    int num;
    if (list == NULL) 
    {
        return 0;
    }
    if (*list != NULL) 
    {
        // If the list already have elements, find what is the last one.
        end = *list;
        while (end->next != NULL) 
        {
            end = end->next;
        }
    }
    // Repeats n times.
    for (int i = 0; i < n; i++) 
    {
        temp = (Elem *) malloc(sizeof(Elem));
        if (temp == NULL) 
        {
            printf("There was an error while allocating memory.\n");
            return 0;
        }
        printf("DynamicSort >>> Insert new elem: ");
        scanf("%d", &num);
        temp->num = num;
        temp->next = NULL;
        // If the list is empty, make temp the first element.
        if (*list == NULL) 
        {
            *list = temp;
        } 
        else 
        {
            // Aux will vary depending whether the list starts empty or not.
            aux = *list;
            if (end != NULL)
                aux = end;
                        
            if (end != NULL && end->next != NULL && temp->num <= end->next->num) 
            {
                /* If the list started with at least two elements and temp->num 
                is smaller than the last element, put temp right after the last
                elem.
                */
                temp->next = end->next;
                end->next = temp;
            } 
            else if (end == NULL && temp->num <= (*list)->num) 
            {
                /* If the list started empty and temp is smaller than the first
                elem, make temp the first element.
                */
                temp->next = *list;
                *list = temp;
            }
            else 
            {
                /* If the list is not empty (not mattering if it started empty
                or not) temp is not smaller than the first (or last) element,
                find the right position for temp.  
                */
                while (aux->next != NULL) 
                {
                    if (temp->num >= aux->num && temp->num < aux->next->num)
                        break;
                    aux = aux->next;
                }
                if (aux->next == NULL) 
                {
                    aux->next = temp;
                } 
                else 
                {
                    secAux = aux->next;
                    aux->next = temp;
                    temp->next = secAux;
                }
            }
        }
    }
    return 1;
}