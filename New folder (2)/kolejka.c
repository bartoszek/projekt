#include <kolejka.h>
#include <string.h>


void Queue_Init(Queue *queue,size_t data_size)
{
    queue->sizeOfQueue=0;
    queue->data_size=data_size;
    queue->head=NULL;
    queue->tail=NULL;
}

int Queue_push(Queue *queue , void* data)
{
    node_t *newNode = malloc ( sizeof ( node_t ) ); 
    if ( newNode  ==  NULL )  
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
    memcpy(newNode->data,data,queue->data_size);
    if (queue->sizeOfQueue==0){
        queue->head=queue->tail=newNode;
    }
    else
    {
        queue->tail->next=newNode; // [head (next=second_node)] [second_node]... [tail (next=NULL)] >>> ... [tail(next=newNode)]                             (set newNode as next after tail)
        queue->tail=newNode; //       [head (next=second_node)] [second_node]... [tail(next=newNode)] >>> ... [second_to_last (next=newNode)] [tail=newNode] (set tail node to newNode)
    }
    queue->sizeOfQueue++;
    return 0;
}

int Queue_remove_by_index(Queue *queue, int n) //index for 1 to queue->sizeOfQueue
{
    if(n>0 && n<=queue->sizeOfQueue)
    {
        node_t *to_remove=NULL;
        node_t *to_reconect=NULL;
        if(n==1) //remove head
        {
            to_remove=queue->head;
            queue->head=to_remove->next;
        }
        else //remove further away
        {
            to_remove=queue->head->next;    //remove next after head
            to_reconect=queue->head;        //recconect with head
            for (int i = 1; i < n; i++)     //iterate n-1 times moving remove and recconect to next elem
            {
                to_remove=to_remove->next;
                to_reconect=to_reconect->next;
            }
            to_reconect->next=to_remove->next;       //reconnect previus with one after the remove node ... [to_reconnect(next=to_remove)] [to_remove] [to_remove->next]
        }
        free(to_remove);
        queue->sizeOfQueue--;
    }
    else if(queue->sizeOfQueue!=0)
    {
        fprintf ( stderr , "index out of range in queue.remove_by_index\n" );
        return ( 1 );
    }
    else
    {
        fprintf ( stderr , "Queue is empty\n" );
        return ( 2 );
    }
    return 0;
}

int Queue_pop_head(Queue *queue)
{
    int retval=Queue_remove_by_index(queue,1);
    return retval;
}

int Queue_pop_tail(Queue *queue)
{
    int retval=Queue_remove_by_index(queue,queue->sizeOfQueue);
    return retval;
}

void Queue_clean(Queue *queue)
{
    while(Queue_pop_head(queue)==0);
    return;
}

void Queue_iterator_Init(Queue_iterator* iter,Queue* queue)
{
    iter->queue=queue;
    iter->current=queue->head;
    iter->last=NULL;
    iter->second_to_last=NULL;
}

void* Queue_next(Queue_iterator *iter)
{
    if(iter->current==NULL)
    {
	fprintf(stderr, "Queue is empty\n");
	return NULL;
    }
    void *retval=iter->current->data;  //pointer to current->data
    iter->second_to_last=iter->last;   //move last to second_to_last
    iter->last=iter->current;          //move current to last
    iter->current=iter->current->next; //move current->next to current
    return retval;              //return previus current data pointer
}

void Queue_remove(Queue_iterator* iter)
{
    if(iter->second_to_last==NULL) // need to remove head;
    {
        Queue_pop_head(iter->queue);
    }
    else
    {
        iter->second_to_last->next=iter->last->next; //recoonect [second_to_last] [last] [current] >>> [last] [current]
        iter->queue->sizeOfQueue--;
    }
    free(iter->last);
}
