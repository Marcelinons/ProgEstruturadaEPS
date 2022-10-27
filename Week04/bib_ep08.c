#include "bib_ep08.h"

void criaAluno(Aluno* a, char linha[512]) {
    char* tk = strtok(linha, ",");
    (*a).ra = atoi(tk);

    tk = strtok(NULL, ",");
    strcpy((*a).nome, tk);

    tk = strtok(NULL, ",");
    (*a).p1 = atof(tk);
    
    tk = strtok(NULL, ",");
    (*a).p2 = atof(tk);

    tk = strtok(NULL, ",");
    (*a).p3 = atof(tk);
}

void escreverAluno(Aluno a) {
    printf("ra: %d\nnome:%s\n", a.ra, a.nome);
    printf("p1: %.1f\np2: %.1f\np3: %.1f\n", a.p1, a.p2, a.p3);
    printf("final: %.1f\n", a.final);
    printf("\n");
}