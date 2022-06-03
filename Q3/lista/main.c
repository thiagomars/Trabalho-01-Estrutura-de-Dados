#include <stdio.h>
#include<stdlib.h>
#include "fila2.h"

int main(void){
	int a, qtd;
	Fila* f1 = fila_cria();
	
	fila_insere(f1,31);
	fila_insere(f1,33);
	fila_insere(f1,35);
	fila_insere(f1,37);
	fila_insere(f1,39);
	
	a = fila_remove(f1);
	printf("Valor removido da fila f1: %d\n",a);
	
	fila_imprime(f1);
	
	Fila* f2=inverte_fila(f1);
	
	fila_imprime(f2);
	
	qtd = qtd_primos(f1);
	printf("Qtd. elem. primos na fila f1: %d \n",qtd);
	
	fila_libera(f1); 
	fila_libera(f2);
	
	system("PAUSE");
	return 0;
}
