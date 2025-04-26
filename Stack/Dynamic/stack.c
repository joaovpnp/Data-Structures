#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

node* createNode() {
    node *n = malloc(sizeof(node));
    n->data = NULL;
    n->next = NULL;
    return n;
}

stack* createStack(const size_t size) {

    stack* s = malloc(sizeof(stack));
    s->top = NULL;
    s->size = size;

    return s;
}

void destroyStack(stack* s) {

    if (s == NULL)
        return;

    node *aux = s->top;

    while (aux != NULL) {
        node *temp = aux->next;
        free(aux->data);
        free(aux);
        aux = temp;
    }

    free(s);
}

void push(T* value, stack* s) {

    if (s == NULL)
        return;

    node *newNode = createNode();
    newNode->data = malloc(s->size);
    memcpy(newNode->data, value, s->size);

    newNode->next = s->top;
    s->top = newNode;

}

T* pop(stack* s) {

    if (stackIsEmpty(s))
        return NULL;

    node *aux = s->top;
    T* data = malloc(s->size);
    memcpy(data, aux->data, s->size);
    s->top = aux->next;

    free(aux->data);
    free(aux);

    return data;
}

T* peek(const stack *s) {

    if (stackIsEmpty(s))
        return NULL;
    
    T* value = malloc(s->size);
    memcpy(value, s->top->data, s->size);

    return value;
}

int stackIsEmpty(const stack *s) {
    return s == NULL || s->top == NULL;
}
