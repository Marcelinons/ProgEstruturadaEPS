#include <stdio.h>
#include <stdlib.h>


/** EP_02_07
  *
  * Retorna a pirâmide de Floyd para um dado N inteiro.
  *
  * Exemplo: N = 6:
  *
  * 1...
  * 2...3...
  * 4...5...6...
  * 7...8...9...10..
  * 11..12..13..14..15..
  * 16..17..18..19..20..21..
  *
  * Nicolas Marcelino da Silva
  * 29-09-2022
**/

/*
 Cada linha imprime a mesma quantidade de números; por exemplo na linha 3
 são impressos 3 números, na 4° são impressos 4, etc.
*/

void main() {
    int n, count = 1;

    //printf("Input n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // Controla as linhas
        for (int j = 0; j <= i; j++) { // Controla quantos números sao impressos

            printf("%d", count);

            if (count < 10) {
                printf("...");
            } else if (count >= 10 && count < 100) {
                printf("..");
            } else {
                printf(".");
            }
            count++;
        }
        printf("\n");
    }
}
