#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "item.h"

/*O nó é a base para se criar uma lista ligada ele nada mais é do que um ponteiro que contem o endereço de memoria
do item e contém o o endereço de memoria do proximo nó, ligando assim a lista

Node is the basis to create a linked list, basically it's a pointer that contains the memory adress of a item and
have the memory adress to the next node, thus linking the list */

typedef struct NODE{
	ITEM *item;
	struct NODE *next;
}NODE;

typedef struct linked_list{
	NODE *begin;
	NODE *end;
	int size;
}LINKED_LIST;

void delete_node(NODE *node){
	delete_item(&(node->item));
	free(node);
}

LINKED_LIST *create_list(){
	LINKED_LIST *list = (LINKED_LIST *) malloc(sizeof(LINKED_LIST));

	if(list != NULL){
		list->begin = NULL;
		list->end = NULL;
		list->size = 0;
	}

	return list;
}

int insert_end(LINKED_LIST *list, ITEM *item){
	NODE *newp = (NODE *) malloc(sizeof(NODE));

	if(newp != NULL){
		newp->item = item;
		newp->next = NULL;

		if(list->begin == NULL){
			list->begin = newp;
		}else{
			list->end->next = newp;
		}

		list->end = newp;
		list->size++;

		return 1;
	}else{
		return 0;
	}
}
ITEM *find_item(LINKED_LIST *list, int key){
	NODE *auxp = list->begin;

	while(auxp != NULL){
		if(auxp->item->key == key){
			return auxp->item;
		}

		auxp = auxp->next;
	}

	return NULL;
}

int empty(LINKED_LIST *list){
	return (list->begin == NULL);
}