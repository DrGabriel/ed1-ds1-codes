#include <stdio.h>
#include <sdtlib.h>
#include <item.h>

typedef struct item{
	int key;
}ITEM;

ITEM create_item(ITEM *item, int key){
	item = (ITEM *) malloc(sizeof(ITEM));
	item->key = key;
	return item;
}

void delete_item(ITEM *item){
	free(item);
}