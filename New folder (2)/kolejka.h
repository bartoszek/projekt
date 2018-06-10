
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
	Queue *queue;
	node_t *last;
	node_t *current;
}Queue_iterator;


void Queue_Init(Queue*,size_t);
int Queue_push(Queue*,void*);
int Queue_remove_by_index(Queue*,int);
int Queue_pop_head(Queue*);
int Queue_pop_tail(Queue*);
void Queue_clean(Queue*);

void Queue_iterator_Init(Queue_iterator*,Queue*);
void* Queue_next(Queue_iterator*);
void Queue_remove(Queue_iterator*);