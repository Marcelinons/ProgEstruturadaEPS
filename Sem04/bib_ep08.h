#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int ra;
  char nome[50];
  float p1, p2, p3, final;
} Aluno;

void criaAluno(Aluno* a, char linha[512]);
void escreverAluno(Aluno a);