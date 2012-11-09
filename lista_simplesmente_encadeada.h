/*
* Descrição de como operar com lista.
*
* Esta é uma imlementação da primeira
* lista de exercício do 3 período da
* matéria de Estrutura de Dados e 
* Algoritmo II do curso de Engenharia 
* da Computação da Faculdade FUCAPI 2012.
*
* @author Priscila Paixão
*
*/

#ifndef _LISTA_SIMPLESMENTE_ENCADEADA_H
#define _LISTA_SIMPLESMENTE_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define remove(N, L) remove_elemento(N, L)
#define union(L1,L2) uniao_listas(L1,L2)

typedef struct L{
	
	int valor;
	struct L *prox;
	
}LISTA;

//função que retorna o tamanho da lista
int size(LISTA *L){
	
	LISTA *ptr;
	int cont=0;
	
	if(L == NULL)
		return cont;
	
	ptr = L;
	
	while(ptr !=NULL){
		cont++;
		ptr=ptr->prox;
	}
	return cont;	
}

//função interna que procura a ocorrência de um valor na lista
int sets_contains(int N, LISTA *L){
	
	LISTA *t = L;
	
	while (t != NULL){
		if (t->valor == N)
			return 1;
		t = t->prox;
	}
	return 0;
}

//insere um dado valor no início da lista
void insere_inicio(int N, LISTA **L){
	
	LISTA *newnode;
	
	newnode = (LISTA*)malloc(sizeof(LISTA));
	
	newnode->valor = N;
	newnode->prox = NULL;
	
	if(*L == NULL) {
		*L = newnode;
	} else {
		newnode->prox = *L;
		*L = newnode;	
	}
}

//insere um dado valor no fim da lista
void insere_fim(int N, LISTA **L){
	
	LISTA *newnode;
	LISTA *ptr;
	
	newnode = (LISTA*)malloc(sizeof(LISTA));
		
	ptr = *L;
	newnode->valor = N;
	newnode->prox = NULL;
	
	if(*L == NULL) {
		*L = newnode;
	} else {
		while(ptr->prox != NULL)
			ptr = ptr->prox;
		
		ptr->prox = newnode;
	}
}

//insere um dado valor em uma posição desejada
void insere_meio(int N, int P, LISTA **L){
	
	LISTA *ptr;
	LISTA *aux;
	LISTA *newnode;
	int cont=0;
	
	newnode = (LISTA*)malloc(sizeof(LISTA));
	
	newnode->valor = N;
	newnode->prox = NULL;
	ptr = *L;
	
	if(*L == NULL || P >= size(ptr)){
		insere_fim(N,L);
	} else {
		aux = *L;
		ptr = (*L)->prox;
		
		if((P>=0) && P<=size(ptr)){

			if(ptr == NULL || P == 0){
				insere_inicio(N,L);
			}
			while(ptr!=NULL){
			
				if(cont == P-1){
					aux->prox = newnode;
					newnode->prox = ptr;					
				}
				cont++;
				ptr=ptr->prox;
				aux=aux->prox;
			}
		}
	}
}

//coloca a lista em ordem crescente
void ordena(LISTA **L){

	LISTA *aux;
	LISTA *aux2;
	int temp;
	
	aux = *L;
	aux2 = (*L)->prox;
	
	while (aux2 != NULL) {
		while (aux2 != aux) {
			if (aux2->valor < aux->valor) {
				temp = aux->valor;
				aux->valor = aux2->valor;
				aux2->valor = temp;
			}
			aux = aux->prox;
		}
		aux = *L;
		aux2 = aux2->prox;
	}
}

//insere e coloca os valores em ordem crescente
void insere_ordenada(int N, LISTA **L){
	
	insere_fim(N,L);
	ordena(L);
	
}

//imprime a lista
void imprime(LISTA *L) {
    
    LISTA *ptr;
	
	ptr = L;
	
	if(ptr == NULL){
		printf("\nERRO: Lista vazia!");
	}else{ 		
		while (ptr != NULL) {
			printf(" %d\t", ptr->valor);
			ptr = ptr->prox;
    	}
	}
}

//remove um dado valor da lista
bool remove_elemento(int N, LISTA **L){
		
	LISTA *a;
	LISTA *b;
	
	bool x;
	
	x = true;
	
	if(*L == NULL){
		fprintf(stderr,"ERRO: Lista vazia, não há remoção!");
		exit(1);
	}
	
	if(!sets_contains(N,*L)){
		return x=false;
	}
	
	a = *L;
	
	if (a->valor == N) {
		*L = (*L)->prox;
		free(a);
		return x;	
	}

	b = (*L)->prox;
	
	while(b != NULL && b->valor != N){
		
		a = b;
		b = b->prox;
	}
	
	if(b != NULL){
		a->prox = b->prox;
		free(b);
		return x;
	}
	x = false;
	return x;
}

//função que retorna a união de 2 listas
LISTA *uniao_listas(LISTA *L1, LISTA *L2){

	LISTA *result = NULL;
	LISTA *t1 = L1;
	LISTA *t2 = L2;
 
	while (t1 != NULL){
		insere_inicio(t1->valor, &result);
		t1 = t1->prox;
	}
 
	while (t2 != NULL){
		if (!sets_contains(t2->valor, result))
			insere_inicio(t2->valor, &result);
		t2 = t2->prox;
	}
 
	return result;
}

//função que retorna os valores comuns nas 2 listas
LISTA *interseccao(LISTA *L1, LISTA *L2){
	
	LISTA *result = NULL;	
	LISTA *t1 = L1;
 
	while (t1 != NULL){
		if (sets_contains(t1->valor, L2))
			insere_inicio(t1->valor, &result);
		t1 = t1->prox;
	}
 
	return result;
}

//função que retorna a união de 2 listas ordenadas e sem valores iguais
LISTA *concatena(LISTA *L1, LISTA *L2){
	
	LISTA *result;
	
	result = union(L1,L2);
	
	ordena(&result);
	
	return result;
}

#endif
