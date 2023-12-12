#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include<ctype.h>

void numerodeTelefone(char numero[], char nome[], char NomeDigitado[]){
    if (strcmp(nome, NomeDigitado) == 0){
        printf("Número de telefone: %s\n", numero);
    }
}

struct contato{
    char nome[500];
    char numero[500];
    char email[500];
};

int main () {

    setlocale(LC_ALL, "portuguese");

    int i;
    char NomeDigitado[500];
    struct contato contatos[3];

    for (i = 0; i < 3; i++){
        printf("DADOS DO %dº CONTATO\n\n", i+1);
        printf("Nome: ");
        gets(contatos[i].nome);
        printf("Número de telefone: ");
        gets(contatos[i].numero);
        printf("E-mail: ");
        gets(contatos[i].email);
        system("cls || clear");
    }
    system("cls || clear");

    printf("Digite o nome do contato que deseja buscar: ");
    gets(NomeDigitado);

    for (i = 0; i < 3; i++){
        numerodeTelefone(contatos[i].numero, contatos[i].nome, NomeDigitado);
    }

    return 0;
}