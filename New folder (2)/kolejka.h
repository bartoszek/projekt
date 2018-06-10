
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
}Queue;

typedef struct _iterator
{
	Queue queue;
	int position;
	node_t *current;
}Queue_iterator;


void Queue_Init(Queue*,size_t);
void Queue_iterate_Init(Queue *,Queue_iterate *)
int Queue_push(Queue*,void*);
int Queue_remove_by_index(Queue*,int);
void* Queue_iterate(Queue_iterator*);
int Queue_pop_head(Queue*);
int Queue_pop_tail(Queue*);
void Queue_clean(Queue*);
