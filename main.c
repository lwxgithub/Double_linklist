#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NAMESIZE 32
struct person_st
{
	int id;
	char name[NAMESIZE];
	int age;
};

static void print_s(void *data)
{
	struct person_st *d = data;
	printf("%d %s %d\n",d->id,d->name,d->age);
}

static int id_cmp(const void *key,const void *data)
{
    const int *k = key;
    const struct person_st *d = data;
    return (*k - d->id);
}

static int name_cmp(const void *key,const void *data)
{
    const char *n = key;
    const struct person_st *d = data;
    return strcmp(n , d->name);
}

int main()
{
	LLIST *handle;
	int i ,ret, id = 3;
    char *name = "person2";
	struct person_st tmp, *datap;
	
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
	printf("\n\n");

    ret =  llist_fetch(handle,name,name_cmp,&tmp);
    if(ret == 0)
        print_s(&tmp);
    printf("\n\n");
   
  //  llist_delete(handle,&id,id_cmp);
  //  llist_travel(handle,print_s);

#if 0
    //datap = llist_find(handle,&id,id_cmp);
    datap = llist_find(handle,name,name_cmp);
        if(datap == NULL)
            printf("ca not find!\n");
        else
            print_s(datap);
#endif
	llist_destroy(handle);
	return 0;
}
