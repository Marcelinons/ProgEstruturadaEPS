#include <stdio.h>

/* EP03_06
 *
 * Nicolas M. 11-10-2022
 */

/// @brief Lê um vetor de n inteiros.
/// @param n Comprimento do vetor;
/// @param v Vetor de n inteiros;
void ReadIntVet(int n, int *v);

/// @brief Printa os elementos de um vetor.
/// @param n Comprimento do vetor;
/// @param v Vetor de n inteiros;
void PrintIntVet(int n, int *v);

/// @brief Subtrai os elementos de um vetor B do vetor A e armazena os
/// resultados em um vetor C.
/// @param n Comprimento dos vetores;
/// @param vetA Vetor A de n inteiros;
/// @param vetB Vetor B de n inteiros que serão subtraídos de A;
/// @param vetC Vetor C de n inteiros contendo os resultados das subtrações;
void SubtractVet(int n, int *vetA, int *vetB, int *vetC);


void ReadIntVet(int n, int *v) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    };
};

void PrintIntVet(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    };
    printf("\n");
};

void SubtractVet(int n, int *vetA, int *vetB, int *vetC) {
    for (int i = 0; i < n; i++) {
        vetC[i] = vetA[i] - vetB[i];
    };
};

void main() {
    int n = 5;
    int vetA[n], vetB[n], vetC[n];
    ReadIntVet(n, vetA);
    ReadIntVet(n, vetB);
    SubtractVet(n, vetA, vetB, vetC);
    PrintIntVet(n, vetC);
};