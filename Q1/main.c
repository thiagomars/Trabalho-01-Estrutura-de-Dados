#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
	int a, b, c;
	Lista* l1 = lst_cria();
	
	l1 = lst_insere(l1,6);
	l1 = lst_insere(l1,12);
	l1 = lst_insere(l1,25);
	l1 = lst_insere(l1,28);
	l1 = lst_insere(l1,45);
	l1 = lst_remove(l1,25);
	l1 = lst_remove_rec(l1,12);
	
	lst_imprime(l1);
	lst_imprime_invertida_rec(l1);
	
	a=soma(l1);
	b=menores(l1,22);
	c=num_ndivp(l1,6);
	
	printf("Soma dos valores dos nos %d\n",a);
	printf("Num. nos c/ info < que 22: %d\n",b);
	printf("Num. nos c/ info c/ 6 div. positivos.: %d\n",c);
	
	Lista* l2 = lst_cria();
	
	l2 = lst_insere(l2,28);
	l2 = lst_insere(l2,130);
	l2 = lst_insere(l2,6);
	
	Lista* l3=lst_conc(l1,l2);
	lst_imprime(l3);
	
	Lista* l4=lst_intersec(l1,l2);
	lst_imprime(l4);
	
	l1=lst_diferenca(l1,l2);
	lst_imprime(l1);
	
	lst_libera(l1);
	lst_libera(l2);
	lst_libera(l3);
	lst_libera(l4);
	
	system("PAUSE");
	
	return 0;
}
