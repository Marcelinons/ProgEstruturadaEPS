#include "LinkedQueue.h"

/*
    This library contains methods useful to create and manipulate linked queues.

    Note that a queue is nothing more than a list, but the criteria for add or
    remove a element must follow a specific logic. In this case, the queue will
    follow the FIFO (first in, first out) idea.

    The struct used for each node of the queue represent a student: it has the
    "name", "age" and "regnum" (which stands for register number) parameters (
    and, of course, the next pointer). The names will have a maximum length of
    20 characters.

    Author: Nicolas Marcelino da Silva.
*/

List* CreateList(void) {
    List *list = NULL;
    list = (List *) malloc(sizeof(List));
    if (list != NULL) {
        *list = NULL;
    } 
    return list;
}

void DestroyList(List *list) {
    Node *node = NULL;
    if (list == NULL) {
        return;
    }
    while (node != NULL) {
        node = *list;
        *list = (*list)->next;
        free(node);
    }
    free(list);
    list = NULL;
}

int AddToQueue(List *list, char *name, int age, int regnum) {
    Node *node = NULL, *temp = NULL;
    if (list == NULL) {
        return 0;
    }
    node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        return 0;
    }
    strcpy(node->name, name);
    node->age = age;
    node->regnum = regnum;
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
    } else {
        temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    return 1;
}

int RemoveFromQueue(List *list) {
    Node *temp = NULL;
    if (list == NULL || *list == NULL) {
        return 0;
    }
    temp = *list;
    *list = (*list)->next;
    free(temp);
}

void PrintStudents(List *list) {
    Node *node = NULL;
    if (list == NULL) {
        return;
    }
    node = *list;
    printf(">>> STUDENTS IN THE QUEUE: \n\n");
    while (node != NULL) {
        printf("    >>> STUDENT #%d <<<\n", node->regnum);
        printf("    Name: %s\n", node->name);
        printf("    Age: %d\n\n", node->age);
        node = node->next;
    }
}

void FindOldest(List *list) {
    Node *temp = NULL;
    int highestAge;
    if (list == NULL) {
        exit(0);
    }
    // Find the highest age value in the queue.
}