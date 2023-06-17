#include <stdio.h>

/* EP03_05
 * Le vetor de N elementos, mostra quantos elementos sao pares e quantos sao impares;
 * Este codigo esta incabado.
 * Nicolas M. 11-10-2022
 */

/// @brief Lê um vetor de n inteiros
/// @param n Quantidade de elementos no vetor 
/// @param v Vetor de n elementos
void ReadIntVector(int n, int *v);

/// @brief Imprime os elementos de um vetor de n inteiros
/// @param n Quantidade de elementos no vetor
/// @param v Vetor de n elementos
void PrintVector(int n, int *v);

/// @brief Retorna o maior valor de um vetor de inteiros
/// @param n Quantidade de elementos no vetor
/// @param v Vetor de n elementos
int MaxVet(int n, int *v);

/// @brief Retorna o menor valor de um vetor de inteiros
/// @param n Quantidade de elementos no vetor
/// @param v Vetor de n elementos
int MinVet(int n, int *v);

/// @brief Imprime os elementos ímpares de um vetor de n inteiros
/// @param n Quantidade de elementos no vetor
/// @param v Vetor de n elementos
void PrintOddNums(int n, int *v); 

/// @brief Imprime os elementos pares de um vetor de n inteiros
/// @param n Quantidade de elementos no vetor
/// @param v Vetor de n elementos
void PrintPairNums(int n, int *v);

/// @brief Verifica se um dado número está dentro de um vetor de N elementos
/// @param n Quantidade de elementos no vetor
/// @param v Vetor de n elementos
/// @param numToCheck Número cuja presença será verificada
/// @returns 1 se o número está; 0 caso contrário
int CheckNumInVet(int n, int *v, int numToCheck);

/// @brief Limpa o lixo de um vetor.
/// Note que, no contexto desse código, o vetor de retorno é util apenas para
/// receber valores diferentes de -1.
/// @param n Quantidade de elementos no vetor
/// @param v Vetor de n elementos
/// @returns Vetor com todos os elementos = -1
void TrashCleaner(int n, int *v);


void ReadIntVector(int n, int *v) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    };
};

void PrintVector(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    };
    printf("\n");
};

int MaxVet(int n, int *v) {
    int maior = v[0];
    for (int i = 0; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        };
    };
    return maior;
};

int MinVet(int n, int *v) {
    int menor = v[0];
    for (int i = 0; i < n; i++) {
        if (v[i] < menor) {
            menor = v[i];
        };
    };
    return menor;
};

void PrintOddNums(int n, int *v) {
    int oddNums[n], counter = 0;
    TrashCleaner(n, oddNums);

    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) {
            if (CheckNumInVet(n, oddNums, v[i])) {
                continue;
            } else {
                printf("%d\n", v[i]);
                oddNums[counter] = v[i];
                counter++;
            };
        };
    };
};

void PrintPairNums(int n, int *v) {
    int pairNums[n], counter = 0;
    //TrashCleaner(n, pairNums);

    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            if (CheckNumInVet(n, pairNums, v[i])) {
                continue;
            } else {
                printf("%d\n", v[i]);
                pairNums[counter] = v[i];
                counter++;
            };
        };
    };
};

int CheckNumInVet(int n, int *v, int numToCheck) {
    for (int i = 0; i < n; i++) {
        if (numToCheck == v[i]) {
            return 1;
        };
    };
    return 0;
};

void TrashCleaner(int n, int *v) {
    for (int i = 0; i < n; i++) {
        v[i] = -1;
    };
};

void main() {
    
    int n = 10;
    int vetor[n];
    ReadIntVector(n, vetor);

    PrintVector(n, vetor);

    TrashCleaner(n, vetor);

    PrintVector(n, vetor);

    printf("Numeros Pares:\n");
    PrintPairNums(n, vetor);
    
    printf("Numeros Impares:\n");
    PrintOddNums(n, vetor);

    printf("Maior: %d\n", MaxVet(n, vetor));
    printf("Menor: %d\n", MinVet(n, vetor));
};
