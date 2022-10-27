#include <stdio.h>

/* EP03_12
 *
 * - Nicolas M. 13-10-2022
 */

/// @brief Le e imprime uma string de 5 caracteres. Se a string inserida
/// tiver mais do que 5 caracteres, exibe uma mensagem e pede que uma nova
/// string seja inserida.
/// @param str Char list
void FiveCharString(char *str);

/// @brief Conta quantos caracteres uma dada string possui.
/// @param str Char list
/// @return int - quantidade de caracteres em uma string.
int StringLen(char *str);

/// @brief Imprime os elementos de uma lista de maneira invertida
/// @param str Char list
void InversePrint(char *str, int strlen);

void FiveCharString(char *str) {
    int running = 1;
    while (running) {
        scanf("%s", str);
        if (StringLen(str) > 5) {
            printf("Digite novamente a string com ate 5 caracteres:\n");
        } else {
            InversePrint(str, StringLen(str));
            running = 0;
        };
    };
};

int StringLen(char *str) {
    int i, elementos = 0;
    for (i = 0; i < 50; i++) {
        if (str[i] != '\0') {
            elementos++;
        } else {
            break;
        };
    };
    return elementos;
};

void InversePrint(char *str, int strlen) {
    int i;
    for (i = strlen-1; i >= 0; i--) {
        printf("%c ", str[i]);
    };
    printf("\n");
};

void main() {
    char string[50];
    FiveCharString(string);
};