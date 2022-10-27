#include <stdio.h>

/// Verifica paridade de um dado número inteiro.
void main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("Numero NEUTRO!\n");
    } else if (n % 2 == 0) {
        printf("Numero PAR!\n");
    } else {
        printf("Numero IMPAR!\n");
    }
}