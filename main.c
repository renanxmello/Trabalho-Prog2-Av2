//Integrantes: Caio Ferreira, Leonardo, Pedro Sant'Anna, Rafael Vianna, Renan Xavier

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* Structs */

struct clientes {
    char nome[100];
    char sexo;
    int idade;
};
typedef struct clientes clientes;

struct vendas { 
    clientes clientes;
    int numItens;
    char nomeVendedor[50]; // Luiza ou Juca
    float valorTotal;
};
typedef struct vendas vendas;
    

/* Funções */

void cadastrarVendas(clientes clientes, vendas *vendas);
void pesquisarVendas(clientes clientes, vendas *vendas);
void infoVendas(clientes clientes, vendas *vendas);


/* Menu */

int main() {
  int opcao = 0;
  do{
      printf("\n1) Cadastrar novas vendas.\n");
      printf("2) Ver informações de uma venda específica, baseado no nome do cliente\n");
      printf("3) Ver informações de todas as vendas\n");
      printf("4) Encerrar o programa\n");
      
      printf("\nDigite aqui a opção desejada: ");
      scanf("%i",&opcao);
      
      switch(opcao){
          case 1:
            cadastrarVendas(clientes clientes, vendas &vendas);
            break;
            
          case 2:
            pesquisarVendas(clientes clientes, vendas);
            break;
            
          case 3:
            infoVendas(clientes clientes, vendas &vendas);
            break;
            
          case 4:
            system("clear");
            printf("\nEncerrando o programa...\n");
            break;
            
          default:
            printf("\nOpcao invalida, tente novamente");
            break;
            
      }
    }while(opcao !=4);
    
    return 0;
}

void cadastrarVendas(clientes clientes, vendas *vendas){
    int qtd_vendas = 0;
    
    printf("Digite a quantidade de vendas que deseja cadastrar: ");
    scanf("%i",&qtd_vendas);
    
    /*alacação de memória das vendas*/
    
    vendas = malloc(qtd_vendas * sizeof(*vendas));
    if (vendas == NULL) {
        printf("Erro: Memória Insuficiente!");
        free(vendas);
        return;
    }
    
    /*Criação do arquivo de texto*/

    FILE *arq;
    arq = fopen("registros.txt", "a");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }
    
    
    
    
    
    
    fclose(arq);
    free(vendas);
}

// void pesquisarVendas(clientes clientes, vendas *vendas){
    
    
// }

// void infoVendas(clientes clientes, vendas *vendas){
    
    
// }







