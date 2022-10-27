#include <stdio.h>
#include <stdlib.h>

/** EP_02_12
  *
  * Recebe dois inteiros, n1 e n2, e n1*n2 por meio de somas sucessivas.
  *
  * Nicolas Marcelino da Silva
  * 03-09-2022
  **/

/// Recebe dois inteiros e retorna n1*n2 por meio de somas sucessivas
int soma(int, int);


int soma(int n1, int n2){
    if (n2 == 0) {
        return 0;
    } else {
        return n1 + soma(n1, n2-1);
    }
}

void main() {
    int res, n1, n2;
    scanf("%d%d", &n1, &n2);
    res = soma(n1, n2);
    printf("%d", res);
}
