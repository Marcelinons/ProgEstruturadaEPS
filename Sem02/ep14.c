#include <stdio.h>
#include <stdlib.h>

/** EP_02_14
  *
  * Recebe dois naturais e retorna quantas vezes o segundo n�mero aparece dentro
  * do primeiro n�mero.
  *
  * Nicolas Marcelino da Silva
  * 03-09-2022
  **/

/// Conta com que frequ�ncia um n�mero aparece dentro de outro.
int contafreq(int, int);


int contafreq(int num, int digt) {
    int aparece;

    if (num == 0) {
        return 0;

    } else {
        // Se o n�mero � igual, soma 1 � vari�vel 'aparece'
        if (num % 10 == digt) {
            aparece = 1;
        } else {
            aparece = 0;
        }

        num = num / 10;
        printf("%d\n", aparece);
        return aparece + contafreq(num, digt);
    }
}

int main()
{
    int k;
    k = contafreq(1234333323, 3);
    printf("%d", k);
}
