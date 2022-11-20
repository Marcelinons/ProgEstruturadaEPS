#include "DynamicList.c"

/*
    FILE USED TO TEST THE METHODS OF DynamicList.c.
*/

int main()
{
    int num = 0, pairs, largest, sum, largPos = 1;
    float media;
    List *li1 = CreateList();
    List *li2 = CreateList();
    
    // If there are any errors while creating the lists, the program is 
    // terminated.
    if (li1 == NULL || li2 == NULL) {
        exit(0);
    }
    
    printf("----- LIST 1 -----\n");
    // Receive the elements of the first list (5 ints).
    
    for (int i = 0; i < 5; i++) {
        printf("Enter element: ");
        scanf("%d", &num);
        if (!InsertEnd(li1, num)) {
            exit(0);
        }
    }
   
    // Receive the elements of the second list (5 ints).
    
    // printf("----- LIST 2 -----\n");
    // for (int i = 0; i < 5; i++) {
    //     printf("Enter element: ");
    //     scanf("%d", &num);
    //     InsertEnd(li2, num);
    // }

    printf("------ OUTPUTS ------\n");

    // RemoveLastN(li1, 9);

    printf("BEFORE SWITCH POS 1 AND 3: ");
    Head(li1);

    SwitchElems(li1, 1, 3);

    printf("AFTER SWITCH POS 1 AND 3:  ");
    Head(li1);

    // if (EqualLists(li1, li2)) {
    //     printf("They're equal.\n");
    // } else {
    //     printf("They're not equal.\n");
    // }
    
    // printf("\nFirst 5 elements of the list: ");
    // Head(li1);
    
    // pairs = CountPairElems(li1);
    // printf("Number of pair elements among these: %d\n", pairs);
    
    // media = Mean(li1);
    // printf("Mean of these elements: %.2f\n", media);
    
    // largest = Largest(li1, &largPos);
    // printf("Largest number among these elements: %d at position %d\n",
    //     largest, largPos);
    
    // sum = Sum(li1);
    // printf("Sum of these elements: %d\n", sum);
    
    // Calculations(li1);

    // Free the used memory space.
    FreeMemory(li1);
    FreeMemory(li2);
    printf("---- END OF PROGRAM ----\n");
    return 0;
}
