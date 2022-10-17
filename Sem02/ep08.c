#include <stdio.h>
#include <stdlib.h>


/** EP_02_08
  *
  * Calcula o valor de E para um dado N inteiro.
  * E = (1) + (1/2!) + (1/3!) + ... + (1/N!)
  *
  * Nicolas Marcelino da Silva
  * 03-09-2022
**/


/// Retorna o fatorial de um dado n inteiro (recursiva)
int Fatorial(int);

/// Retorna o valor de E usando a equação citada
float CalculaE(int);


int Fatorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return (n * Fatorial(n - 1));
    }
}

float CalculaE(int n) {
    if (n == 0) {
        return 0;
    } else {
        return ((1/(float)Fatorial(n) + CalculaE(n - 1)));
    }
}

void main()
{
    float res;
    int n;

    scanf("%d", &n);

    res = CalculaE(n);
    printf("%.2f\n", res);
}
