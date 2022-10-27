#include <stdio.h>

/* EP03_19
 * 
 * Recebe uma matriz n x n e determina se é triangular superior, inferior,
 * diagonal ou nenhum destes.
 * 
 * - Nicolas M. 13-10-2022
 */

/// @brief Le uma matriz de inteiros n x n.
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para matriz n x n;
/// @return 1.
int ReadMat(int n, int mat[][n]);

/// @brief Imprime uma matriz de inteiros n x n.
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para matriz n x n;
/// @return 1.
int PrintMat(int n, int mat[][n]);

/// @brief Verifica se uma dada matriz é uma matriz triangular superior;
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para matriz n x n;
/// @return 1 caso seja triangular superior; 0 caso contrario.
int IsUpperTriangular(int n, int mat[][n]);

/// @brief Verifica se uma dada matriz é uma matriz triangular inferior;
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para matriz n x n;
/// @return 1 caso seja triangular inferior; 0 caso contrário.
int IsLowerTriangular(int n, int mat[][n]);

/// @brief Classifica uma dada matriz n x n de inteiros como triangular
/// superior, triangular infeior, matriz diagonal ou nenhuma destes.
/// @param n Dimensoes da matriz;
/// @param mat Ponteiro para matriz n x n;
/// @return 1.
int MatrixClassifier(int n, int mat[][n]);


int ReadMat(int n, int mat[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        };
    };
    return 1;
};

int PrintMat(int n, int mat[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        };
        printf("\n");
    };
    return 1;
};

int IsUpperTriangular(int n, int mat[][n]) {
    for (int i = n-1; i > 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            if (mat[i][j] != 0) {
                return 0;
            };
        };
    };
    return 1;
};

int IsLowerTriangular(int n, int mat[][n]) {
    for (int j = n-1; j > 0; j--) {
        for (int i = j-1; i >= 0; i--) {
            if (mat[i][j] != 0) {
                return 0;
            };
        };
    };
    return 1;
};

int MatrixClassifier(int n, int mat[][n]) {
    int upperTri = IsUpperTriangular(n, mat);
    int lowerTri = IsLowerTriangular(n, mat);
    
    if (upperTri && !(lowerTri)) {
        printf("Matriz Triangular Superior!!!\n");
    } else if (!(upperTri) && lowerTri) {
        printf("Matriz Triangular Inferior!!!\n");
    } else if (upperTri && lowerTri) {
        printf("Matriz Diagonal!!!\n");
    } else {
        printf("Nao se Enquadra!!!\n");
    };
    return 1;
};

int main() {
    int n = 4;
    int matriz[n][n];

    ReadMat(n, matriz);
    printf("\n -------------- Resultados ------------- \n");
    PrintMat(n, matriz);
    printf("\n");
    MatrixClassifier(n, matriz);
    return 1;
};

/* Testes Rápidos (n = 4)
--- Diag
1
0
0
0
0
2
0
0
0
0
3
0
0
0
0
4
--- Nao se enquadra
1
2
3
4
5
6
7
8
9
10
11
12
15
16
0
-6
--- Triag Sup
1
2
3
4
0
5
6
7
0
0
8
9
0
0
0
10
--- Triag Inf
1
0
0
0
3
5
0
0
7
8
9
0
11
10
-9
13
*/