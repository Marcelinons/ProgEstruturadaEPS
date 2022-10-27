#include <stdio.h>

/* EP06_07
 *
 * NicolasMSilva <27/10/2022> 
*/

/// @brief Calcula a area e volume de uma esfera de raio r.
/// @param r Raio da esfera;
/// @param area Ponteiro para variavel area;
/// @param volume Ponteiro para variavel volume;
void funcao(float r, float *area, float *volume);


int main () {
    float r = 5, area, volume;

    funcao(r, &area, &volume);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);
    return 1;
}

void funcao(float r, float *area, float *volume) {
    float pi = 3.14;

    *area = 4*pi*r*r;
    *volume = (4*pi*r*r*r)/(float)3;
}


