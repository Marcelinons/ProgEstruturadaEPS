#include <stdio.h>

/* EP06_05
 *
 * NicolasMSilva <27/10/2022> 
*/

/// @brief Soma os valores de A e B e armazena o valor desta soma na variavel A
/// @param a Ponteiro para inteiro A;
/// @param b Ponteiro para inteiro B;
void funcao(int *a, int *b);

void funcao(int *a, int *b) {
    *a += *b;
}

int main () {
    return 1;
}