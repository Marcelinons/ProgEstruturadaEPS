#include <stdio.h>

/* EP03_13
 *
 * - Nicolas M. 13-10-2022
*/

/// @brief Conta quantas vogais há em uma dada string de no máximo 8 chars.
/// @param str Lista de char;
int ContaVogal(char *str);

/// @brief Verifica se um dado caractere e uma vogal.
/// @param letter Caractere a ser verificada;
/// @return 1 caso o caractere seja uma vogal; 0 caso contrário
int IsAVowel(char letter);

/// @brief Troca as vogais de uma dada string por outro caractere.
/// @param str String a ter as vogais substituídas;
/// @param letter Caractere que ira substituir as vogais;
void LetterSwapper(char *str, char letter);

/// @brief Conta qual o tamanho de uma string.
/// @param str String a ter o tamanho definido;
/// @return int - Tamanho da string.
int StringLen(char *str);

/// @brief Le uma string
/// @param str Vetor de char;
void ReadString(char *str);

int ContaVogal(char *str) {
    int i, vogais = 0;
    for (i = 0; i < 8; i++) {
        if (IsAVowel(str[i])) {
            vogais++;
        };
    };
    return vogais;
};

int IsAVowel(char letter) {
    char vogais[] = "aeiou";
    int i;
    for (i = 0; i < 5; i++) {
        if (letter == vogais[i]) {
            return 1;
        };
    };
    return 0;
};

void LetterSwapper(char *str, char letter) {
    int i;
    for (i = 0; i < StringLen(str); i++) {
        if (IsAVowel(str[i])) {
            str[i] = letter;
        };
    };
};

int StringLen(char *str) {
    int i, elementos = 0;
    for (i = 0; i < 100; i++) {
        if (str[i] != '\0') {
            elementos++;
        } else {
            break;
        };
    };
    return elementos;
};

void ReadString(char *str) {
    
};

void main () {
    char string[8];
    char letter;
    
    scanf("%s ", string);
    
    scanf("%c", &letter);
    
    printf("A string possui %d vogais.\n", ContaVogal(string));
    
    LetterSwapper(string, letter);
    printf("%s\n", string);
};