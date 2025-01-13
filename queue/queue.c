#include "linkedlist.h"

typedef LinkedList Queue;

Queue *
queue_new(void)
{
    return linkedlist_new();
}

void
queue_free(Queue *queue)
{
    linkedlist_free(queue);
}

size_t
getQueueSize(Queue *queue)
{
    return getLinkedlistSize(queue);
}

int 
enqueue(Queue *queue, void *element)
{
   return addTail(queue, element);
}


void *
dequeue(Queue *queue)
{
    Node *head = getHead(queue);
    void *ret = getNodeData(head);
    deleteNode(queue, head);
    return ret;
}
