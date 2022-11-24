#include "StaticList.c"

/* Code to test the methods of StaticList.c (someday I'll finish) */

void main() {
    int num, sMethod;
    List *li = NULL;
    li = CreateList();
    if (li == NULL) {
        exit(0);
    }
    printf("\n----- LIST #1 -----\n\n");
    // Read 5 elements list.
    for (int i = 0; i < 5; i++) {
        printf(" Insert new int: ");
        scanf("%d", &num);
        InsertNewElem(li, num);
    }
    printf("\nSelect sorting method: 1) Bubble sort;\n");
    printf("                       2) Selection sort;\n");
    printf("                       3) Insertion sort.\n");
    printf("Select sorting method: ");
    scanf("%d", &sMethod);
    
    printf("\n----- OUTPUTS -----\n\n");
  
    printf("List in the beginning: ");
    PrintList(li);

    switch (sMethod) {
    case 1:
        if (BubbleSort(li)) {
            printf("Sorted list using BubbleSort: ");
            PrintList(li);
        } else {
            printf("ERROR -> Couldn't sort the list using bubble sort.\n");
        }
        break;
    case 2:
        if (SelectionSort(li)) {
            printf("Sorted list using SelectionSort: ");
            PrintList(li);
        } else {
            printf("ERROR -> Couldn't sort the list using selection sort.\n");
        }
        break;
    case 3:
        if (InsertionSort(li)) {
            printf("Sorted list using InsertionSort: ");
            PrintList(li);
        } else {
            printf("ERROR -> Couldn't sort the list using insertion sort.\n");
        }
    default:
        break;
    }
    printf("\n----- END OF THE PROGRAM -----\n\n");
    FreeMemory(li);
}