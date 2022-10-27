#include <stdio.h>
#include <stdlib.h>

/** EP_02_10
  *
  * Retorna a soma dos N primeiros n�meros naturais
  *
  * Nicolas Marcelino da Silva
  * 03-09-2022
  **/


/// Retorna somat�rio dos N primeiro n�meros naturais
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

