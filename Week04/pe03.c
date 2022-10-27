#include <stdio.h>
#include <stdlib.h>

/* EP04_03
 *
 * Cria uma estrutura RegistroAluno que armazena o numero de matricula, nome,
 * notas e a media de um aluno. Encontra a maior media e printa as informacoes
 * do aluno que apresentar essa media.
 *
 * - Nicolas M. 13-10-2022
*/

/// @brief Armazena o numero de matricula, nome, notas e media de um aluno
typedef struct ModelRegistroAluno
{
    int matricula;
    char nome[50];
    float notas[3];
    float media;
} RegistroAluno;

/// @brief Le os dados de n alunos e os armazena em instancias da struct
/// RegistroAluno.
/// @param n Quantidade de alunos;
/// @param aluno Ponteiro para a structure
void ReadStdtData(int numAlunos, RegistroAluno *aluno);

/// @brief Retorna a maior media entre os alunos;
/// @param numAlunos Quantidade da alunos;
/// @param aluno Ponteiro para a structure
/// @return float: Maior media.
float EncontraMaiorMedia(int numAlunos, RegistroAluno *aluno);

/// @brief Mostra as informacoes do(s) aluno(s) que obtiveram a maior media
/// @param numAlunos Quantidade de alunos;
/// @param aluno Ponteiro para a structure
void MostraMelhorAluno(int numAlunos, float maiorMedia, RegistroAluno *aluno);


void ReadStdtData(int numAlunos, RegistroAluno *aluno)
{
    int soma, i, j; // Para o calculo da média

    for (i = 0; i < numAlunos; i++)
    {
        soma = 0;

        scanf("%d ", &aluno[i].matricula);

        fflush(stdin);
        fgets(aluno[i].nome, 50, stdin);

        for (j = 0; j < 3; j++)
        {
            scanf("%f", &aluno[i].notas[j]);
            soma += aluno[i].notas[j];
        };

        aluno[i].media = soma/3;
    };
};

float EncontraMaiorMedia(int numAlunos, RegistroAluno *aluno)
{
    float maior;
    int i;

    for (i = 0; i < numAlunos; i++)
        {
        if (!(i))
        {
            maior = aluno[i].media;
        } else if (aluno[i].media > maior)
        {
            maior = aluno[i].media;
        };
    };
    return maior;
};

void MostraMelhorAluno(int numAlunos, float maiorMedia, RegistroAluno *aluno)
{
    int i, j;

    for (i = 0; i < numAlunos; i++)
    {
        if (aluno[i].media == maiorMedia)
        {
            printf("%d\n", aluno[i].matricula);
            printf("%s", aluno[i].nome);
            for (j = 0; j < 3; j++)
            {
                printf("%.1f\n", aluno[i].notas[j]);
            };
        };
    };
};

int main()
{
    int numAlunos = 4;
    RegistroAluno alunos[numAlunos];

    RegistroAluno *alunosPointer = alunos;

    ReadStdtData(numAlunos, alunosPointer);
    float maiorMedia = EncontraMaiorMedia(numAlunos, alunosPointer);
    MostraMelhorAluno(numAlunos, maiorMedia, alunosPointer);
};
