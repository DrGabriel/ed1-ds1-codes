#ifndef ITEM_H
#define ITEM_H

typedef struct item ITEM;

ITEM create_item(int key);
void delete_item(ITEM *item);

#endif