#include <stdio.h>
#include <stdlib.h>


/** EP_02_03
  *
  * Retorna uma contagem regressiva a partir de um int N positivo ou nulo até 0.
  *
  * Nicolas Marcelino da Silva
  * 29-09-2022
**/


/// Receives a int n. Iterates until the input is >= 0.
int GetNum();

/// Recursively prints a countdown from int n to 0.
int Countdown(int);


int GetNum() {
    int c = 1, n = 0;
    while (c) {
        scanf("%d", &n);
        if (n < 0) {
            printf("O numero deve ser >=0!\n");
        } else {
            c = 0;
        }
    }
    return n;
}

int Countdown(int n) {
    if (n == 0) {
        printf("0 ");
        return 0;
    } else {
        printf("%d ", n);
        return Countdown(n - 1);
    }
}

int main() {
    int num = GetNum();

    Countdown(num);
    printf("\nFIM!\n");
}
