#include <stdio.h>
#include "lista_simplesmente_encadeada.h"

#define TAM 5;

#define FIM 0
#define INSERIR 1
#define REMOVER 2
#define LISTAR 3
#define INSERIR_EM 4
#define INSERIR_E_ORDENA 5
#define UNIAO 6
#define INTERSECCAO 7
#define SETAR_LISTA 8

int obterOpcao(void) {

     int opcao;

     printf("-------->MENU<--------\n");
     printf("--LISTA SIMPLESMENTE--\n");
     printf("%2d - FIM\n", FIM);
     printf("%2d - INSERIR\n", INSERIR);
     printf("%2d - REMOVER\n", REMOVER);
     printf("%2d - LISTAR\n", LISTAR);
     printf("%2d - INSERIR EM\n", INSERIR_EM);
     printf("%2d - INSERIR E ORDENA\n", INSERIR_E_ORDENA);
     printf("%2d - UNIÃO\n", UNIAO);
     printf("%2d - INTERSECÇÃO\n", INTERSECCAO);
     printf("%2d - SETAR LISTA\n", SETAR_LISTA);
     printf("Opcao: ");
     scanf("%d", &opcao);
     putchar('\n');
     return opcao;
 }

int main (int argc, char **argv){

	LISTA *L = NULL;
	LISTA *L1 = NULL;
	LISTA *L2 = NULL;
		
	int opcao;
	int valor;
	int pos;
	int flag_l1 = 1;
	int flag_l2 = 0;
	
	L = L1;
    
    while ((opcao = obterOpcao()) != FIM){
		
		switch (opcao){

			case INSERIR:
				printf("Valor a ser inserido: ");
				scanf("%d", &valor);
				insere_inicio(valor,&L);
				printf("Operacao concluida com sucesso\n");
			break;

			case REMOVER:
				printf("Valor a ser removido: ");
				scanf("%d", &valor);
				if (remove_elemento(valor,&L))
					printf("Valor %d removido\n", valor);
				else
					printf("Valor não encontrado\n");
			break;

			case LISTAR:
				imprime(L);
				printf("\n");
			break;
			
			case INSERIR_EM:
				printf("Valor a ser inserido: ");
				scanf("%d", &valor);
				printf("Posição desejada: ");
				scanf("%d", &pos);
				insere_meio(valor,pos,&L);
			break;
			
			case INSERIR_E_ORDENA:
				printf("Valor a ser inserido: ");
				scanf("%d", &valor);
				insere_ordenada(valor,&L);
			break;
			
			case UNIAO:
				if (flag_l1) {
					L1 = L;
				} else {
					L2 = L;
				}
				imprime(concatena(L1, L2));
				printf("\n");
			break;
			
			case INTERSECCAO:
				if (flag_l1) {
					L1 = L;
				} else {
					L2 = L;
				}
				imprime(interseccao(L1, L2));
				printf("\n");
			break;
			
			case SETAR_LISTA:
				printf("(1) Lista 1\n");
				printf("(2) Lista 2\n");
				printf("informe a lista a ser setada: ");
				scanf("%d", &valor);
				
				if (valor == 1 && !flag_l1) {
					flag_l1 = 1;
					flag_l2 = 0;
					L2 = L;
					L = L1;
				}
				
				if (valor == 2 && !flag_l2) {
					flag_l2 = 1;
					flag_l1 = 0;
					L1 = L;
					L = L2;
				}
         }
     }
	
return 0;	
}
