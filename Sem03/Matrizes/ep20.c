#include <stdio.h>

/* EP03_20
 * 
 * Recebe uma matriz n x m e exibe sua transposta.
 * 
 * - Nicolas M. 13-10-2022
 */

/// @brief Le uma matriz de inteiros n x m.
/// @param n Numero de linhas;
/// @param m Numero de colunas;
/// @param mat Ponteiro para matriz n x m;
/// @return 1.
int ReadMat(int n, int m, int mat[][m]);

/// @brief Calcula a transposta de uma matriz.
/// @param n Numero de linhas da matriz original;
/// @param m Numero de colunas da matriz original; 
/// @param mat Ponteiro para matriz n x m;
/// @param matTrans Ponteiro para matrix m x n;
/// @return 1.
int MatTransposer(int n, int m, int mat[][m], int matTrans[][n]);

/// @brief Printa uma matriz n x m;
/// @param n Numero de linhas;
/// @param m Numero de colunas;
/// @param mat Ponteiro para a matriz;
/// @return 1.
int PrintMat(int n, int m, int mat[][m]);


int ReadMat(int n, int m, int mat[][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        };
    };
    return 1;
};

int MatTransposer(int n, int m, int mat[][m], int matTrans[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Em uma matriz transposta, as coordenadas j sao equivalentes
            // as coordenadas i de uma matriz normal e vice versa.
            // -> As coordenadas se invertem <-
            // i se torna vertical e j horizontal;
            matTrans[j][i] = mat[i][j];
        };
    };
};

int PrintMat(int n, int m, int mat[][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        };
        printf("\n");
    };
};

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    int matriz[n][m], matrizTrans[m][n];   

    ReadMat(n, m, matriz);    
    MatTransposer(n, m, matriz, matrizTrans);
    PrintMat(m, n, matrizTrans);

    return 1;
};
