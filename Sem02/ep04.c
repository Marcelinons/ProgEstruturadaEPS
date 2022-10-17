#include <stdio.h>
#include <stdlib.h>


/** EP_02_04
  *
  * L� um c�digo de opera��o:
  *
  * 1 = (a+b)
  * 2 = (a+b+c)
  * 3 = (a*b)
  * 0 = sair
  *
  * Se o usu�rio digitar a opera��o SAIR (0), o programa mostra o MENOR
  * resultado obtido, considerando SOMENTE as opera��es realizadas, e ENCERRA.
  * Entretanto, caso NENHUM C�digo de Opera��o seja selecionado, a seguinte
  * mensagem � impressa: "Nenhum calculo foi realizado!". Caso contr�rio,
  * solicitar� a ENTRADA dos n�meros (a e b OU a, b e c) e imprimir� o
  * resultado da opera��o (soma ou multiplica��o). Ap�s isso, o programa volta
  * a SOLICITAR o C�digo de Opera��o para o usu�rio digitar uma NOVA OPERA��O.
  *
  * Nicolas Marcelino da Silva
  * 04-10-2022
  **/


/// Recebe como par�metro a opera��o e retorna o resultado.
int RealizaOperacao(int *, int);

/// Valida a entrada da operacao.
///
/// Se a entrada for diferente de 1, 2, 3 ou 0, retorna 0. Caso contr�rio,
/// retorna 1.
int ValidaOperacao(int operacao);


int RealizaOperacao(int *run, int op) {

    int a, b, c, res;

    switch (op) {
    case 1:
        scanf("%d", &a);
        scanf("%d", &b);

        res = a+b;
        printf("(a+b) = %d\n", res);
        break;
    case 2:
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);

        res = a+b+c;
        printf("(a+b+c) = %d\n", res);
        break;
    case 3:
        scanf("%d", &a);
        scanf("%d", &b);

        res = a*b;
        printf("(a*b) = %d\n", res);
        break;
    case 0:
        *run = 0;
        break;
    }
    return res;
}

int ValidaOperacao(int op) {

    if (op != 1 && op != 2 && op != 3 && op != 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    int running = 1, menor, res;
    int first = 1; // Para verificar se � a primeira itera��o

    while (running) {
        int operacao;

        scanf("%d", &operacao);

        if (ValidaOperacao(operacao)) {
            printf("ERRO: Entrada invalida.\n");
            continue;
        }

        if (first && operacao == 0) {
            // Se for escolhido 0 na primeira vez, retorna a msg:
            printf("Nenhum calculo foi realizado!\n");
            return 0;
        }

        res = RealizaOperacao(&running, operacao);

        // Verifica qual foi o menor resultado at� agora;
        if (first) {
            menor = res;
        } else if (res < menor) {
            menor = res;
        }
        first = 0;
    }
    printf("Menor resultado: %d\n", menor);
    return 0;
}
