typedef struct fila Fila;

//Cria uma Fila
Fila* fila_cria(void);

//Testa se uma Fila e vazia
int fila_vazia(Fila *f);

//Adiciona um elemento em uma Fila
void fila_insere(Fila *f, int info);

//Remove um elemento de uma Fila
int fila_remove(Fila *f);

//Imprime os elementos de uma Fila
void fila_imprime(Fila *f);

//Libera o espaço alocado para uma Fila
void fila_libera(Fila *f);

//Retornar o número de elementos da fila com valor primo
int qtd_primos(Fila * f);

//Criar uma nova fila com os elementos da fila f na ordem inversa.
Fila* inverte_fila(Fila * f);

