#include <stdio.h>

/* EP06_02
 * 
 * Compara o valor de dois enderecos de memoria, A e B. Imprime qual o maior.
 * 
 * NicolasMSilva <27/10/2022>
*/

int main () {
    int x = 2, y = 3;

    int* px = NULL;
    int* py = NULL;

    px = &x;
    py = &y;

    if (px > py) {
        printf("A\n");
    } else {
        printf("B\n");
    }

    return 1;
}