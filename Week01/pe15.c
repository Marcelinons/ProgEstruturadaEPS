#include <stdio.h>

/// @brief Receives a year and says wether it is a leap year or not.
void main() {
    int ano;
    scanf("%d", &ano);
    if (ano % 4 == 0) {
        if (ano % 100 != 0) {
            printf("Eh Ano Bissexto!\n");
        } else {
            if (ano % 400 == 0) {
                printf("Eh Ano Bissexto!\n");
            } else {
                printf("Nao Eh Ano Bissexto!\n");
            }
        } 
    } else {
        printf("Nao Eh Ano Bissexto!\n");
    }
}