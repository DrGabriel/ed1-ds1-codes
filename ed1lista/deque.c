#include <stdio.h>
#include <stdlib.h>

typedef struct DEQUE{

	int inicio1,inicio2;
	ITEM * items;
}DEQUE;

DEQUE* criar_deque(int tam){
	DEQUE * deque = (DEQUE *) malloc(sizeof(DEQUE));
	if(deque != NULL){
		deque->inicio1 = 0;
		deque->inicio2 = 0;
		deque->items = (ITEM *) malloc(sizeof(ITEM));
		if(deque->items != NULL)
			return deque;
	}
	return NULL;
}

