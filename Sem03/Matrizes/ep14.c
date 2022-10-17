#include <stdio.h>

/* EP03_14
 *
 * Le uma matriz (3x3) de inteiros, encontra o menor e maior valor e mostra suas
 * coordenadas i e j. 
 * 
 * - Nicolas M. 13-10-2022
*/

/// @brief Le uma matrix (n x m);
/// @param n Numero de linhas;
/// @param m Numero de colunas;
/// @param mat Matriz de tamanho n por m;
/// @return 1.
int ReadMat(int n, int m, int mat[n][m]);

/// @brief Encontra o menor valor em uma matriz de inteiros e armazena suas
/// coordenadas i e j em um vetor de 2 elementos.
/// @param n Numero de linhas;
/// @param m Numero de colunas;
/// @param mat Matriz de inteiros (n x m);
/// @param minCoords Vetor de 2 elementos que armazenará as coordenadas i e j
/// do menor valor da matriz;
/// @return Menor inteiro da matriz.
int MinMat(int n, int m, int mat[n][m], int *minCoords);

/// @brief Encontra o maior valor em uma matriz de inteiros e armazena suas
/// coordenadas i e j em um vetor de 2 elementos.
/// @param n Numero de linhas;
/// @param m Numero de colunas;
/// @param mat Matriz de inteiros (n x m);
/// @param maxCoords Vetor de 2 elementos que armazena as coordenadas i e j
/// do maior valor da matriz;
/// @return Maior inteiro da matriz;
int MaxVet(int n, int m, int mat[n][m], int *maxCoords);

int ReadMat(int n, int m, int mat[n][m]) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        };
    };
    return 1;
};

int MinMat(int n, int m, int mat[n][m], int *minCoords) {
    // Condicoes iniciais
    int menor = mat[0][0];
    minCoords[0] = 0;
    minCoords[1] = 0;

    /// Percorrer a matriz e atualizar menor, minCoords, se necessario
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] < menor) {
                menor = mat[i][j];
                minCoords[0] = i;
                minCoords[1] = j;
            };
        };
    };
    return menor;
};

int MaxMat(int n, int m, int mat[n][m], int *maxCoords) {
    // Condicoes iniciais
    int maior = mat[0][0];
    maxCoords[0] = 0;
    maxCoords[1] = 0;

    // Percorrer a matriz e atualizar maior, maxCoords, se necessario
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] > maior) {
                maior = mat[i][j];
                maxCoords[0] = i;
                maxCoords[1] = j;
            };
        };
    };
    return maior;
};

int main() {
    int n = 3, m = 3;
    int matriz[n][m];
    int minCoords[2], maxCoords[2];
    
    ReadMat(n, m, matriz);

    int maiorValor = MaxMat(n, m, matriz, maxCoords);
    printf("Maior: %d\n", maiorValor);
    printf("Posicao (maior): %d linha e %d coluna\n",
        maxCoords[0], maxCoords[1]);

    int menorValor = MinMat(n, m, matriz, minCoords);
    printf("Menor: %d\n", menorValor);
    printf("Posicao (menor): %d linha e %d coluna\n",
        minCoords[0], minCoords[1]);

    return 1;
};
