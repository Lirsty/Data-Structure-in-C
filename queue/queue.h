#ifndef _QUEUE_H

#define _QUEUE_H
#include <stddef.h>

typedef struct _queue Queue;
Queue *queue_new(void);
void queue_free(Queue *queue);
size_t getQueueSize(Queue *queue);
int enqueue(Queue *queue, void *data);
void *dequeue(Queue *queue);


#endif /* _QUEUE_H */
