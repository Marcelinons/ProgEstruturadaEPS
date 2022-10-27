#include <stdio.h>
#include <stdlib.h>

/** EP3_01
  *
  * Lê 6 valores inteiros, adiciona-os a um vetor e imprime o vetor e o vetor em
  * ordem inversa.
  *
  * - Nicolas M. 10102022
  **/

void main() {
    int i, vetor[6];

    // Recebe os valores do vetor
    for (i = 0; i < 6; i++) {
        scanf("%d", &vetor[i]);
    };

    // Printa os valores do vetor
    printf("Vet=\n");
    for (i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    };
    
    // Printa os valores do vetor em ordem inversa
    printf("\nOrdem Inversa=\n");
    for (i = 5; i >= 0; i--) {
        printf("%d ", vetor[i]);
    };

};
