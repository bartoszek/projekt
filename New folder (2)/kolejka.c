#include <kolejka.h>

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

int remove_by_index(node_t ** head, int n) 
{
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n-1; i++) 
    {
        if (current->next == NULL) 
        {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}