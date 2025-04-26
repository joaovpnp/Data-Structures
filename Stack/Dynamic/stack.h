#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>

typedef void T;

typedef struct n {
    T *data;
    struct n *next;
} node;

typedef struct {
    node *top;
    size_t size;
} stack;

stack* createStack(const size_t size);
void destroyStack(stack* s);
void push(T* value, stack* s);
T* pop(stack* s);
T* peek(const stack *s);
int stackIsEmpty(const stack *s);

#endif