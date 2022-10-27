#include <stdio.h>
#include <stdlib.h>

/** EP_02_11
  *
  * Recebe dois inteiros, n1 e n2, e retorna n1 ^ n2.
  *
  * Nicolas Marcelino da Silva
  * 03-09-2022
  **/

/// Recebe dois inteiros n1 e n2 e retorna n1^n2
int Potencia(int, int);

int Potencia(int n1, int n2) {
    if (n2 == 0) {
        return 1;
    } else {
        return (n1 * Potencia(n1, n2-1));
    }
}

void main() {
    int res, n1, n2;
    scanf("%d%d", &n1, &n2);

    res = Potencia(n1, n2);

    printf("%d", res);
}
