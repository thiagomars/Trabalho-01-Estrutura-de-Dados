#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
	int info;
	Lista *prox;
};

/* Cria uma lista vazia. */
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista é vazia. */
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

/* Busca um elemento em uma lista (retorna o endere?o ou NULL).*/
Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	
	while(lAux!=NULL){
		if(lAux->info == info){
			return lAux;
		}
		
		lAux = lAux->prox;
	}
	
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
	
	while(lAux != NULL){
		printf("Info = %d\n",lAux->info);
		
		lAux = lAux->prox;
	}
}

/* Imprime uma lista invertida recursivamente.*/
void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else {
		lst_imprime_invertida_rec(l->prox);
		printf("Info = %d\n",l->info);
	}
}

/* Remove um elemento de uma lista recursivamente.*/
Lista * lst_remove_rec(Lista * l, int info){
	if(!lst_vazia(l))
		if(l -> info == info){
			Lista * lAux = l;
			l = l -> prox;
			free(lAux);
		} else {	
			l -> prox = lst_remove_rec(l -> prox, info);
		}
		
	return l;
}

/* Remove um elemento de uma lista.*/
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

/* Libera o espaço alocado por uma lista. */
void lst_libera(Lista *l){
	Lista* lProx;
	
	while(l != NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

/* Retornar o número de nós da lista que possuem o campo info com valor menor que n */
int menores(Lista * l, int n){
	Lista * lAux = l;
	int quant = 0;
	
	while(lAux != NULL){
		if (lAux -> info < n){
			quant++;
		}
		
		lAux = lAux -> prox;
	}
	
	return quant;
}

/* Somar os valores do campo info de todos os nós. */
int soma(Lista * l) {
	Lista * lAux = l;
	int soma = 0;
	
	while(lAux != NULL){
		soma += lAux -> info;
		lAux = lAux -> prox;
	}
	
	return soma;
}

/* Retornar o numero de nos da lista que possuem o campo info com n divisores positivos */
int num_ndivp(Lista * l, int n){
	Lista * lAux = l;
	int divPos = 0;
	int cont = 1;
	int valor = 0;
	
	while(lAux != NULL){
		while(cont <= lAux -> info){
			if(lAux -> info % cont == 0){
				divPos++;
			}
			cont++;
		}
		
		if(divPos == n){
			valor++;
		}
		
		divPos = 0;
		cont = 1;
		lAux = lAux -> prox;
	}
	
	return valor;
}

/* Gerar uma nova lista que e a intersecçao de duas listas com valores ordenados */
// Item D
Lista * lst_intersec(Lista * l1, Lista * l2){
	Lista * aux1 = l1;
	Lista * aux2 = l2;
	Lista * novaLista = lst_cria();
	//false = 0
	//true = 1
	int verific = 0;
	
	while(aux1 != NULL){
		while(aux2 != NULL){
			if(aux1 -> info == aux2 -> info){
				verific = 1;
			}
			aux2 = aux2 -> prox;
		}
		
		if(verific == 0){
			novaLista = lst_insere(aux1, aux1 -> info);
		}
		
		aux1 = aux1 -> prox;
		aux2 = l2;
		verific = 0;
	}
	
	aux1 = l1;
	aux2 = l2;
	verific = 0;
	
	while(aux2 != NULL){
		while(aux1 != NULL){
			if(aux2 -> info == aux1 -> info){
				verific = 1;
			}
			aux1 = aux1 -> prox;
		}
		
		if(verific == 0){
			novaLista = lst_insere(aux2, aux2 -> info);
		}
		
		aux2 = aux2 -> prox;
		aux1 = l1;
		verific = 0;
	}	
}

/* Gerar uma nova lista que é a concatenação de uma lista l1 no final de uma lista l2 */
Lista* lst_conc(Lista * l1, Lista * l2) {
	Lista * lAuxInv = lst_cria();
	Lista * lAux = l1;
	Lista * l3 = lst_cria();
	
	while (lAux != NULL) {
		lAuxInv = lst_insere(lAuxInv, lAux -> info);
		lAux = lAux -> prox;
	}
	
	lAux = lAuxInv;
	
	while (lAux != NULL) {
		l3 = lst_insere(l3, lAux -> info);
		lAux = lAux -> prox;
	}
	
	lAuxInv = NULL;
	lAux = l2;
	
	while (lAux != NULL) {
		lAuxInv = lst_insere(lAuxInv, lAux -> info);
		lAux = lAux -> prox;
	}
	
	lAux = lAuxInv;
	
	while (lAux != NULL) {
		l3 = lst_insere(l3, lAux -> info);
		lAux = lAux -> prox;
	}
	
	return l3;
}

/* Diferença entre duas listas l1 e l2 - retirar de uma o que possui na outra*/
Lista * lst_diferenca(Lista * l1, Lista * l2) {
	Lista * lAux;
	Lista * lAuxl1 = l1;

	while(lAuxl1 != NULL){
		lAux = lst_busca(l2, lAuxl1 -> info);
		lAuxl1 = lAuxl1 -> prox;
		
		if (lAux != NULL ){
			l1 = lst_remove(l1, lAux -> info);
		}
	}
	return l1;
}










