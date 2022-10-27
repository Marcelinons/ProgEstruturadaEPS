#include <stdio.h>

/// @brief Receives two ints and checks which is the largest.
void main() {
    int alunas, alunos;
    scanf("%d%d", &alunas, &alunos);
    if (alunos == alunas) {
        printf("Mesma quantidade!");
    } else if (alunos > alunas) {
        printf("Quantidade de alunos eh maior do que de alunas!");
    } else {
        printf("Quantidade de alunas eh maior do que de alunos!");
    }
}