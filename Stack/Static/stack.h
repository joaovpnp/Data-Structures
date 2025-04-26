#ifndef _STACK_H
#define _STACK_H

#include <string.h>

#define AT(s, i, size) ((char*)(s)->data + (i)*(size))

typedef void T;

typedef struct {
    int top;
    int LENGTH;
    size_t size;
    T* data;
} stack;

stack* createStack(const int LENGTH, const size_t size);
void destroyStack(stack* s);
int push(T* value, stack* s);
T* pop(stack* s);
T* peek(const stack *s);
int stackIsEmpty(const stack *s);
int stackIsFull(const stack *s);

#endif