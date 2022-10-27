#include <stdio.h>

/// Calculadora simples.
void main() {
    int operation, n1, n2;
    scanf("%d%d%d", &operation, &n1, &n2);
    switch (operation) {
        case 1:
            printf("O resultado da soma eh: %d\n", n1+n2);
            break;
        case 2:
            printf("O resultado da subtracao eh: %d\n", n1-n2);
            break;
        case 3:
            printf("O resultado da divisao eh: %f\n", (float)n1/n2);
            break;
        case 4:
            printf("O resultado da multiplicacao eh: %d\n", n1*n2);
            break;
        default:
            printf("Numero Invalido!\n");
    }
}