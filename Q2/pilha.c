#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

typedef struct lista Lista;
typedef struct pilha Pilha;

struct lista {
	int info;
	Lista *prox;
};

struct pilha {
	Lista * prim;
};

//////////////////////////////////////////////////////////////////////////////
///////////////////////////// L I S T A //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista ? vazia.*/
int lst_vazia(Lista *l){
	return (l==NULL);
}

/* Insere um elemento no in?cio da lista.*/
Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	
	return ln;
}

/* Insere um elemento em ordem na lista.*/
Lista* lst_insere_ordenado(Lista *l, int info){
	Lista *lNew = (Lista*)malloc(sizeof(Lista));   //estrutura lista que ser? inserida
	
	lNew->info = info;   //estrutura recebendo o valor a ser inserido
	
	if(l == NULL){  //se a lista repassada estiver vazia
		lNew->prox = NULL;
		
		return lNew;
		
	} else if(l->info >= info){   //se o primeiro valor da original for maior que o valor a ser inserido
		lNew->prox = l;   //insere antes do primeiro valor
		
		return lNew;
		
	} else {
		Lista *lAnt = l;
		
		Lista *lProx = l->prox;
		
		while(lProx!=NULL && lProx->info < info) {
			lAnt = lProx;
			
			lProx = lProx->prox;
		}
	
		lAnt->prox = lNew;
		
		lNew->prox = lProx;
		
		return l;
	}
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		if(lAux->info == info)
			return lAux;
		
		lAux = lAux->prox;
	}
	
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		
		lAux = lAux->prox;
	}
}

/* Remove um elemento da lista.*/
Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
		
		if(l->info==info){
			free(l);
			return lAux;
		} else {
			Lista* lAnt = l;
			
			while(lAux!=NULL ){
				if(lAux->info == info){
					lAnt->prox = lAux->prox;
					free(lAux);
					
					break;
				}else{
					lAnt = lAux;
					lAux = lAux->prox;
				}
			}
		}
	}
	return l;
}

/* Libera o espa?o alocado por uma lista.*/
void lst_libera(Lista *l){
	Lista* lProx;
	
	while(l!=NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

//////////////////////////////////////////////////////////////////////////////
///////////////////////////// P I L H A //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//Função que cria uma pilha
Pilha * pilha_cria(void){
	Pilha * p = (Pilha*)malloc(sizeof(Pilha));
	
	if(p == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	p -> prim = NULL;
	return p;
}

//Testa se uma pilha é vazia.
int pilha_vazia(Pilha * p){
	return p -> prim == NULL;
}

//Função que adiciona um elemento no topo de uma pilha.
void pilha_push(Pilha * p, int info){
	Lista * l = (Lista*)malloc(sizeof(Lista));
	
	if(l == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	l -> info = info;
	l -> prox = p->prim;
	p -> prim = l;
}

//Função que remove um elemento do topo de uma pilha.
int pilha_pop(Pilha * p) {
	int a;
	Lista * l;
	
	if(pilha_vazia(p)) {
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	
	l = p -> prim;
	a = l -> info;
	p -> prim = l -> prox;
	
	free(l);
	return a;
}

//Função que imprime os elementos de uma pilha;
void pilha_imprime(Pilha *p) {
	Lista * lAux = p -> prim;
	
	while(lAux != NULL) {
		printf("%d \n",lAux -> info);
		lAux = lAux -> prox;
	}
}

//Libera o espaço alocado para uma pilha.
void pilha_libera(Pilha * p){
	Lista * l = p -> prim;
	Lista * lAux;
	
	while(l != NULL) {
		lAux = l -> prox;
		free(l);
		l = lAux;
	}
	
	free(p);
}

//Gerar uma nova pilha com os elementos da pilha p na ordem inversa
Pilha * inverte_pilha(Pilha * p){
	Pilha * pilhaInvertida = pilha_cria();
	Lista * lAux = p -> prim;
	
	while(lAux != NULL){
		pilha_push(pilhaInvertida, lAux -> info);
		lAux = lAux -> prox;
	}
	
	return pilhaInvertida;
}

//Verificar quais são os elementos em comum em duas listas l1 e l2 e empilhar em ordem crescente em uma nova pilha
Pilha * empilha_elem_comuns(Lista * l1, Lista * l2) {
	Pilha * p2 = pilha_cria();
	Lista * l3 = lst_cria();
	Lista * lAux = l1;
	Lista * lAuxProcurar;
	
	while(lAux != NULL){
		lAuxProcurar = lst_busca(l2, lAux -> info);
		
		if(lAuxProcurar != NULL){
			l3 = lst_insere_ordenado(l3, lAux -> info);
		}
		
		lAux = lAux -> prox;
	}
	
	//Ordenar em uma nova pilha //////////////////
	while(l3 != NULL) {
		pilha_push(p2, l3 -> info);
		l3 = l3 -> prox;
	}

	return p2;
}


