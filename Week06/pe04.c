#include <stdio.h>

/* EP06_04
 *
 * Recebe dois valores do teclado;
*/

/// @brief Se o valor de b foi maior que o de a, inverte seus valores.
/// @param a Ponteiro para inteiro a;
/// @param b Pointeiro para inteiro b;
void funcao(int *a, int *b);

void funcao(int *a, int *b) {
    if (*b > *a) {
        int aux = *a;
        *a = *b;
        *b = aux;
    }
}

int main () {
    int a = 4, b = 2;
    printf("Antes:\n%d, %d\n", a, b);
    funcao(&a, &b); 
    printf("Depois:\n%d, %d\n", a, b);
    return 1;
}