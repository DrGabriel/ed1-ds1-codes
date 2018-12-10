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

NO * retornaMesmoGrau(int grau, LISTA_LIGADA * pol){
    NO *paux = pol->cabeca->prox;
    NO *pant = NULL;

    while(paux != NULL){
        if(paux->item->grau == grau){
            if(pant == NULL)
                pol->cabeca->prox = paux->prox;
            else
                pant->prox = paux->prox; /*anterior aponta para o proximo do no encontrado*/
            return paux;
        }
        pant = paux;
        paux = paux->prox;
    }
    return NULL;
}
void calculaPx(LISTA_LIGADA *lista, int x){
	float total = 0;

    NO  *paux = lista->cabeca->prox;

	while(paux != NULL){
		total += paux->item->valor * pow(x,paux->item->grau);
		paux = paux->prox;
	}

	printf("Total = %f\n",total);
}

void calculaPmaisQ(LISTA_LIGADA *P, LISTA_LIGADA *Q){
    NO *paux1 = P->cabeca->prox;
    NO *paux2 = Q->cabeca->prox;
    NO *paux3;

    while(paux1 != NULL){
        paux3 = retornaMesmoGrau(paux1->item->grau,Q);
        if(paux3 != NULL){
            paux1->item->valor += paux3->item->valor;
        }
        paux1 = paux1->prox;
    }
    P->fim->prox = paux2;
}

void imprimePol(LISTA_LIGADA *lista){
    NO *paux = lista->cabeca->prox;

    while(paux != NULL){
        printf("%.1fx^%d ",paux->item->valor, paux->item->grau);
        paux = paux->prox;
    }
    printf("\n");

}

int main(){

	LISTA_LIGADA *lista1 = criar_lista();
	LISTA_LIGADA *lista2 = criar_lista();

	ITEM *item1 = criar_item(2.0,1);
	ITEM *item2 = criar_item(34.0,0);
	ITEM *item3 = criar_item(3.0,1);
	ITEM *item4 = criar_item(12.0,2);

	int controle = inserir(lista1,item1);
	controle = inserir(lista1, item2);
	controle = inserir(lista2,item3);
	controle = inserir(lista2,item4);

	imprimePol(lista1);
	imprimePol(lista2);
	calculaPmaisQ(lista1,lista2);
	imprimePol(lista1);
	//calculaPx(lista,2);

	return 0;
}
