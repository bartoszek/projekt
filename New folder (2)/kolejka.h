
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


void Queue_Init(Queue *queue,size_t data_size){
	queue->sizeOfQueue=0;
	queue->data_size=data_size;
	queue->head=NULL;
	queue->tail=NULL;
}


int push(Queue*,void*);

int push(Queue *queue , void* data)
{
 	node_t *newNode = malloc ( sizeof ( node_t ) ); 
	if ( temp  ==  NULL )  
	{ 
  		fprintf(stderr ,"malloc failed in queue.push when creating new node\n"); 
  		return ( 2 );
  	}
  	newNode->next=NULL;
  	newNode->data = malloc (queue->data_size);
  	if ( newNode->data == NULL)
  	{
  		fprintf ( stderr ,  "malloc failed in queue.push when creating data for new node \n " ); 
  		return ( 3 );
  	}
  	memcpy(newNode->data,data,queue->data_size)
  	if (queue->sizeOfQueue==0){
  		queue->head=queue->tail=newNode;
  	}
  	else
  	{
  		queue->tail->next=newNode; // [head (next=second_node)] [second_node]... [tail (next=NULL)] >>> ... [tail(next=newNode)]                             (set newNode as next after tail)
  		queue->tail=newNode; //       [head (next=second_node)] [second_node]... [tail(next=newNode)] >>> ... [second_to_last (next=newNode)] [tail=newNode] (set tail node to newNode)
  	}
}

void _print( node_t *print_head)
{
	if(print_head==NULL)
	{
		printf("\n");
		return;
	}
	else
	{
		printf("print_head.val=%d\n",print_head->val);
		_print(print_head->next); 
	}

}


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
