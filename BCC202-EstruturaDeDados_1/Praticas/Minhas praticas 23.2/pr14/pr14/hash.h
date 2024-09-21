# ifndef hash_h
# define hash_h

typedef char Chave[11]; // A chave tem até 10 chars 

typedef struct {
    Chave* chaves; // Vetor para armazenar até m chaves
    int* pesos;    // Vetor de pesos
    int m;         // Tamanho do vetor de chaves
    int p;         // Tamanho do vetor de pesos
} Hash;

// Manter como especificado
void inicia(Hash*, int, int);

// Manter como especificado
void libera(Hash*);

//Definir de acordo com o metodo escolhido para insercao na arvore
int insere (Hash*, Chave);

# endif
