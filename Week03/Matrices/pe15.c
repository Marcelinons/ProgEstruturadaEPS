#include <stdio.h>

/* EP03_15
 * 
 * Le um inteiro m e imprime uma matriz m x m onde todos os valores são 0
 * exceto pela diagonal esquerda, composta por 1's.
 * 
 * - Nicolas M. 13-10-2022
*/

/// @brief Preenche uma matriz m x m de zeros com uma diagonal de uns.
/// @param m Dimensoes da matriz;
/// @param mat Matriz de dimensoes m;
/// @return 1.
int FillZeroMat(int m, int mat[m][m]);

/// @brief Imprime uma matriz m x m
/// @param m Dimensoes da matriz;
/// @param mat Matriz de dimensoes m;
/// @return 1.
int PrintMat(int m, int mat[m][m]);


int FillZeroMat(int m, int mat[m][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            };
        };
    };
    return 1;
};

int PrintMat(int m, int mat[m][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        };
        printf("\n");
    };
};

int main () {
    int m;
    scanf("%d", &m);
    int matriz[m][m];

    FillZeroMat(m, matriz);
    PrintMat(m, matriz);

    return 1;
};