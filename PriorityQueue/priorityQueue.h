#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#include <string.h>

typedef void T;
typedef int (*priorityRuler)(T*, T*);

typedef struct n {
    T *data;
    struct n *next; 
} node;

typedef struct {
    node *front;
    node *tale;
    priorityRuler ruler;
    size_t size;
} priorityQueue;

#endif