#include <stdio.h>
#include <stdlib.h>

struct element {
    int num; // Element of the list.
    struct element *next; // Pointer to the next element of the list.
};
typedef struct element Elem;
typedef struct element *List;
/* List *li -> Is a pointer to List, which is a pointer to the struct element.
 Therefore, it is a pointer-to-pointer and stores the address of a pointer.
*/

/// @brief Creates a dynamic list.
/// @return Pointer-to-pointer of an element struct.
List* CreateList();

/// @brief Deallocates the memory used by the elements of the list.
/// @param li Pointer-to-pointer to the struct element.
void FreeMemory(List *li);

/// @brief Counts how many elements there are in the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @return Quantity of elements in the list. If the pointer is NULL, returns
/// -1.
int SizeofList(List *li);

/// @brief Checks if a given list is empty.
/// @param li Pointer-to-pointer to the last element of the list.
/// @return 1 if the list is empty. 0 otherwise.
int EmptyList(List *li);

/// @brief Inserts a new element at the beginning of the list.
/// @param li Pointer-to-pointer to the last element of the list.
/// @param n Number which will be inserted.
/// @return 1 if insertion is successful. 0 otherwise.
int InserNewElemBeginning(List *li, int n);

/// @brief Inserts a new element at the end of the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param n Number to be inserted.
/// @return 1 if insertion is successful. 0 otherwise.
int InsertNewElem(List *li, int n);

/// @brief Gets the number in the given position of the list.
/// @param li Pointer-to-pointer to the last element of the list.
/// @param pos Position of the wanted element.
/// @return Element in the pos position.
int GetElemInPos(List *li, int pos);

/* BELOW METHODS NEED TO BE REFINED */

/// @brief Returns the arithmetic mean of the first 5 elements of a given
/// list.
/// @param li Pointer-to-pointer to the last element of the list.
/// @return Mean of the arithmetic mean of the first 5 elements of the list.
float Mean(List *li);

/// @brief Prints the first five elements of the list.
/// @param li Pointer-to-pointer to the last element of the list.
void Head(List *li);

/// @brief Counts how many of the first five numbers of the list are pair.
/// @param li Pointer-to-pointer to the last element of the list.
/// @return Quantity of pair numbers among the first five of the list.
int CountPairElems(List *li);

/// @brief Find the largest number among the five first of the list and
/// gets its position.
/// @param li Pointer-to-pointer to the last element of the list.
/// @param largPos Pointer to a variable which will store the position of the
/// largest number.
/// @return Largest number of the first five elements of the list.
int LargestAmongFFive(List *li, int *largPos);
