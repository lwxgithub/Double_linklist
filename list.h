#ifndef MY_LIST_H_
#define MY_LIST_H_

struct llist_node_st
{
	void *data;
	struct llist_node_st *prev,*next;
};

typedef struct
{
	int size;
	struct llist_node_st head;
}LLIST;

#define LLIST_FORWARD  1
#define LLIST_BACKWARD 2
typedef void llist_op(void *);

LLIST *llist_create(int);    //������

llist_insert(LLIST *,const void *,int);    //���ݲ���

void llist_travel(LLIST *,llist_op *);    //�������

void llist_destroy(LLIST *);  //��������
#endif
