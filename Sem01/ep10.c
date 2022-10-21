#include <stdio.h>

/// Retorna um dia da semana com base em um inteiro entre 1 e 7 (inclusos).
void main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("Domingo!\n");
            break;
        case 2:
            printf("Segunda-feira!\n");
            break;
        case 3:
            printf("Terca-feira!\n");
            break;
        case 4:
            printf("Quarta-feira!\n");
            break;
        case 5:
            printf("Quinta-feira!\n");
            break;
        case 6:
            printf("Sexta-feira!\n");
            break;
        case 7:
            printf("Sabado!\n");
            break;
        default:
            printf("Numero Invalido!\n");
    }
}