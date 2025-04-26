#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue *createQueue(const int LENGTH, size_t size) {

    if (LENGTH <= 0)
        return NULL;

    queue *q = malloc(sizeof(queue));
    q->data = malloc(size*LENGTH);

    q->LENGTH = LENGTH;
    q->front = -1;
    q->rear = -1;
    q->size = size;

    return q;
}

void destroyQueue(queue *q) {
    if (q != NULL) {
        q->front = -1;
        q->rear = -1;
        q->LENGTH = -1;
        q->size = 0;

        if (q->data != NULL)
            free(q->data);
        
        free(q);
    }
}

int nextPosition(const int i, const int LENGTH) {
    return (i + 1) % LENGTH;
}

int enqueue(const T* value, queue *q) {

    if (q == NULL || isFull(q))
        return 0;

    q->rear = nextPosition(q->rear, q->LENGTH);
    memcpy(AT(q, q->rear, q->size), value, q->size);

    if (q->front == -1)
        q->front = 0;
    
    return 1;
}

T* dequeue(queue *q) {

    if (q == NULL || isEmpty(q))
        return NULL;

    T* value = malloc(q->size);
    memcpy(value, AT(q, q->front, q->size), q->size);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = nextPosition(q->front, q->LENGTH);
    }

    return value;
}

T* peek(const queue *q) {

    if (q == NULL || q->data == NULL || isEmpty(q))
        return NULL;

    T* value = malloc(q->size);
    memcpy(value, AT(q, q->front, q->size), q->size);
    
    return value;
}

int isEmpty(const queue *q) {
    return q->front == -1;
}

int isFull(const queue *q) {
    return !isEmpty(q) && nextPosition(q->rear, q->LENGTH) == q->front;
}

queue *clone(const queue *q) {

    if (q == NULL)
        return NULL;

    queue *copy = malloc(sizeof(queue));
    if (copy == NULL)
        return NULL;

    copy->front = q->front;
    copy->rear = q->rear;
    copy->LENGTH = q->LENGTH;
    copy->size = q->size;

    copy->data = malloc(q->size*q->LENGTH);

    int i = q->front;
    for(; i != nextPosition(q->rear, q->LENGTH); i = nextPosition(i, q->LENGTH))
        memcpy(AT(copy, i, q->size), AT(q, i, q->size), q->size);
    
    return copy;
}
