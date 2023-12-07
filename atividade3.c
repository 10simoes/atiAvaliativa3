#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Produto {
    char codigo[20];
    char descricao[50];
    int quantidade;
    float valor;
};

struct Produto estoque[100];
int total_produtos = 0; 

void inicializar_estoque() {
    total_produtos = 0;
}

void adicionar_produto() {
    printf("Digite o código do produto: ");
    scanf("%s", estoque[total_produtos].codigo);
    printf("Digite a descrição do produto: ");
    scanf("%s", estoque[total_produtos].descricao);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &estoque[total_produtos].quantidade);
    printf("Digite o valor do produto: ");
    scanf("%f", &estoque[total_produtos].valor);

    total_produtos++;
    printf("Produto adicionado com sucesso!\n");
}

void relatorio_produtos() {
    printf("Relatório de Produtos:\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("Código: %s, Descrição: %s, Quantidade: %d, Valor: R$%.2f\n", estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
    }
}

void pesquisar_produto() {
    char codigo_pesquisa[20];
    printf("Digite o código do produto a ser pesquisado: ");
    scanf("%s", codigo_pesquisa);

    int encontrado = 0;
    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(estoque[i].codigo, codigo_pesquisa) == 0) {
            printf("Produto encontrado - Código: %s, Descrição: %s, Quantidade: %d, Valor: R$%.2f\n", estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

void remover_produto() {
    char codigo_remover[20];
    printf("Digite o código do produto a ser removido: ");
    scanf("%s", codigo_remover);

    int encontrado = 0;
    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(estoque[i].codigo, codigo_remover) == 0) {
            for (int j = i; j < total_produtos - 1; j++) {
                estoque[j] = estoque[j + 1];
            }
            total_produtos--;
            printf("Produto removido com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

int main() {
    int opcao;
    do {
        printf("\n===== Menu =====\n");
        printf("1. Inicializar Estoque\n");
        printf("2. Adicionar Produto\n");
        printf("3. Consultar Produtos\n");
        printf("4. Pesquisar Produto por Código\n");
        printf("5. Remover Produto\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inicializar_estoque();
                break;
            case 2:
                adicionar_produto();
                break;
            case 3:
                relatorio_produtos();
                break;
            case 4:
                pesquisar_produto();
                break;
            case 5:
                remover_produto();
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
        }
    } while (opcao != 6);

    return 0;
}