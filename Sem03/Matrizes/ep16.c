#include <stdio.h>

/* EP03_16
 * 
 * Le uma matriz n x n de inteiros e exibe a soma dos valores da diagonal
 *  principal e secundaria.
 * 
 * - Nicolas M. 13-10-2022
 */

/// @brief Le uma matriz n x n de inteiros.
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para uma matriz n x n;
/// @return 1.
int ReadMat(int n, int mat[n][n]);

/// @brief Soma os valores da diagonal principal de uma matriz n x n de ints.
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para uma matriz n x n;
/// @return Soma dos valores da diagonal principal.
int MainDiagSum(int n, int mat[n][n]);

/// @brief Soma os valores da diagonal secundaria de uma matrix n x n de ints.
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para uma matrix n x n;
/// @return Soma dos valores da diagonal secundaria.
int SecDiagSum(int n, int mat[n][n]);


int ReadMat(int n, int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        };
    };
    return 1;
};

int MainDiagSum(int n, int mat[n][n]) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            /* Observando uma matriz (n x n) de indices i e j começando em 0,
             * percebe-se que os indices i e j sao sempre iguais nos pontos que
             * formam a diagonal principal.
             */
            if (i == j) {
                soma += mat[i][j];
            };
        };
    };
    return soma;
};

int SecDiagSum(int n, int mat[n][n]) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            /* Observando uma matriz (n x n) de indices i e j começando em 0,
             * percebe-se que a soma dos indices i e j sao sempre iguais a n-1
             * nos pontos que formam a diagonal secundaria.
             */
            if (i + j == n-1) {
                soma += mat[i][j];
            };
        };
    };
    return soma;
};

int main () {
    int n = 3;
    int matriz[n][n];

    ReadMat(n, matriz);

    int mainDiagSum = MainDiagSum(n, matriz);
    int secDiagSum = SecDiagSum(n, matriz);

    printf("Soma diagonal principal: %d\n", mainDiagSum);
    printf("Soma diagonal secundaria: %d\n", secDiagSum);

    return 1;
};