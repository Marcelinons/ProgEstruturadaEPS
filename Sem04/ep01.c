#include <stdio.h>
#include <stdlib.h>

/* EP04_01
 *
 * Creates a TypeClient struct to store a client's age and name. Reads from the
 * keyboard a string and int (client's name and age) and prints it.
 *
 * - Nicolas M. 13-10-2022
 */

/// @brief Stores a client's age and name.
typedef struct TypeClient {
    int idade;
    char nome[50];
} Cliente;

int main()
{
    Cliente c;

    fflush(stdin);
    fgets(c.nome, 50, stdin);

    scanf("%d", &c.idade);

    printf("Nome: %sIdade: %d", c.nome, c.idade);
};
