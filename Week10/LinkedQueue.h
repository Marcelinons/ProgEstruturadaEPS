#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define nameSize 20
struct TStudent {
    char name[nameSize];
    int age;
    int regnum;
    struct TStudent *next;
};
typedef struct TStudent Node;
typedef struct TStudent *List;

/// @brief Creates a new linked list.
/// @return Pointer to the first element of a list.
List* CreateList(void);

/// @brief Destroys a given list, freeing all the used space.
/// @param list Pointer to the first element (first Node) of the list.
void DestroyList(List* list);

/// @brief Adds a new element to the queue. In this case, the element is a
/// student's name, age and regnum (student's register number).
/// @param list Pointer to the first element (first Node) of the queue.
/// @param name Student's name (maximum of 20 characters).
/// @param age Student's age.
/// @param regnum Student's register number.
/// @return 1 if insertion is successful, 0 otherwise.
int AddToQueue(List *list, char *name, int age, int regnum);

/// @brief Removes the first element of the queue (following FIFO's algorithm).
/// @param list Pointer to the first element (first Node) of the queue.
/// @return 1 if removal is successful, 0 otherwise.
int RemoveFromQueue(List *list);

/// @brief Prints the elements of a student queue.
/// @param list Pointer to the first element of the list.
void PrintStudents(List *list);

/// @brief Finds the oldest student among the queue and returns its data.
/// @param list Pointer to the first element of the queue.
/// @return struct of type TStudent with the oldest student's data.
void FindOldest(List *list);