#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Aluno {
    char nome[50];
    char dataNascimento[15];
    float nota1;
    float nota2;
    float media;
};

float calcularMedia(const struct Aluno* aluno) {
    return (aluno->nota1 + aluno->nota2) / 2.0;
}


int verificarAprovacao(const struct Aluno* aluno) {
    return aluno->media >= 7.0;
}

int main() {
    setlocale(LC_ALL,"portuguese");
    struct Aluno alunos[5];

   
    for (int i = 0; i < 5; ++i) {
        printf("Informe os dados do aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome); 
        printf("Data de Nascimento: ");
        scanf("%s", alunos[i].dataNascimento);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

       
        alunos[i].media = calcularMedia(&alunos[i]);
    }

   
    for (int i = 0; i < 5; ++i) {
        printf("\nAluno %s:\n", alunos[i].nome);
        printf("Média: %.2f\n", alunos[i].media);

        if (verificarAprovacao(&alunos[i])) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }

    return 0;
}
