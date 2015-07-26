#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NAMESIZE 32
struct person_st
{
	int id;
	char name[NAMESIZE];
	int age;
}

void print_s(void *data)
{
	struct person_st *d = data;
	printf("%d %s %d\n",d->id,d->name,d->age);
}

int main()
{
	LLITS *handle;
	int i;
	struct person_st tmp;
	
	handle = llist_create(sizeof(struct person_st));
	if(handle== NULL)
		return -1;
	
	for(i = 0; i < 6; i++)
	{
		tmp.id = i;
		tmp.age = 20 + i;
		snprintf(tmp.name,NAMESIZE,"person%d",i);
		
		llist_insert(handle,&tmp,LLIST_FORWARD);
	}
	
	llist_travel(handle,print_s);
	
	llist_destroy(handle);
	return 0;
}