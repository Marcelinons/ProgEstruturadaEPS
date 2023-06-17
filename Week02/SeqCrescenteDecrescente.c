#include <stdio.h>
#include <stdlib.h>


/** EP_02_01
  *
  * Recebe um inteiro N e retorna uma sequência crescente e decrescente de
  * 0 à N.
  *
  * Nicolas Marcelino da Silva
  * 29-09-2022
**/


/// Receives a int N and outputs all natural numbers from 0 to N.
int DeCrescent(int);

/// Receives a int N and outputs all natural numbers from N to 0.
int Crescent(int, int);


int DeCrescent(int n) {

    if (n == 0) {
        printf("0 ");
        return 0;
    } else {
        printf("%d ", n);
        return DeCrescent(n-1);
    }
}

int Crescent(int n, int c) {

    if (c <= n) {
        printf("%d ", c);
        c++;
        return Crescent(n, c);
    } else {
        printf("\n");
    }
}

int main() {
    int num, c = 0;

    printf("Input a int: ");
    scanf("%d", &num);

    Crescent(num, c);
    DeCrescent(num);
}

/*
#include <stdio.h>

/// Show the first 50 natural numbers
void naturais (int n);

void naturais (int n) {
    if (n <= 50) {
        printf("%d\n", n);
        n++;
        naturais(n);
    }
}

int main() {

    int n = 0;
    printf("First 50 natural numbers:\n");
    naturais(n);

    return 0;
}
*/
