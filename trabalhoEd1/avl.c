#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
	struct NO *pai;
	struct NO *fesq;
	struct NO *fdir;
	int valor;
	int altura;
}

typedef struct AVL{
	NO * raiz;
}

NO * criar_no(int valor){
	NO *novo = (NO*) malloc(sizeof(NO));
	if(novo != NULL){
		no->pai = no->fesq = no->fdir = NULL;
		no->valor = valor;
		no->altura = 0;
	}

	return NULL;
}

