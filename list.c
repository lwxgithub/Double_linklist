#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

LLIST *llist_create(int size)
{
	LLIST *newnode;
	newnode = malloc(sizeof(*newnode));
	if(newnode == NULL)
		return NULL;
	
	newnode->size = size;
	newnode->head.prev = newnode->head.next = &newnode->head;
	return newnode;
}

llist_insert(LLIST *ptr,const void *data,int mode)
{
	struct llist_node_st *newnode;
	newnode = malloc(sizeof(*newnode));
	if(newnode == NULL)
		return -1;
	newnode->data = malloc(ptr->size);
	if(newnode->data == NULL)
	{
		free(newnode);
		return -1;
	}	
	memcpy(newnode->data, data, ptr->size);
	
	if(mode == LLIST_FORWARD)
	{
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;

	}
	else if(mode == LLIST_BACKWARD)
	{
		newnode->prev = ptr->head.prev;
		newnode->next = &ptr->head;
	}
	else
	{
		return -2;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	return 0;
}

void llist_tral(LLIST *ptr,llist_op *op)
{
	struct llist_node_st *cur;
	for(cur = ptr->haed.next; cur != ptr->head; cur = cur->next)
		op(cur->data);
}

void llist_destroy(LLIST *ptr)
{
	struct llist_node_st * cur,*node;
	for(cur = ptr->head.next; cur != &ptr->head; cur = node)
	{
		node = cur->next;
		free(cur->data);
		free(cur);
	}
}