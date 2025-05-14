#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#include <string.h>

typedef void T;
typedef int(*priorityRuler)(const T*, const T*);

typedef enum {
    MIN=-1,
    MAX=1
} PRIORITY_TYPE;

typedef struct n {
    T *data;
    struct n *next; 
} node;

typedef struct {
    node *front;
    node *tale;
    PRIORITY_TYPE pType;
    priorityRuler ruler;
    size_t size;
} priorityQueue;

priorityQueue *createQueue(const size_t size, priorityRuler ruler, PRIORITY_TYPE pType);
void destroyQueue(priorityQueue *q);
void enqueue(const T* value, priorityQueue *q);
T* dequeue(priorityQueue *q);
T* peek(const priorityQueue *q);
int isEmpty(const priorityQueue *q);

#endif