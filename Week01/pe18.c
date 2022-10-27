//#include "sequencia.h" // Moodle's library
#include <stdio.h>

/// Recebe dois valores inteiros e um char, este indicando que tipo de operação
/// deverá ser realizada (adição, subtração, multiplicação, divisão) e retorna o
/// resultado desta operação.
/// Retorna 0 caso o símbolo seja diferente dos 4 esperados.
float operacao(float n1, float n2, char simb);

float operacao(float n1, float n2, char simb) {
    switch (simb) {
        case '+': ;
            float soma = n1 + n2;
            return soma;
        case '-': ;
            float sub = n1 - n2;
            return sub;
        case '*': ;
            float mult = n1*n2;
            return mult;
        case '/': ;
            float div = n1/n2;
            return div;
        default: // Caso o símbolo de entrada seja diferente de +, -, * ou /;
            return 0.0;
    }
}