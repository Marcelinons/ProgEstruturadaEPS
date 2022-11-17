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
/// @param li Pointer-to-pointer to the first element of the list.
/// @return 1 if the list is empty. 0 otherwise.
int EmptyList(List *li);