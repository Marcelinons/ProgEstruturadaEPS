#include <stdio.h>
#include <stdlib.h>

/*
    This library contains methods to control static lists in C. Most ot these
    methods were took from Structured Programming class slides, made by the 
    teachers Francisco de Assis Zampirolli and Wagner Tanaka Botelho. All the
    credits goes to them.

    - Nicolas Marcelino da Silva
*/

#define arraySize 20 /* Maximum size of the list. */
typedef struct list 
{
    int qtd;
    int num[arraySize];
} List;

/// @brief Creates a list using List struct.
/// @return Pointer to a list (from List struct).
List* CreateList();

/// @brief Inserts a new number (int) on the next available position of the
/// given list.
/// @param li Pointer to a list (from List struct). 
/// @param n Number to be inserted.
/// @return 1 if the insertion was successful; 0 otherwise.
int InsertNewElem(List *li, int n);

/// @brief Releases the used memory space.
/// @param li Pointer to a list (from List struct).
void FreeMemory(List *li);

/// @brief Prints the elements of a given list.
/// @param li Pointer to a list (from List struct).
void PrintList(List *li);

/// @brief Concatenate two given lists into a new third list.
/// @param li1 Pointer to the first list (from List struct).
/// @param li2 Pointer to the second list (from List struct). 
/// @return Pointer to a third list which contains the elements of both lists.
List* ConcatLists(List *li1, List *li2);

/// @brief Removes the n first elements of a given list.
/// @param li Pointer to a list (from List struct). 
/// @param n Number of elements which will be removed from the beginning of the 
/// list.
/// @return 1 if removal is successful, 0 otherwise.
int RemoveFirstN(List *li, int n);

/// @brief Switches the position of two given integers inside a given list.
/// @param li Pointer to a list (from List struct);
/// @param n1 Number which position will be switched with n2.
/// @param n2 Number which position will be switched with n1.
/// @return 1 if the change is successful, 0 otherwise.
int SwitchInts(List* li, int n1, int n2);

/// @brief Removes the first element of a given list.
/// @param li Pointer to a list (from List struct).
/// @return 1 if the removal is successful. 0 otherwise.
int RemoveFromBeginning(List *li);

/// @brief Removes the last element of a given list.
/// @param li Pointer to a list (from List struct).
/// @return 1 if the removal is successful. 0 otherwise.
int RemoveFromEnd(List *li);

/// @brief Returns the number of elements inside a given list.
/// @param li Pointer to a list (from List struct);
/// @return Number of elements in the list. If the list's pointer is NULL, 
/// returns -1.
int SizeOfList(List *li);

/// @brief Inserts a new element (int) at the beginning of the list.
/// @param li Pointer to a list (from List struct).
/// @return 1 if insertion is successful. 0 otherwise.
int InsertNewElemBeginning(List *li, int n);

/// @brief Removes the first appearance of n in list.
/// @param li Pointer to the list (from List struct).
/// @param n Element which will be removed.
/// @return 1 if removal is successful. 0 otherwise.
int Remove(List *li, int n);

/// @brief Gets the element of a given position of the list.
/// @param li Pointer to the list (from List struct).
/// @param pos Position of the element in the list. 
/// @return The value of the element in the given position of the list.
int GetNInPos(List *li, int pos);

/// @brief Gets the position (not the index) of a given element inside the
/// list.
/// @param li Pointer to a list (from List struct). 
/// @param elem Element whose position will be returned.
/// @return The position (not the index) of a given element inside the list. If
/// the element is not in the list, or the pointer is NULL, returns -1.
int GetPosOfElem(List *li, int elem);