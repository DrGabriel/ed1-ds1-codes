#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM{
	int chave;
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

ITEM* criar_item(int chave){
	ITEM *item= (ITEM*) malloc(sizeof(ITEM));
	if(item != NULL){
		item->chave = chave;
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

LISTA_LIGADA* intercalar(LISTA_LIGADA *lista1,LISTA_LIGADA *lista2){
	//LISTA_LIGADA *lista_intercalada = criar_lista();

	NO *paux1; //no auxliar que guarda subconjuntos da lista1
	NO *paux2; //no auxliar que guarda subconjuntos da lista2
	NO *pauxl1 = lista1->cabeca->prox; // no auxiliar para percorrer os itens da lista1 e criar a lista intercalada
	NO *pauxl2 = lista2->cabeca->prox; // no auxiliar para percorrer os itens da lista2

	while(pauxl1 != NULL || pauxl2 != NULL){
		paux1 = pauxl1->prox; // Guarda subconjunto da lista 1
		pauxl1->prox = pauxl2; // no da lista intercalada aponta para no da lista2

		paux2 = pauxl2->prox; //Gurda subconjunto da lista 2

		pauxl1 = pauxl1->prox; //Avança para o próximo nó da lista intercalada
		pauxl1 -> prox = paux1;// no da lista intercalada aponta para no da lista 2

        pauxl1 = pauxl1->prox;// Avança para o próximo nó da lista intercalada
        pauxl2 = paux2; // lista 2 aponta para subconjunto da lista 2
	}
	return lista1;
}


void imprimir(LISTA_LIGADA *lista){
	NO *paux = lista->cabeca->prox;
	while(paux != NULL){
		printf("%d ",paux->item->chave);
		paux = paux->prox;
	}
}

int main(){
	ITEM *item1 = criar_item(1);
	ITEM *item2 = criar_item(2);
	ITEM *item3 = criar_item(3);
	ITEM *item4 = criar_item(4);
	ITEM *item5 = criar_item(5);
	ITEM *item6 = criar_item(6);

	LISTA_LIGADA *lista1 = criar_lista();
	LISTA_LIGADA *lista2 = criar_lista();

	int controle = inserir(lista1,item1);
	controle = inserir(lista1,item3);
	controle = inserir(lista1,item5);
	controle = inserir(lista2,item2);
	controle = inserir(lista2,item4);
	controle = inserir(lista2,item6);

 	imprimir(lista1);
    printf("\n");
	imprimir(lista2);
	printf("\n");
	lista1 = intercalar(lista1,lista2);
	imprimir(lista1);
	printf("\n");


	return 0;
}
