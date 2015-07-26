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

LLIST *llist_create(int);    //链表创建

llist_insert(LLIST *,const void *,int);    //数据插入

void llist_travel(LLIST *,llist_op *);    //链表遍历

void llist_destroy(LLIST *);  //链表销毁
#endif
