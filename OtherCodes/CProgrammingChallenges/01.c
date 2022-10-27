#include <stdio.h>

/* Receives an array of ints with size n and a int num. Find in the array two
 * numbers whose sum is equal to num, and return its indices. 

 * - NicolasMSilva 22-10-2022
*/

/// @brief Reads a array of n ints.
/// @param n Number of elements;
/// @param v Pointer to a array of n elements; 
/// @param i Initializer of i. Must be 0 in order to work correctly;
void ReadArray(int n, int* v, int i);

/// @brief Sum each pair of elements of a given array and returns the indices 
/// of two numbers whose sum is equal to num.
/// @param n Number of elements;
/// @param num Target value;
/// @param v Pointer to a int array of n elements;
/// @param indices Pointer to a int array of 2 elements that will store the
/// found indices;
/// @return 1 if there are two ints whose sum is equal to num; 0 otherwise.
int SumTwoElems(int n, int num, int* v, int* indices);

/// @brief Prints a array of n ints;
/// @param n Number of elements;
/// @param v Pointer to a n elements int array;
/// @param i Initializer of i. Must be 0 in order to work correctly;
void PrintArray(int n, int* v, int i);


void ReadArray(int n, int* v, int i) 
{
    if (i < n) 
    {
        scanf("%d", &v[i]);
        return ReadArray(n, v, i+1);
    }
}

int SumTwoElems(int n, int num, int*v, int* indices) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (i == j) {
                continue;
            }
            if (v[i] + v[j] == num) {
                indices[0] = i;
                indices[1] = j;
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    return found;
}

void PrintArray(int n, int* v, int i) {
    if (i < n) {
        printf("%d ", v[i]);
        return PrintArray(n, v, i+1);
    }
    printf("\n");
}

int main () {
    int n = 5, num, found, indices[2];
    int array[n];
    
    printf("Target Value: ");
    scanf("%d", &num);

    ReadArray(n, array, 0);

    //PrintArray(n, array, 0);

    found = SumTwoElems(n, num, array, indices);

    if (found) {
        printf("Indices: %d, %d\n", indices[0], indices[1]);
    } else {
        printf("There are no numbers in this array whose sum is equal to %d.\n",
            num);
    }
    return 0;
}