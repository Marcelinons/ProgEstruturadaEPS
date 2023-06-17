#include <stdio.h>
#include <stdlib.h>


/** EP_02_06
  *
  * Calcula o harmônico de um dado inteiro.
  *
  * Nicolas Marcelino da Silva
  * 29-09-2022
**/


/// Calcula o harmônico de um inteiro
float Harmonic(int);


float Harmonic(int n) {
    if (n == 0) {
        return 0;
    } else {
        return ((1/(float)n) + Harmonic(n-1));
    }
}

void main() {
    int num=0;
    float harm;
    scanf("%d", &num);

    harm = Harmonic(num);
    printf("%.1f", harm);
}
