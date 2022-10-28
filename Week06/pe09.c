#include <stdio.h>

/* EP06_09
 *
 * Le uma matriz n x n e adiciona 1 a cada elemento usando aritmetica de
 * ponteiros.
 * 
 * NicolasMSilva <28/10/2022>
*/

/// @brief Soma um em cada elemento da matriz.
/// @param mat Ponteiro para o primeiro elemento da matriz
void Add1Mat(int *mat);

/// @brief Le uma matriz n x n;
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para o primeiro elemento da matriz;
void ReadMat(int n, int *mat);

/// @brief Printa os elementos de uma matriz n x n;
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para primeiro elemento da matriz;
void PrintMat(int n, int *mat);


int main () {
    int n = 3;
    int mat[n][n];
    int *pMat = &mat[0][0];

    ReadMat(n, pMat);
    Add1Mat(pMat);
    PrintMat(n, pMat);

    return 1;
}

void Add1Mat(int *mat) {
    for (int i = 0; i < 9; i++) {
        *(mat + i) += 1;  
    }
}

void ReadMat(int n, int *mat) {
    for (int i = 0; i < n*n; i++) {
        scanf("%d", (mat + i));
    }
}

void PrintMat(int n, int *mat) {
    for (int i = 0; i < n*n; i++) {
        printf("%d\n", *(mat + i));
    }
}