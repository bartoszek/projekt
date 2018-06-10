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

void* Queue_iter(Queue *queue)
{
    if(queue->sizeOfQueue==0)
    {
        fprintf(stderr,"Queue is empty\n");
        return;
    }
    else
    {
        node_t *to_print=queue->head;
        for(int i=0;i<queue->sizeOfQueue;i++) //iterate for head to tail (0...sizeOfQueue-1)
        {
            (*queue->print_function)(to_print->data); //use function pointer on node.data
        }
    }
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

void Queue_iterate_Init(Queue *queue,Queue_iterator *iter)
{
    iter->queue=queue;
    iter->current=queue->head;
}

void* Queue_iterate(Queue_itertor *iter)
{
    void *retval=iter->current->data;  //pointer to current->data
    iter->current=iter->current->next; //move current one step forward
    return iter->current;              //return previus current data pointer
}