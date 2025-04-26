#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *createStack(const int LENGTH, const size_t size) {

    stack *s = malloc(sizeof(stack));
    if (s == NULL)
        return NULL;
    
    s->data = malloc(size*LENGTH);
    if (s->data == NULL)
        return NULL;

    s->size = size;
    s->top = 0;
    s->LENGTH = LENGTH;

    return s;
}

void destroyStack(stack *s) {

    if (s == NULL)
        return;

    if (s->data != NULL)
        free(s->data);

    free(s);
}

int push(T* value, stack *s) {

    if (stackIsFull(s))
        return 0;
    
    memcpy(AT(s, s->top, s->size), value, s->size);
    s->top++;

    return 1;
}

T* pop(stack *s) {

    if (stackIsEmpty(s))
        return NULL;
    
    s->top--;
    
    T* value = malloc(s->size);
    memcpy(value, AT(s, s->top, s->size), s->size);

    return value;
}

T* peek(const stack *s) {

    if (stackIsEmpty(s))
        return NULL;
    
    T* value = malloc(s->size);
    memcpy(value, AT(s, s->top-1, s->size), s->size);

    return value;
}

int stackIsEmpty(const stack *s) {
    return s == NULL || s->top == 0;
}

int stackIsFull(const stack *s) {
    return s == NULL || s->top == s->LENGTH;
}
