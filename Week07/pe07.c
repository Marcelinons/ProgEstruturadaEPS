#include <stdio.h>
#include <stdlib.h>

char* funcao(char *str);

void main(void) 
{
    char str[6], *p = NULL;
    scanf("%s", str);
    p = funcao(str);

    for (int i = 0; *(p + i) != '\0'; i++) 
    {
        printf("%c ", *(p + i));
    }

    free(p);
    p = NULL;
}

char* funcao(char *str) 
{
    char *p = NULL;
    int auxInd;
    p = (char *) malloc(7 * sizeof(char));

    // Get the index of the last element on the string.
    for (int i = 0; *(str + i) != '\0'; i++) 
    {
        auxInd = i + 1;
    }
    // The last position of p must be \0.
    *(p + auxInd) = '\0';

    for (int i = 0; i < auxInd; i++) 
    {
        *(p + i) = *(str + auxInd-1 - i);
    }
    return p;
}