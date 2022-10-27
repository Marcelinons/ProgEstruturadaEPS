#include <stdio.h>
#include <stdlib.h>

/** EP_02_10
  *
  * Retorna a soma dos N primeiros números naturais
  *
  * Nicolas Marcelino da Silva
  * 03-09-2022
  **/


/// Retorna somatório dos N primeiro números naturais
int Somatorio(int);

int Somatorio(int n) {
    if (n == 0)
        return 0;
    else
        return n + Somatorio(n-1);
}

void main() {
    int res, n;
    scanf("%d", &n);

    res = Somatorio(n);
    printf("%d", res);
}

