typedef struct lista Lista;
typedef struct fila Fila;

//Cria uma Fila
Fila * fila_cria(void);

//Testa se uma Fila e vazia
int fila_vazia(Fila * f);

//Adiciona um elemento em uma Fila
void fila_insere(Fila * f, int info);

//Remove um elemento de uma Fila
int fila_remove(Fila * f);

//Imprime os elementos de uma Fila
void fila_imprime(Fila * f);

//Libera o espaço alocado para uma Fila
void fila_libera(Fila * f);

//Quantidade de elementos primos de uma fila
int qtd_primos(Fila * f);

//Cria uma nova fila com ordem inversa
Fila * inverte_fila(Fila * f);



