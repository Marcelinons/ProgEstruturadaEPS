#include <stdio.h>
#include <stdlib.h>


/** EP_02_02
  *
  * Recebe um inteiro N e retorna os números naturais ímpares e pares de 0
  * até N.
  *
  * Nicolas Marcelino da Silva
  * 29-09-2022
**/


/// Receives a int n and prints the odd numbers from 0 to n.
void odds(int);


/// Receives a int n and prints the even numbers from 0 to n.
void evens(int);


void odds(int n) {
    int i = 0;
    for (i; i <= n; i++) {
        if (i % 2 != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void evens(int n) {
    int i = 0;
    for (i; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;

    scanf("%d", &n);

    odds(n);
    evens(n);
}
