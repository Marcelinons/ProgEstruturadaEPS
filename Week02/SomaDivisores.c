#include <stdio.h>
#include <stdlib.h>

/** EP_02_05
  *
  * Recebe um inteiro e retorna a soma de todos os divisores desse número.
  *
  * Nicolas Marcelino da Silva
  * 29-09-2022
**/


/// Encontra os divisores de um dado n e os soma.
int SomaDivs(int);


int SomaDivs(int n) {
    int soma=0;

    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}

void main() {
    int n, res;

    scanf("%d", &n);

    res = SomaDivs(n);
    printf("%d\n", res);
}
