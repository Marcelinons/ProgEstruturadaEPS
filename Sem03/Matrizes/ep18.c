#include <stdio.h>

/* EP03_18
 * 
 * Le uma matriz n x n de inteiros, atribui a soma dos numeros de cada coluna
 * a um vetor, imprime este vetor.
 *
 * - Nicolas M. 13-10-2022
*/

/// @brief Le uma matriz n x n de inteiros.
/// @param n Dimensoes da Matriz;
/// @param mat Ponteiro para uma matriz n x n;
/// @return 1.
int ReadMat(int n, int mat[n][n]);

/// @brief Calcula o somatorio dos valores de cada coluna e os atribui a um
/// vetor.
/// @param n Dimensoes da matriz; 
/// @param mat Ponteiro para matriz n x n;
/// @param vet Ponteiro para vetor de n elementos;
/// @return 1.
int SumColumns(int n, int mat[n][n], int *vet);

/// @brief Imprime os elementos de um vetor de inteiros.
/// @param n Comprimento do vetor;
/// @param vet Ponteiro para o vetor;
/// @return 1.
int PrintVet(int n, int *vet);

int ReadMat(int n, int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        };
    };
    return 1;
};

int SumColumns(int n, int mat[n][n], int *vet) {
    for (int j = 0; j < n; j++) {
        int somaCol = 0;
        for (int i = 0; i < n; i++) {
            somaCol += mat[i][j];
        };
        vet[j] = somaCol;
    };
    return 1;
};

int PrintVet(int n, int *vet) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    };
    printf("\n");
    return 1;
};

int main () {
    int n = 3;
    int matriz[n][n], vetor[n];

    ReadMat(n, matriz);
    SumColumns(n, matriz, vetor);
    PrintVet(n, vetor);

    return 1;
};