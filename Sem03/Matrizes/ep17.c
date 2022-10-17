#include <stdio.h>
#include <math.h>

/* EP03_17
 * 
 * Le o numero de linhas n e o numero de colunas m e imprime uma matriz cujos
 * indices seguem a seguinte logica:
 * a) A[i][j] = 2i + 7j – 2 se i < j;
 * b) A[i][j] = 3i^2 – 1 se i = j;
 * c) A[i][j] = 4i^3 + 5j^2 + 1 se i > j.
 * 
 * - Nicolas M. 13-10-2022
*/

/// @brief Preenche uma matriz de inteiros n x m seguindo a logica descrita no
/// cabeçalho.
/// @param n Numero de linhas;
/// @param m Numero de colunas;
/// @param mat Ponteiro para uma matriz n x m;
/// @return 1.
int FillMat(int n, int m, int mat[n][m]);

/// @brief Imprime uma matriz de inteiros n x m.
/// @param n Numero de linhas;
/// @param m Numero de colunas;
/// @param mat Ponteiro para uma matrix n x m;
/// @return 1.
int PrintMat(int n, int m, int mat[n][m]);


int FillMat(int n, int m, int mat[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < j) {
                mat[i][j] = 2*i + 7*j - 2;
            } else if (i > j) {
                mat[i][j] = 4*pow(i, 3) + 5*pow(j, 2) + 1;
            } else {
                mat[i][j] = 3*pow(i, 2) - 1;
            }; 
        };
    };
    return 1;
};

int PrintMat(int n, int m, int mat[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        };
        printf("\n");
    };
};


int main () {
    int lin, col;
    scanf("%d%d", &lin, &col);
    int matriz[lin][col];

    FillMat(lin, col, matriz);
    PrintMat(lin, col, matriz);

    return 1;
};