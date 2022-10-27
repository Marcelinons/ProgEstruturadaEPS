#include <stdio.h>

/* EP04_07
 * 
 * Recebe do teclado um inteiro entre 1 e 12 e retorna o respectivo mes do ano
 * e quantos dias este mes possui.
 * 
 * - Nicolas M. 17-10-2022
 *
*/

int main ()
{
    enum MesesDoAno {
        Janeiro = 1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto,
        Setembro, Outubro, Novembro, Dezembro
    } meses;

    scanf("%d", &meses);

    switch (meses)
    {
        case Janeiro:
            printf("Janeiro - 31 dias\n");
            break;
        case Fevereiro: 
            printf("Fevereiro - 28 dias\n");
            break;
        case Marco: 
            printf("Marco - 31 dias\n");
            break;
        case Abril: 
            printf("Abril - 30 dias\n");
            break;
        case Maio: 
            printf("Maio - 31 dias\n");
            break;
        case Junho: 
            printf("Junho - 30 dias\n");
            break;
        case Julho: 
            printf("Julho - 31 dias\n");
            break;
        case Agosto: 
            printf("Agosto - 31 dias\n");
            break;
        case Setembro: 
            printf("Setembro - 30 dias\n");
            break;
        case Outubro: 
            printf("Outubro - 31 dias\n");
            break;
        case Novembro: 
            printf("Novembro - 30 dias\n");
            break;
        case Dezembro: 
            printf("Dezembro - 31 dias\n");
            break;
        default:
            printf("ERRO: Numero invalido.\n");
            break;
    };
    return 1;
};
