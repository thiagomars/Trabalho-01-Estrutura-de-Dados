#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"

/////////////////////////// F i l a    c o m    V e t o r ///////////////////////////////////

#define MAX 5   //tamanho maximo da fila

typedef struct fila {
	//quantidade de elementos que a fila possui no momento
	int n;
	//indice do primeiro elemento da fila
	int ini;
	//vetor que guarda os elementos da fila
	int v[MAX];
} Fila;

//Cria uma fila
Fila * fila_cria(void) {
	Fila * f = (Fila*)malloc(sizeof(Fila));
	
	if(f == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	
	f -> n = 0;
	f -> ini = 0;
	return f;
}

//Insere um elemento em uma fila
void fila_insere(Fila *f, int info) {
	int fim;
	
	//Confirma que se a fila está cheia ou não
	if(f -> n == MAX){
		printf("Capacidade da Fila Maxima!!!\n");
		exit(1);
	}
	
	//passando o final da fila
	fim = (f -> ini + f -> n) % MAX;   
	f -> v[fim] = info;
	f -> n++;
}

//Fila e vazia
int fila_vazia(Fila * f) {
	return f -> n == 0;
}

//Remove um elemento da Fila
int fila_remove(Fila * f) {
	int a;
	
	if(fila_vazia(f)) {
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	
	//Remover no inicio da fila
	a = f -> v[f -> ini];
	f -> ini = (f -> ini + 1) % MAX;
	//tamanho total recebe -1
	f -> n--;
	
	return a;
}

//Imprime uma fila
void fila_imprime(Fila * f) {
	int i; int k;
	
	for(i = 0; i < f -> n; i++) {
		k = (f -> ini + i) % MAX;
		printf("%d\n", f -> v[k]);
	}
}

//Libera uma fila
void fila_libera(Fila *f) {
	free(f);
}

//
//item a
int qtd_primos(Fila * f){
	int cont = 0;
	int aux = 0;
	int qtd = 0;
	int verific = 1;
	int total = 0;
	int aux2 = 0;
	
	while(cont < f -> n){
		aux = (f -> ini + cont) % MAX;
		
		while(verific <= f -> v[aux] / 2){
			if(f -> v[aux] % verific == 0){
				aux2++;
			}
			verific++;
		}
		
		if(aux2 == 1){
			total++;
		}
		
		verific = 1;
		cont++;
		aux2 = 0;
	}
	
	return total;
}

//Nova fila com os elementos da fila f na ordem inversa
//item b
Fila * inverte_fila(Fila * f) {
	Fila * inv = fila_cria();
	
	//final da fila principal
	int fim = (f -> ini + f -> n % MAX);
	int cont;
	
	cont = fim - 1;
	
	while(cont >= fim - f -> n){
		fila_insere(inv, f -> v[cont]);
		cont--;
	}
	
	return inv;
}





