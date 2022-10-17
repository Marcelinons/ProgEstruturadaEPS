#include <stdio.h>

/* EP03_09
 *
 * - Nicolas M. 12-10-2022
 */

/// @brief Lê um vetor em que os elementos são todos diferentes.
/// @param n Comprimento do vetor.
/// @param v Vetor de tamanho n.
void ReadUniqueVet(int n, int *v);

/// @brief Printa os elementos de um vetor de inteiros
/// @param n Comprimento do vetor
/// @param v Vetor de inteiros
void PrintVet(int n, int *v);

/// @brief Verifica se um dado num está dentro de um vetor de n elementos
/// @param n Comprimento do vetor
/// @param num Número cuja presença será verificada
/// @param v Vetor de n elementos
/// @return 1 caso o número não esteja no vetor, 1 caso contrário.
int NumNotInVet(int n, int num, int *v);

/// @brief Troca os elementos de um vetor de inteiros por 0 a fim de remover
/// o lixo. Permite melhor controle sobre os valores do vetor e maior controle
/// sobre as condicionais a serem impostas.
/// @param n Comprimento do vetor;
/// @param v Vetor de inteiros;
void GarbRemover(int n, int *v);

void ReadUniqueVet(int n, int *v) {
    int count = 0, aux, firstZero = 1;

    while (count < n) {
        scanf("%d", &aux);
        if (aux == 0 && firstZero) {
            firstZero = 0;
            v[count] = 0;
            count++;
        } else if (NumNotInVet(count+1, aux, v)) {
            v[count] = aux;
            count++;
        } else {
            printf("Numero já digitado! Digite outro numero!\n");
        };
    };
};

void PrintVet(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    };
};

int NumNotInVet(int n, int num, int *v) {
    for (int i = 0; i < n; i++) {
        if (num == v[i]) {
            return 0;
        };
    };
    return 1;
};

void GarbRemover(int n, int *v) {
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    };
};

void main() {
    int n = 10;
    int vetor[n];
    GarbRemover(n, vetor);
    ReadUniqueVet(n, vetor);
    PrintVet(n, vetor);
};