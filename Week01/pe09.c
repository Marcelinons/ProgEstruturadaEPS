#include <stdio.h>

/// @brief  Receives two ints and says if they're equal or, if its the case,
/// each one is the larger.
void main() {
    int a, b;
    scanf("%d%d", &a ,&b);
    if (a == b) {
        printf("Numeros iguais!\n");
    } else if (a > b) {
        printf("O %d eh o maior numero!\n", a);
    } else {
        printf("O %d eh o maior numero!\n", b);
    }
}