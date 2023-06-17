#include <stdio.h>
#include <stdlib.h>

/** EP_02_09
  *
  * Calcula a soma dos n primeiros cubos
  *
  * Nicolas Marcelino da Silva
  * 03-09-2022
  **/

/// Função recursiva para calcular a soma dos primeiro n cubos
int SomaCubos(int n);


int SomaCubos(int n) {
    if (n == 1) {
        return 1;
    } else {
        return (n*n*n + SomaCubos(n-1));
    }
}

int main() {
    int n, res;

    scanf("%d", &n);

    res = SomaCubos(n);
    printf("%d", res);
}
