#include <stdio.h>

/* EP06_03
 *
 * NicolasMSilva <27/10/2022>
*/

/// @brief Troca os valores das variaveis ponteiro a e b.
/// @param a Ponteiro para inteiro a;
/// @param b Ponteiro para inteiro b;
void funcao(int *a, int *b);

void funcao(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}


int main () {
    int x = 3, y = 5, *xp, *yp;

    xp = &x;
    yp = &y; 
    
    printf("Antes:\n%d, %d\n", *xp, *yp);

    funcao(xp, yp);

    printf("Depois:\n%d, %d\n", *xp, *yp);
    
    return 1;
}