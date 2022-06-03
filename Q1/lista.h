typedef struct lista Lista;

/* Criar uma lista vazia.*/
Lista* lst_cria();

/* Testar se uma lista e vazia.*/
int lst_vazia(Lista *l);

/* Inserir um elemento no inicio da lista.*/
Lista* lst_insere(Lista *l, int info);

/* Busca um elemento na lista.*/
Lista* lst_busca(Lista *l, int info);

/* Imprime uma lista.*/
void lst_imprime(Lista *l);

/* Remove um elemento de uma lista. */
Lista* lst_remove(Lista *l, int info);

/* Remove um elemento de uma lista recursivamente.*/
Lista* lst_remove_rec(Lista *l, int info);

/* Imprime uma lista invertida recursivamente.*/
void lst_imprime_invertida_rec(Lista* l);

/* Libera o espaço alocado por uma lista. */
void lst_libera(Lista *l);

/* Retornar o numero de nos da lista que possuem o campo info com valor menor que n */ 
int menores(Lista * l, int n);

/* Somar os valores do campo info de todos os nós. */
int soma(Lista * l);

/* Retornar o numero de nos da lista que possuem o campo info com n divisores positivos */
int num_ndivp(Lista * l, int n);

/* Gerar uma nova lista que e a intersecçao de duas listas com valores ordenados */
Lista * lst_intersec(Lista * l1, Lista * l2); // Item D 

/* Gerar uma nova lista que é a concatenação de uma lista l1 no final de uma lista l2 */
Lista * lst_conc(Lista * l1, Lista * l2);

/* Diferença entre duas listas l1 e l2 - retirar de uma o que possui na outra*/
Lista * lst_diferenca(Lista * l1, Lista * l2);













