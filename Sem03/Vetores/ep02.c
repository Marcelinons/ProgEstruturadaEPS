#include <stdio.h>
#include <stdlib.h>

/** EP03_02

Lê 5 inteiros, armazena-os em um vetor e retorna mostra a média desses valores


- Nicolas M. 10.10.2022
**/

/// Lê um vetor de 5 elementos
void LerVetor(int vet[]);

/// Retorna a média dos valores do vetor de 5 elementos
float CalculaMediaVetor(int vet[]);


void LerVetor(int vet[]) {
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vet[i]);
    };
};

float CalculaMediaVetor(int vet[]) {
    int soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += vet[i];
    };
    float media = soma / 5.0;

    return media;
};

int main() {
    int vetor[5];
    LerVetor(vetor);
    float media = CalculaMediaVetor(vetor);

    // Printar elementos do vetor
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    };

    printf("\n%.2f", media);

    return 0;
};
