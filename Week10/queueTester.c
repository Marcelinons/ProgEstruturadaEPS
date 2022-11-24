#include "LinkedQueue.c"

/*
    Simple file containing a main function which will be used to test the
    functionality of the methods declared and defined at LinkedQueue.h and
    LinkedQueue.c, respectfully.

    Author: Nicolas Marcelino da Silva.
*/

void main() {
    List* list = NULL;
    char name[nameSize];
    int age, regnum;
    Node* oldest = NULL;
    list = CreateList();
    printf("\n------ RECEIVING DATA ------\n");
    // Will read the data of 3 students (name, age and regnum).
    for (int i = 1; i < 4; i++) {
        printf("\n>>> STUDENT #%d <<<\n\n", i);
        printf("Enter student's name: ");
        scanf("%s", &name);
        printf("Enter student's age: ");
        scanf(" %d", &age);
        printf("Enter student's register number: ");
        scanf("%d", &regnum);
        if (AddToQueue(list, name, age, regnum)) {
            printf("New student successfully added to the queue!\n");
        } else {
            printf("ERROR: couldn't add new student to queue.\n");
        }
    }
    printf("\n------ OUTPUTS ------\n\n");
    PrintStudents(list);
    oldest = FindOldest(list);
    printf("The oldest student is %s, who is %d years old.\n", oldest->name,
        oldest->age);
    printf("\n------ END OF PROGRAM ------\n\n");
    DestroyList(list);
    free(oldest);
}