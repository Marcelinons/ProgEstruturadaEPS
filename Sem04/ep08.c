#include "bib_ep08.h"

/* EP04_08
 * 
 * Le do teclado o nome de um arquivo.csv; le os dados dos alunos contidos nele
 * e os armazenando em uma posicao numa lista de structs; calcula a media
 * individual de cada aluno e a media da turma; imprime as informacoes dos
 * dos alunos cuja media foi maior ou igual que a media da turma
 * 
 * Nicolas Marcelino da Silva; 21-10-2022
*/ 

int main() {

    float media, somaNotaTurma;
    int studentCount;
    char filename[50], line[512];
    Aluno aluno[10]; // Maximo de 10 alunos no arquivo;
    
    scanf("%s", filename);
  
    FILE *studentsData = fopen(filename, "r");

    if (studentsData == NULL) {
        printf("Ocorreu um erro ao tentar abrir o arquivo %s.\n", filename);
        exit(1);
    }

    studentCount = 0;
    // Le cada linha do arquivo
    while (fgets(line, sizeof(line), studentsData)) {
        criaAluno(&aluno[studentCount++], line);
    }

    // Calcula a media de cada aluno e encontra a maior media
    somaNotaTurma = 0;
    for (int i = 0; i < studentCount; i++) {
        aluno[i].final = (aluno[i].p1 + aluno[i].p2 + aluno[i].p3) / (float)3; 
        somaNotaTurma += aluno[i].final;
    }

    media = somaNotaTurma / (float)studentCount;

    printf("Numero de Alunos: %d\n", studentCount);
    printf("Media: %.1f\n", media);
    printf("Alunos acima da media:\n\n");

    // Imprime as informacoes dos alunos cuja media esta acima da media da turma
    for (int i = 0; i < studentCount; i++) {
        if (aluno[i].final >= media) {
            escreverAluno(aluno[i]);
        }
    }

    fclose(studentsData);
    return 0;
}