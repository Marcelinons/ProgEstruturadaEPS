#include <stdio.h>
#include <stdlib.h>

/*
Implemente uma função que RECEBA como parâmetro uma MATRIZ A contendo 3 linhas e 3 colunas. A função deve RETORNAR o ponteiro para um VETOR B de tamanho 3 ALOCADO DINAMICAMENTE, em que cada POSIÇÃO de B é a SOMA dos números de cada COLUNA da matriz. Por fim, os elementos de B devem ser IMPRESSOS no main().
*/

/// @brief Retorna um ponteiro para um vetor dinâmico de 3 inteiros, onde cada
/// elemento do vetor é composto pela soma dos números das colunas da dada
/// matriz. 
/// @param mat_A Pointer para o primeiro elemento da matriz de 3x3; 
/// @return Ponteiro para vetor dinâmico 3 elementos inteiros.
int* funcao(int *mat_A);

void main() 
{
    int *p = NULL;

    int mat[9] = {-8, -3, -4, 1, 2, 3, 8, -4, -1};

    p = funcao(mat);

    for (int i = 0; i < 3; i++) 
    {
        printf("%d ", *(p + i));
    }

    free(p);
    p = NULL;
}

int* funcao(int *mat_A) 
{
    int *p = NULL, count = 0;;
    p = (int *) calloc(3, sizeof(int));

    for (int i = 0; i < 9; i++) 
    {
        if (count > 2) 
        {
            count = 0;
        }
        *(p + count++) += *(mat_A + i);
    }
    return p;
}