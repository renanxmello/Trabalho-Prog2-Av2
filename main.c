// Integrantes: Caio Ferreira, Leonardo, Pedro Sant'Anna, Rafael Vianna, Renan Xavier

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* Structs */

struct clientes {
    char nome[100];
    char sexo;
    int idade;
};
typedef struct clientes clientes;

struct vendas { 
    clientes cliente;
    int numItens;
    char nomeVendedor[50]; // Luiza ou Juca
    float valorTotal;
};
typedef struct vendas vendas;
    

/* Funções */
void cadastrarVendas(clientes cliente, vendas *vendas);
void pesquisarVendas(clientes cliente, vendas *vendas);
void infoVendas(clientes cliente, vendas *vendas);


/* Menu */
int main() {
    setlocale(LC_ALL, "Portuguese"); 

    clientes cliente;
    vendas *vendas = NULL; 
    int opcao = 0;

    do {
        printf("\n1) Cadastrar novas vendas.\n");
        printf("2) Ver informações de uma venda específica, baseado no nome do cliente\n");
        printf("3) Ver informações de todas as vendas\n");
        printf("4) Encerrar o programa\n");

        printf("\nDigite aqui a opção desejada: ");
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVendas(cliente, vendas);
                break;

            case 2:
                // pesquisarVendas(cliente, vendas);
                break;

            case 3:
                // infoVendas(cliente, vendas);
                break;

            case 4:
                system("clear");
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida, tente novamente\n");
                break;
        }
    } while (opcao != 4);

    free(vendas);
    return 0;
}


void cadastrarVendas(clientes cliente, vendas *vendas) {
    int qtd_vendas = 0;

    printf("Digite a quantidade de vendas que deseja cadastrar: ");
    scanf("%i", &qtd_vendas);
    getchar(); // limpa o buffer do enter

    /* alocação de memória das vendas */
    vendas = malloc(qtd_vendas * sizeof(*vendas));
    if (vendas == NULL) {
        printf("Erro: Memória Insuficiente!\n");
        return;
    }

    /* Criação do arquivo de texto */
    FILE *arq;
    arq = fopen("registros.txt", "a");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    /* Cadastro das vendas */
    for (int i = 0; i < qtd_vendas; i++) {
        int nome;

        /*Nome do cliente*/
 
        do {
            printf("\nDigite o nome do cliente: ");
            scanf(" %[^\n]", vendas[i].cliente.nome);
            nome = strlen(vendas[i].cliente.nome);

            if (nome < 3) {
                printf("\nNome inválido. O nome deve ter mais de 3 caracteres.\n");
            }
        } while (nome < 3);

         do {
            printf("Digite o sexo do cliente\n");
            printf("(M) Masculino, (F) Feminino, (N) Nao desejo responder\n");
            scanf(" %c", &vendas[i].cliente.sexo);

            /*transforma toda caracter maúscular em minúscular*/

            vendas[i].cliente.sexo = tolower(vendas[i].cliente.sexo);
            if (vendas[i].cliente.sexo != 'm' && vendas[i].cliente.sexo != 'f' && vendas[i].cliente.sexo != 'n') {
              printf("\nOpção inválida\n");
            }
    } while (vendas[i].cliente.sexo != 'm' && vendas[i].cliente.sexo != 'f' && vendas[i].cliente.sexo != 'n');

    }

    fclose(arq);
}
