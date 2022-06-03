#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

//////////////////////// L i s t a    E n c a d e a d a ///////////////////////////

struct lista{
	int info;
	Lista * prox;
};

struct fila{
	Lista * ini;
	Lista * fim;
};

Fila * fila_cria(void){
	Fila * f = (Fila*)malloc(sizeof(Fila));
	
	if(f == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	f -> ini = NULL;
	f -> fim = NULL;
	
	return f;
}

void fila_insere(Fila *f, int info){
	Lista * l = (Lista*)malloc(sizeof(Lista));
	
	if(l == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	l -> info = info;
	l -> prox = NULL;
	
	if(!fila_vazia(f))
		f -> fim -> prox = l;
	else
		f -> ini = l;
	
	f -> fim = l;
}

int fila_vazia(Fila * f){
	return f -> ini == NULL;
}

int fila_remove(Fila * f){
	Lista * l;
	int a;
	
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	
	a = f -> ini -> info;
	l = f -> ini;
	f -> ini = f -> ini -> prox;
	
	free(l);
	
	if(fila_vazia(f)){
		f -> fim = NULL;
	}
	
	return a;
}

//Imprime os elementos de uma fila
void fila_imprime(Fila * f){
	Lista * lAux = f -> ini;
	
	while(lAux != NULL){
		printf("%d\n", lAux -> info);
		lAux = lAux -> prox;
	}
}

//Inserir recursivamente
Fila * fila_insere_invertida_rec(Lista * l, Fila * f_inv){
	if(l == NULL){
		return;
	} else{
		fila_insere_invertida_rec(l -> prox, f_inv);
		fila_insere(f_inv, l -> info);
	}
	
	return f_inv;
}

//Libera o espaço alocado para uma fila
void fila_libera(Fila * f){
	Lista * l = f -> ini;
	Lista * lAux;
	
	while(l != NULL){
		lAux = l -> prox;
		free(l);
		l = lAux;
	}
	
	free(f);
}

//Quantidade de elementos primos em uma fila
int qtd_primos(Fila * f) {
	Lista * l = f -> ini;
	int qtd = 0;
	int n = 0;
	int cont = 1;
	int result = 0;
	
	while(l != NULL) {
		n = l -> info;
		
		while(cont <= (n/2)){
			if(n % cont == 0){
				qtd++;
			}
			cont++;
		}
		
		
		if(qtd < 2){
			result++;
		}
		
		cont = 1;
		qtd = 0;
		
		l = l -> prox;
		
	}
	
	return result;
}

//Cria uma fila com ordem inversa
Fila * inverte_fila(Fila * f) {
	Fila * inv = fila_cria();
	Lista * lAux = f -> ini;
	
	inv = fila_insere_invertida_rec(lAux, inv);
	
	return inv;	
}


