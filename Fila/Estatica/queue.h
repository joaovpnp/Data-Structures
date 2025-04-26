#ifndef _QUEUE_H
#define _QUEUE_H

#include <string.h>

#define AT(q, i, size) ((char*)(q)->data + (i)*(size))

typedef void T;

typedef struct {
    int LENGTH;
    int front;
    int rear;
    size_t size;
    T *data;
} queue;

queue *createQueue(const int LENGTH, size_t size);
void destroyQueue(queue *q);
int enqueue(const T* value, queue *q);
T* dequeue(queue *q);
T* peek(const queue *q);
int isEmpty(const queue *q);
int isFull(const queue *q);
queue *clone(const queue *q);

#endif