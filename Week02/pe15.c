#include <stdio.h>
#include <stdlib.h>

/** EP_02_15
  *
  * Converte um natural em base decimal para base binária
  *
  * Nicolas Marcelino da Silva
  * 03-09-2022
  **/

/// Converte decimal para binário
int dec2bin(int);


int dec2bin(int n_dec) {

    if (n_dec == 0) {
        return 0;
    } else {

        if (n_dec % 2 == 0) {
            return dec2bin(n_dec/2)*10;
        } else {
            return 1 + dec2bin(n_dec/2)*10;
        }
    }
}

int main() {
    int k = dec2bin(5);
    printf("%d", k);
}
