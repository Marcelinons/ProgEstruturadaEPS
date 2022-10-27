#include <stdio.h>
#include <stdlib.h>

/** EP_02_17
  *
  * Nicolas Marcelino da Silva
  * 04-10-2022
  **/

/// Retorna o produto de dois inteiros usando o algoritmo de
/// multiplicação Russa (ou multiplicação etíope)
int multiplicacao_russa(int, int);

int multiplicacao_russa(int a, int b) {

    if (a == 0) {
        return 0;
    } else {
        if (a % 2 != 0) {
            return b + multiplicacao_russa(a/2, b*2);
        }
        return multiplicacao_russa(a/2, b*2);
    }
}

int main()
{
    int k, a, b;
    scanf("%d%d", &a, &b);
    k = multiplicacao_russa(a, b);
    printf("%d", k);
}
