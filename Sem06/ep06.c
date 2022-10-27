#include <stdio.h>

/* EP06_06   

 * Preenche os elementos de um vetor de chars de tamanho 5 com um char lido
 * pelo teclado.
 * 
 * NicolasMSilva <27/10/2022>
*/

/// @brief Troca os elementos do vetor pelo dado char.
/// @param v Ponteiro para vetor de 5 elementos char;
/// @param c Ponteiro para char;
void funcao(char *v, char c);

void funcao(char *v, char c) {
    for (int i = 0; i < 5; i++) {
        *(v+i) = c;
    }
}

int main () {
    char v[] = "UFABC", c = 'X';
    
    printf("%s\n", v);

    funcao(v, c);
    
    printf("%s\n", v);
    return 1;
}