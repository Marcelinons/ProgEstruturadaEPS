#include <stdio.h>

/// @brief Encontra o maior elemento de um vetor e conta quantas vezes ele
/// aparece.
/// @param vet Ponteiro para um vetor de inteiros de tamanho N;
/// @param tam Tamanho do vetor;
/// @param maior Ponteiro para variavel que ira armazenar o maior elemento do
/// vetor;
/// @return Quantidade de vezes que o maior elemento aparece no vetor. 
int funcao (int *vet, int tam, int *maior);

int main() {
    int tam, maior;

    printf("Tamanho do vetor: ");
    scanf("%d", &tam);

    int vet[tam];

    int qauntasvezes = funcao(vet, tam, &maior);
    
    printf("%d", qauntasvezes);

    return 1;
}

int funcao(int *vet, int tam, int *maior) {
    int qntVezes = 0;

    for (int i = 0; i < tam; i++) {
        scanf("%d", (vet + i));
        
        // Encontrar o maior valor
        if (i == 0) {
            *maior = *(vet + i);
        } else if (*(vet + i) > *maior) {
            *maior = *(vet + i);
            qntVezes = 0;
        }

        // Contar quantas vezes o maior valor aparece
        if (*maior == *(vet+i)) {
            qntVezes++;
        }
    }
    return qntVezes;
}