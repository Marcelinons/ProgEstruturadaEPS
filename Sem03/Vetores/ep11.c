#include <stdio.h>

/* EP03_11
 *
 * - Nicolas M. 13-10-2022
 */

/// @brief Le uma string de 8 caracteres. Se a string inserida nao tiver 8
/// caracteres, exibe uma mensagem e pede que uma nova string seja inserida.
/// @param str Char list
void EightCharString(char *str);

/// @brief Conta quantos caracteres uma dada string possui.
/// @param str String a ser contada.
/// @return int - quantidade de caracteres em uma string.
int StringLeng(char *str);

/// @brief Printa os 4 primeiros elementos de uma dada string
/// @param str String
void PrintFirstFour(char *str);

void EightCharString(char *str) {
    int running = 1;
    while (running) {
        scanf("%s", str);
        if (StringLeng(str) != 8) {
            printf("Voce digitou uma string com %d caractere(s)!\n",
                StringLeng(str));
            printf("A string deve ter 8 caracteres. Por favor, "
                "digite uma nova string:\n");
        } else {
            PrintFirstFour(str);
            running = 0;
        };
    };
};

int StringLeng(char *str) {
    int i, elements = 0;
    for (i = 0; i < 50; i++) {
        // Conta até que o caractere \0 seja encontrado.
        if (str[i] != '\0') {
            elements++;
        } else {
            break;
        };
    };
    return elements;
};

void PrintFirstFour(char *str) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("%c", str[i]);
    };
    printf("\n");
};

void main() {
    char str[50];
    EightCharString(str);
};
