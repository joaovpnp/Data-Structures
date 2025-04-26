#ifndef _QUEUE_H
#define _QUEUE_H

#include <string.h>

typedef void T;

typedef struct n {
    T* data;
    struct n *next;
} node;

typedef struct {
    node *front;
    node *rear;
    size_t size;
} queue;

queue *createQueue(const size_t size);
void destroyQueue(queue *q);
void enqueue(const T* value, queue *q);
T* dequeue(queue *q);
T* peek(const queue *q);
int isEmpty(const queue *q);

#endif