#include "DynamicList.c"

/*
    FILE USED TO TEST THE METHODS OF DynamicList.c.
*/

int main()
{
    int listSize = 5, num;
    List *list = CreateList();
    
    // If there are any errors while creating the lists, the program is 
    // terminated.
    if (list == NULL) {
        exit(0);
    }
    
    printf("----- LIST 1 -----\n");
    // Receive the elements of the first list (5 ints).
    
    for (int i = 0; i < listSize; i++) {
        printf("Enter element: ");
        scanf("%d", &num);
        if (!InsertEnd(list, num)) {
            exit(0);
        }
    }

    printf("------ OUTPUTS ------\n");

    printf("List: ");
    Head(list);
    printf("Sorted List: ");
    SelectionSort(list, listSize);
    Head(list);

    // Free the used memory space.
    FreeMemory(list);

    printf("---- END OF PROGRAM ----\n");
    return 0;
}
