#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

priorityQueue *createQueue(const size_t size, priorityRuler ruler) {

    priorityQueue *q = malloc(sizeof(priorityQueue));
    q->size = size;
    q->ruler = ruler;
    q->front = NULL;
    q->tale = NULL;

    return q;
}

void destroyQueue(priorityQueue *q) {

    if (q == NULL || isEmpty(q))
        return;
    
    node *aux = q->front;
    while (aux != NULL) {
        q->front = aux->next;
        free(aux->data);
        free(aux);
        aux = q->front;
    }

    free(q);
}

void enqueue(const T* value, priorityQueue *q) {

    if (q == NULL)
        return;

    node *newNode = malloc(sizeof(node));
    newNode->data = malloc(q->size);
    newNode->next = NULL;
    memcpy(newNode->data, value, q->size);

    if (q->tale == NULL) {
        q->front = newNode;
        q->tale = newNode;
    } else {

        node *aux0 = q->front;
        node *aux1 = q->front;
        while (q->ruler(value, aux1->data) == -1) {
            aux0 = aux1;
            aux1 = aux1->next;
        }

        newNode->next = aux1;
        aux0->next = newNode;
    }

}

T* dequeue(priorityQueue *q) {

    if (q == NULL || isEmpty(q))
        return NULL;

    T* value = malloc(q->size);
    memcpy(value, q->front->data, q->size);
    
    node *aux = q->front;
    q->front = aux->next;

    if (aux == q->tale)
        q->tale = NULL;

    free(aux);

    return value;
}

T* peek(const priorityQueue *q) {

    if (q == NULL || isEmpty(q))
        return NULL;

    T* value = malloc(q->size);
    memcpy(value, q->front->data, q->size);

    return value;
}

int isEmpty(const priorityQueue *q) {
    return q == NULL || q->front == NULL;
}
