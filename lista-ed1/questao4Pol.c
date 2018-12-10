#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ITEM{
	float valor;
	int grau;
}ITEM;

typedef struct NO{
	ITEM *item;
	struct NO *prox;
}NO;
typedef struct LISTA_LIGADA{
	NO *cabeca;
	NO *fim;
	int tam;
}LISTA_LIGADA;

ITEM* criar_item(float valor, int grau){
	ITEM *item= (ITEM*) malloc(sizeof(ITEM));
	if(item != NULL){
		item->valor = valor;
		item->grau = grau;
	}
	return item;
}
NO* criar_no(ITEM *item){
	NO *no = (NO*) malloc(sizeof(NO));
	if(no != NULL){
		no->item = item;
		no->prox = NULL;
	}
	return no;
}
LISTA_LIGADA* criar_lista(){
	LISTA_LIGADA *lista = (LISTA_LIGADA*) malloc(sizeof(LISTA_LIGADA));
	if(lista != NULL){
		lista->tam = 0;
		lista->cabeca = criar_no(NULL);
		lista->fim = NULL;
	}
	return lista;
}

int inserir(LISTA_LIGADA *lista,ITEM *item){
	NO *novo = criar_no(item);

	if(novo != NULL){
		if(lista->cabeca->prox == NULL){
			lista->cabeca->prox = novo;
		}else{
			lista->fim->prox = novo;
		}

		lista->fim = novo;
		lista->tam ++;

		return 1;
	}
	return 0;
}

void calculaPx(LISTA_LIGADA *lista, int x){
	float total = 0;

	paux = lista->cabeca->prox;

	while(paux->prox != NULL){
		total += paux->item->valor * pow(x,paux->item->grau);
	}

	printf("Total = %f\n",total);
}

int main(){

	LISTA_LIGADA *lista = criar_lista();
	ITEM *item1 = criar_item(2.0,1);
	ITEM *item2 = criar_item(3.0,0);
	int controle = inserir(lista,item1);
	controle = inserir(lista, item2);
	calculaPx(lista,2);

	return 0;
}