#include <stdio.h>
#include <stdlib.h>

/** EP03_03

- Nicolas M. 10.10.2022
**/


/// Lê 6 valores inteiros e os armazena num vetor
void LerVetor(int v[]);

/// Printa um vetor de n elementos
void PrintarVetor(int n, int vet[]);


void LerVetor(int v[]) {
    for (int i = 0; i < 6; i++) {
        scanf("%d", &v[i]);
    };
};

void PrintarVetor(int n, int vet[]) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", vet[i]);
    };
};

int main() {
    int A[6], soma;
    LerVetor(A);
    soma = A[0] + A[1] + A[5];
    printf("A soma eh: %d.\n", soma);
    A[4] = 100;
    PrintarVetor(6, A);
};
