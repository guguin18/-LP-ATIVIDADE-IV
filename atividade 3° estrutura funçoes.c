
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Produto
{
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

float calcularValorTotal(struct Produto produto)
{
    return produto.preco * produto.quantidadeEstoque;
}

void realizarCompra(struct Produto *produto, int quantidadeComprada)
{
    if (quantidadeComprada > 0)
    {
        produto->quantidadeEstoque += quantidadeComprada;
        printf("Compra realizada com sucesso! Nova quantidade em estoque: %d\n", produto->quantidadeEstoque);
    }
    else
    {
        printf("Quantidade inválida para compra.\n");
    }
}

void consultarEstoque(struct Produto produto)
{
    printf("Produto: %s\n", produto.nome);
    printf("Preco: R$%.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidadeEstoque);
    printf("Valor total em estoque: R$%.2f\n", calcularValorTotal(produto));
}

int main()
{
   
    struct Produto meuProduto = {"Camiseta", 29.99, 50};

    int opcao;
    int quantidadeComprada;

    do
    {
        
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            // Realizar compra
            printf("Digite a quantidade a ser comprada: ");
            scanf("%d", &quantidadeComprada);
            realizarCompra(&meuProduto, quantidadeComprada);
            break;
        case 2:
            // Consultar estoque
            consultarEstoque(meuProduto);
            break;
        case 3:
            // Sair do programa
            printf("Saindo do programa. Obrigado!\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}