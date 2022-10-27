#include <stdio.h>

/* EP03_10
 *
 * - Nicolas M. 13-10-2022
*/

/// @brief Le um vetor de n inteiros.
/// @param n Comprimento do vetor;
/// @param v Vetor de n elementos;
void ReadIntVet(int n, int *v);

/// @brief Ordena um vetor de n inteiros em ordem crescente.
/// @param n Comprimento do vetor;
/// @param v Vetor de n elementos;
void OrdenaVet(int n, int *v);

/// @brief Printa os elementos de um vetor de n inteiros
/// @param n Comprimento do vetor;
/// @param v Vetor de n elementos;
void PrintVet(int n, int *v);


void ReadIntVet(int n, int *v) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    };
};

void OrdenaVet(int n, int *v) {
    int i, j, aux;
    // Iteracao da esquerda para direita
    for (i = 0; i < n; i++) {
        // Iteracao da direita para esquerda
        for (j = n-1; j > i; j--) {
            if (v[j] < v[i]) {
                // Inverte a posicao dos elementos v[j] e v[i]
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            };
        };
    };
};

void PrintVet(int n, int *v) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    };
    printf("\n");
};

void main () {
    int n = 10;
    int vetor[n];
    ReadIntVet(n, vetor);
    PrintVet(n, vetor);

    OrdenaVet(n, vetor);
    PrintVet(n, vetor);
};