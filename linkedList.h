#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <item.h>

typedef struct linked_list LINKED_LIST;

LINKED_LIST * create_list();
void delete_list(LINKED_LIST **list);

int insert_end (LINKED_LIST *list, ITEM *item);
int remove_item(LINKED_LIST *list, int key);
ITEM * show_item(LINKED_LIST *list, int key);

int empty(LINKED_LIST *list);
int full(LINKED_LIST *list);
int size(LINKED_LIST *list);
void printList(LINKED_LIST *list);

#endif