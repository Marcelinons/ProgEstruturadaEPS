#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// @brief Armazena as informacoes de um aluno: ra, nome, notas da p1, p2 e p3 e
/// media final.
typedef struct {
    int ra;
    char nome[50];
    float p1, p2, p3, final;
} Aluno;

/// @brief Cria uma aluno a partir de uma linha de texto.
/// @param a Ponteiro para uma struct do tipo Aluno;
/// @param linha Linha do arquivo;
void criaAluno(Aluno* a, char linha[512]);

/// @brief Imprime os dados de um aluno.
/// @param a Struct do tipo aluno;
void escreverAluno(Aluno a);