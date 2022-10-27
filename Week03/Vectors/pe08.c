#include <stdio.h>

/* EP03_08
 *
 * Nicolas M. 11-10-2022
 */

/// @brief Le um vetor de n elementos inteiros.
/// @param n Comprimento do vetor;
/// @param v Vetor de inteiros de comprimento n;
void ReadIntVet(int n, int *v);

/// @brief Printa os números que se repetem em um dado vetor de inteiros
/// @param n Comprimento do vetor;
/// @param v Vetor de inteiros;
void UniqueVet(int n, int *v);

/// @brief Verifica se um dado num esta dentro de um vetor de n elementos
/// @param n Comprimento do vetor
/// @param num Numero cuja presença sera verificada
/// @param v Vetor de n elementos
/// @return 1 caso o numero nao esteja no vetor, 1 caso contrario.
int NumNotInVet(int n, int num, int *v);

/// @brief Troca os elementos de um vetor de inteiros por 0 a fim de remover
/// o lixo. Permite melhor controle sobre os valores do vetor e maior controle
/// sobre as condicionais a serem impostas.
/// @param n Comprimento do vetor;
/// @param v Vetor de inteiros;
void GarbRemover(int n, int *v);

/// @brief Printa os valores de um vetor de inteiros.
/// @param n Comprimento do vetor;
/// @param v Vetor de inteiros;
void PrintVet(int n, int *v);


void ReadIntVet(int n, int *v) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    };
};

void UniqueVet(int n, int *v) {
    // Booleanos
    int allAreDif = 1;
    int firstZero = 1;

    // Contador de quantos numeros se repetem
    int repetidos = 0;
    
    // Vetor onde os numeros repetidos serão armazenados
    int repVet[n];
    
    GarbRemover(n, repVet);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
        
            if (v[i] == v[j] && i != j) {
                
                /* Devido ao metodo GarbRemover, que substitui todos os valores
                 * do vetor por 0, afim de remover o lixo, o primeiro input = 0
                 * deve ser tratado como um caso a parte.
                 */ 
                if (v[j] == 0 && firstZero) {
                    repVet[repetidos] = 0;
                    repetidos ++;
                    firstZero = 0;
                };

                if (NumNotInVet(n, v[j], repVet)) {
                    repVet[repetidos] = v[j];
                    repetidos++;
                };
                allAreDif = 0; // Algum numero se repetiu
            };
        };
    };

    if (allAreDif) {
        printf("Nao existem valores iguais!\n");
    } else {
        for (int i = 0; i < repetidos; i++) {
            printf("%d\n", repVet[i]);
        };
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

void PrintVet(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    };
    printf("\n");
};

void main() {
    int n = 6;
    int vetor[n];
    ReadIntVet(n, vetor);
    PrintVet(n, vetor);
    UniqueVet(n, vetor);
};