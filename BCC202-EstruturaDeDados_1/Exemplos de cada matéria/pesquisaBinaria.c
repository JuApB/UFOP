// C program to implement iterative Binary Search - geeksforgeek
#include <stdio.h>

// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// If we reach here, then element was not present
	return -1;
}

// Driver code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Element is not present"
							" in array")
				: printf("Element is present at "
							"index %d",
							result);
	return 0;
}

//codigo do PEDROO
typedef long Chave ;

typedef struct {
    Chave Chave ;
    /* outros componentes */
} Registro ;

typedef struct {
    Registro *v;
    int n , max ;
} Dicionario ;

/* inicializa um dicion á rio */
void DicionarioInicio ( Dicionario * dicio ) {
    dicio - >n = 0;
    dicio - > max = 10;
    dicio - >v = ( Registro *) malloc ( sizeof ( Registro ) * dicio -> max );
}

/* encontra o í ndice da chave x no dicion á rio */
int DicionarioFind ( Dicionario * dicio , Chave x) {
    return DicionarioBinaria ( dicio , 0 , dicio ->n -1 , x); // dicio ->n é o tamanho
}

/* encontra o í ndice da chave x no dicion á rio entre esq e dir */
int DicionarioBinaria ( Dicionario * dicio , int esq , int dir , Chave x) {
    int meio = ( esq + dir ) /2;

    if ( dicio - >v[ meio ]. chave != x && esq == dir )
        return -1;
    else if ( x > dicio ->v [ meio ]. chave )
        return DicionarioBinaria ( dicio , meio +1 , dir , x);
    else if ( x < dicio ->v [ meio ]. chave )
        return DicionarioBinaria ( dicio , esq , meio -1 , x);
    else
        return meio ;
}

/* encontra o í ndice da chave x no dicion á rio */
int DicionarioFind ( Dicionario * dicio , Chave c) {
    int i , esq , dir ;
    if ( dicio - >n == 0)
        return -1;
    esq = 0;
    dir = dicio ->n -1;
    do {
        i = ( esq + dir ) / 2;
        if (c > dicio ->v[ i ]. chave )
            esq = i + 1;
        else
            dir = i - 1;
    } while (c != dicio ->v [i ]. chave && esq <= dir );

    if (c == dicio -> v[i ]. chave )
        return i;
    else
        return -1;
}