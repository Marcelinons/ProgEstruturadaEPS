#include <stdio.h>
#include <stdlib.h>

/*
    Recebe do usuario o tamanho e os elemento de uma pilha, entao remove os
    quatro primeiro elementos dessa pilha e os adiciona a uma pilha secundaria.
    Por fim, imprime as duas pilhas apos o procedimento.

    A pilha utilizada tem tamanho maximo 30, sendo uma list aestatica.

    Nicolas Marcelino da Silva, 112020211107, 24/11/2022.
*/

#define arrSize 30
struct pilha {
    int qtd;
    int num[arrSize];
};
typedef struct pilha Pilha;

/// Cria uma nova pilha e retorna um ponteiro para a mesma. Caso haja alguma
/// falha na criacao, retorna um ponteiro nulo.
Pilha* CreatePile(void);

/// Insere um dado inteiro no final da pilha. Retorna 1 caso a insercao seja
/// bem sucedida e 0 caso contrario.
int InsertTop(Pilha *pile, int num);

/// Destroi uma pilha, liberando seu espaco de memoria usado.
void DestroyPile(Pilha *pile);

/// Remove os primeiros quatro elementos da pilha (os ultimo quatro a entrarem)
/// e os adiciona a outra pilha. Retorna 1 caso o processo seja bem sucedido
/// e 0 caso contrario.
int RemoveLastFour(Pilha *pile, Pilha *secPile);

/// Printa os elementos de uma dada pilha.
void PrintPile(Pilha *pile);

int main()
{
    Pilha *p1 = NULL, *p2 = NULL;
    int pSize, num, i;
    /* Cria as duas pilhas e, caso haja algum problema na criacao delas,
     * termina o programa.
     */
    p1 = CreatePile();
    p2 = CreatePile();
    // Caso haja algum problema na criacao das pilhas, termina o programa.
    if (p1 == NULL || p2 == NULL) {
        exit(0);
    }
    // Ler o tamanho da pilha 1 e seus elementos.
    printf("\n----- PRIMEIRA PILHA -----\n\n");
    printf("Tamanho da pilha: ");
    scanf("%d", &pSize);
    for (i = 0; i < pSize; i++) {
        printf("\nInsira novo elemento: ");
        scanf("%d", &num);
        if (InsertTop(p1, num)) {
            printf(">>> INSERCAO BEM SUCEDIDA!\n");
        } else {
            printf(">>> NAO FOI POSSIVEL INSERIR UM NOVO ELEMENTO. A LISTA PODE"
                   " ESTAR CHEIA.\n");
            break;
        }
    }
    printf("\nPILHA RECEBIDA: ");
    PrintPile(p1);
    printf("\n----- OUTPUTS -----\n\n");
    RemoveLastFour(p1, p2);

    printf("PILHA 1 APOS REMOCAO: ");
    PrintPile(p1);
    printf("\nPILHA 2 APOS REMOCAO: ");
    PrintPile(p2);

    // Destruir as duas pilhas.
    DestroyPile(p1);
    DestroyPile(p2);
    printf("\n----- FIM DO PROGRAMA -----\n\n");
    return 0;
}

Pilha* CreatePile(void) {
    Pilha *pile = NULL;
    pile = (Pilha *) malloc(sizeof(Pilha));
    if (pile != NULL) {
        pile->qtd = 0;
    }
    return pile;
}

int InsertTop(Pilha *pile, int num) {
    if (pile == NULL) {
        return 0;
    }
    if (pile->qtd == arrSize) {
        return 0;
    } else {
        pile->num[pile->qtd] = num;
        pile->qtd++;
    }
}

void DestroyPile(Pilha *pile) {
    free(pile);
}

int RemoveTop(Pilha *pile) {
    if (pile == NULL) {
        return 0;
    } else if (pile->qtd == 0) {
        return 0;
    } else {
        pile->qtd--;
        return 1;
    }
}

int RemoveLastFour(Pilha *pile, Pilha *secPile) {
    int i, qtd;
    if (pile == NULL || secPile == NULL) {
        return 0;
    } else if (pile->qtd < 4) {
        printf(">>> O TAMANHO DA PILHA ORIGINAL E MUITO PEQUENO PARA REMOVER "
               "OS QUATRO ULTIMO ELEMENTOS.\n");
        return 0;
    }
    if (pile->qtd == 0 || secPile->qtd == arrSize) {
        return 0;
    } else {
        qtd = pile->qtd;
        for (i = qtd; i > qtd - 4; i--) {
            secPile->num[secPile->qtd] = pile->num[i-1];
            secPile->qtd++;
            pile->qtd--;
        }
        return 1;
    }
}

void PrintPile(Pilha *pile) {
    int i;
    if (pile == NULL) {
        return;
    }
    if (pile->qtd == 0) {
        printf("A lista esta vazia.\n");
        return;
    }
    for (i = 0; i < pile->qtd; i++) {
        printf("%d ", pile->num[i]);
    }
    printf("\n");
}
