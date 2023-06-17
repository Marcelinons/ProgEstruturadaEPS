#include <stdio.h>
#include <stdlib.h>

/** EP_02_16
  *
  * Calcula o superfatorial de um dado N natural.
  * O superfatorial de um número é como um "fatorial de fatoriais";
  *
  * Nicolas Marcelino da Silva
  * 04-10-2022
  **/

/// Retorna o superfatorial de um N
long superfatorial(int);


long superfatorial(int n) {

    int aux = n, fat=1;

    if (n == 0) {
        return 1;
    } else {
        // Calcular o fatorial de n
        while (aux > 1) {
            fat *= aux;
            aux--;
        }
        // Retornar o fatorial de n multiplicado pelo fatorial de n-1...
        return fat * superfatorial(n-1);
    }
}

void main()
{
    int k = superfatorial(4);
    printf("%d", k);
}
