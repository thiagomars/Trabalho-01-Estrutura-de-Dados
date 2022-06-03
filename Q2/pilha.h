typedef struct pilha Pilha;
typedef struct lista Lista;

//Fun��o que cria uma pilha
Pilha * pilha_cria(void);

//Testa se uma pilha � vazia.
int pilha_vazia(Pilha * p);

//Fun��o que adiciona um elemento no topo de uma pilha.
void pilha_push(Pilha * p, int info);

//Fun��o que remove um elemento do topo de uma pilha.
int pilha_pop(Pilha * p);

//Fun��o que imprime os elementos de uma pilha;
void pilha_imprime(Pilha * p);

//Libera o espa�o alocado para uma pilha.
void pilha_libera(Pilha * p);

//Gerar uma nova pilha com os elementos da pilha p na ordem inversa
Pilha * inverte_pilha(Pilha* p);

//Verificar quais s�o os elementos em comum em duas listas l1 e l2 e empilhar em ordem crescente em uma nova pilha
Pilha * empilha_elem_comuns(Lista* l1, Lista* l2);
