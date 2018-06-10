
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	void * data;
	struct node *next;
}node_t;

typedef struct _queue
{
	int sizeOfQueue;
	size_t data_size;
	node_t *head;
	node_t *tail;
	void (*print_function)(void*);
}Queue;


void Queue_Init(Queue*,size_t,void (*print_function)(void*));
int Queue_push(Queue*,void*);
int Queue_remove_by_index(Queue*,int);
void Queue_print(Queue*);


int pop(node_t **pop_head )
{
	if((*pop_head)->next==NULL)
	{
		fprintf ( stderr ,  "pop fail , single element queue \n" ); 
  		return ( - 1 );
	}
	else
	{
		node_t *del_head=*pop_head;
		*pop_head=(*pop_head)->next;
		free(del_head);
	}

}

void clean(node_t **clean_head)
{
	do
	{
		pop(clean_head);
	}
	while((*(clean_head))->next!=NULL);
	free(*clean_head);
	*clean_head=NULL;
}
