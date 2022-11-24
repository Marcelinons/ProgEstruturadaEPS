#include <stdio.h>
#include <stdlib.h>

/*
    METHODS USED TO CONTROL LINKED LISTS (INT TYPE ONLY FOR NOW).

    AUTHOR: Nicolas Marcelino da Silva.
*/

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
/// @return Pointer-to-pointer to the first element of the list.
List* CreateList();

/// @brief Deallocates the memory used by the elements of the list.
/// @param li Pointer-to-pointer to the first element of the list.
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

/// @brief Inserts a new element at the beginning of the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param n Number which will be inserted.
/// @return 1 if insertion is successful. 0 otherwise.
int InsertBeginning(List *li, int n);

/// @brief Inserts a new element at the end of the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param n Number to be inserted.
/// @return 1 if insertion is successful. 0 otherwise.
int InsertEnd(List *li, int n);

/// @brief Gets the element in the given position of the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param pos Position of the wanted element.
/// @return Element in the pos position.
int GetElemInPos(List *li, int pos);

/// @brief Returns the arithmetic mean of the elements of the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @return Mean of the arithmetic mean of the elements of the list.
float Mean(List *li);

/// @brief Prints the first five elements of the list.
/// @param li Pointer-to-pointer to the first element of the list.
void Head(List *li);

/// @brief Counts how many pair numbers are in the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @return Quantity of pair numbers in the list.
int CountPairElems(List *li);

/// @brief Find the largest number in the list and gets its position.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param largPos Pointer to a variable which will store the position of the
/// largest number.
/// @return Largest number of the list.
int Largest(List *li, int *largPos);

/// @brief Sums of the elements of the list.
/// @param li Pointer-to-pointer to the first element of the list. 
/// @return Sum of the elements of the list.
int Sum(List *li);

/// @brief Answer for week 8's pe7.
/// @param li Pointer-to-pointer to the first element of the list.
void Calculations(List *li);

/// @brief Checks whether two given lists are equal.
/// @param li_1 Pointer-to-pointer to the first element of the first list.
/// @param li_2 Pointer-to-pointer to the first element of the second list.
/// @return 1 if they're equal, 0 otherwise.
int EqualLists(List *li_1, List *li_2);

/// @brief Removes the first N elements of a given list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param n Quantity of numbers to be removed from the beginning.
/// @return 1 if removal is successful. 0 otherwise.
int RemoveFirstN(List *li, int n);

/// @brief Removes the last N elements of a given list.
/// Please note that giving a N value that is higher than the size of the list
/// might break the program.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param n Quantity of numbers to be removed.
/// @return 1 if removal is successful. 0 otherwise.
int RemoveLastN(List *li, int n);

/// @brief Inverts the positions of two elements on the two given positions of
/// the list.
/// @param li Pointer-to-pointer to the first element of the list. 
/// @param pos1 Position of the first element.
/// @param pos2 Position of the second element.
/// @return 1 if switch is successful, 0 otherwise.
void SwitchElems(List *li, int pos1, int pos2);

/// @brief Receives the elements of a main list, a position on this list and
/// two secondary lists. Then, add to the first secondary list all the elements 
/// that are behind this given position as well as the element that is occupying 
/// her. Finally, adds the remaining elements on the second secondary list.
/// @param li Pointer-to-pointer to the first element of the main list.
/// @param pos Position which will be the "breakpoint".
/// @param sub1 Pointer-to-pointer to the first element of the first secondary
/// list.
/// @param sub2 Pointer-to-pointer to the first element of the second secondary
/// list.
void Sublists(List *li, int pos, List *sub1, List *sub2);

/// @brief Inverts the elements of a given list.
/// @param li Pointer-to-pointer to the first element of the main list.
/// @param secList Pointer-to-pointer to the first element of the sec list.
void InvertElems(List *li, List *secList);

/// @brief Receives a main list and adds its pair elements to another list.
/// @param li Pointer-to-pointer to the first element of the main list.
/// @param secList Pointer-to-pointer to the first element of the sec list.
void GetPairs(List *li, List *secList); 

/// @brief Sums the elements that are in two given positions of the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param pos1 Position of the first element.
/// @param pos2 Position of the second element.
/// @return Sum of the two elements.
int SumTwoPos(List *li, int pos1, int pos2);

/// @brief Sums the positive elements of the list. Also, counts how many 
/// negative elements are in the list.
/// @param li Pointer-to-pointer to the first element of the list.
/// @param negatives Pointer to a variable which will store the number of 
/// negative elements.
/// @return Sum of all positive elements in the list.
int SumPosElems(List *li, int *negatives);

/// @brief Count how many elements are in the list.
/// @param list Pointer-to-pointer to the first element of the list.
/// @return Number of elements in the list.
int ListSize(Elem **list);

/// @brief Sorts the elements of a given list in crescent order using selection
/// sort algorithm. NOTE THAT THIS METHOD SWAPS THE DATA OF THE NODES INSTEAD OF
/// CHANGING ITS POINTERS.
/// @param list Pointer to pointer to the first element of the list.
/// @return 1 if sort is successful, 0 otherwise.
int SelectionSort(Elem **list, int listSize);

/// @brief Sort a list of ints using the bubble sort algorithm.
/// @param li Pointer to the first element of a list.
/// @return 1 if sorting is successful, 0 otherwise.
int BubbleSort(List *li);