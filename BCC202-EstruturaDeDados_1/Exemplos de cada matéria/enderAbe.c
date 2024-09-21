# define VAZIO " !!!!!!!!!\0 "
2 # define N 10 // tamanho da chave ( string )
3 # define M 100 // tamanho da tabela
4
5 typedef char Chave [N ];
6
7 typedef struct {
8 /* outros componentes */
9 Chave Chave ;
10 } Item ;
11
12 typedef Item Dicionario [M ];

void DicionarioInicia ( Dicionario dic ) {
2 int i;
3 for (i = 0; i < M ; i ++) {
4 memcpy ( dic [i ]. chave , VAZIO , N );
5 }
6 }

int DicionarioPesquisa ( Dicionario dic , Chave chave , int p) {
2 int j = 0;
3 int ini = h ( chave , p);
4
5 while ( strcmp ( dic [( ini + j) % M ]. chave , VAZIO ) != 0 &&
6 strcmp ( dic [( ini + j ) % M ]. chave , chave ) != 0 &&
7 j < M ) {
8 j ++;
9 }
10
11 if ( strcmp ( dic [( ini + j) % M ]. chave , chave ) == 0) {
12 return ( ini + j) % M;
13 }
14
15 return -1; // pesquisa sem sucesso
16 }

int DicionarioInsere ( Dicionario dic , Item x , int p ) {
    if ( DicionarioPesquisa ( dic , x. chave , p) >= 0)
        return 0; // chave já existe no dicion á rio

    int j = 0;
    int ini = h (x. chave , p);
    while ( strcmp ( dic [( ini + j) % M ]. chave , VAZIO ) != 0 && j < M ) {
        j ++;
    }

    if (j < M) {
        dic [( ini + j) % M] = x;
        return 1;
    }
    return 0;
 }

