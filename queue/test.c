#include <stdio.h>
#include "queue.h"

int main()
{
    Queue *queue = queue_new();

    #define LEN 20
    int data[20];
    for (int i=0; i<LEN; ++i)
    {
        data[i] = i;
        enqueue(queue, data+i);
    }
    
    for (int i=0; i<LEN; ++i)
        printf("%d ", *(int *)dequeue(queue));

    queue_free(queue);
}

//cc test.c queue.c ../linkedlist/linkedlist.c  -I../linkedlist