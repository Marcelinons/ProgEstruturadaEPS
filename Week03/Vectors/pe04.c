#include <stdio.h>
#include <stdlib.h>

/** EP03_04

Le um vetor de n inteiros, le dois indices do vetor e soma os elementos dessas posicoes.

- Nicolas M. 10.10.2022
**/

/// Lê um vetor de n elementos inteiros;
void ReadIntVector(int n, int vet[]);

/// Lê um int índice que seja maior ou igual a 0 e menor que 8.
int GetValIndex(char a);

/// Soma dois elementos da posição x e y de um vetor
int SumElemnts(int x, int y, int vet[]);


void ReadIntVector(int n, int vet[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    };
};

int GetValIndex(char a) {

    int index, invalidIndex = 1;

    while (invalidIndex) {
        scanf("%d", &index);
        if (index < 0 || index >= 8) {
            printf("Valor de %c invalido!\n", a);
        } else {
            invalidIndex = 0;
        };
    };

    return index;
};

int SumElemnts(int x, int y, int vet[]) {
    int soma;
    soma = vet[x] + vet[y];
    return soma;
};


int main() {
    int n = 8, soma;
    int vet[n];
    ReadIntVector(n, vet);
    int x = GetValIndex('X');
    int y = GetValIndex('Y');
    soma = SumElemnts(x, y, vet);
    printf("Soma eh: %d\n", soma);
};
