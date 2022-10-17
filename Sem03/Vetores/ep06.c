#include <stdio.h>

/* EP03_06
 *
 * Nicolas M. 11-10-2022
 */

/// @brief Lê um vetor de n floats.
/// @param n Comprimento do vetor;
/// @param v Vetor de n elementos do tipo float;
void ReadFloatVet(int n, float *v);

/// @brief Printa os elementos de um vetor de comprimento n.
/// @param n Comprimento do vetor;
/// @param v Vetor de n elementos do tipo float;
void PrintVet(int n, float *v);

/// @brief Soma os números positivos de um dado vetor.
/// @param n Comprimento do vetor;
/// @param v Vetor de n elementos do tipo float;
/// @return Somatório dos números positivos.
float SumPosi(int n, float *v);

/// @brief Conta a quantidade de números negativos em um vetor.
/// @param n Comprimento do vetor;
/// @param v Vetor de n elementos do tipo float;
/// @return Total de números negativos.
int NegCount(int n, float *v);


void ReadFloatVet(int n, float *v) {
    for (int i = 0; i < n; i++) {
        scanf("%f", &v[i]);
    };
};

void PrintVet(int n, float *v) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", v[i]);
    };
    printf("\n");
};

float SumPosi(int n, float *v) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            soma += v[i];
        };
    };
    return soma;
};

int NegCount(int n, float *v) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < 0) {
            soma++;
        };
    };
    return soma;
};

void main() {
    int n = 5;
    float vetor[n];

    ReadFloatVet(n, vetor);
    int negatives = NegCount(n, vetor);
    float soma = SumPosi(n, vetor);

    PrintVet(n, vetor);
    printf("%d\n", negatives);
    printf("%.2f\n", soma);
};