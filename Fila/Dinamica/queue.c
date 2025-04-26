#include <stdlib.h>
#include "queue.h"

queue *createQueue(const size_t size) {

    queue *q = malloc(sizeof(queue));
    q->size = size;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

void destroyQueue(queue *q) {

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

void enqueue(const T* value, queue *q) {

    if (q == NULL)
        return;

    node *newNode = malloc(sizeof(node));
    newNode->data = malloc(q->size);
    newNode->next = NULL;
    memcpy(newNode->data, value, q->size);

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

}

T* dequeue(queue *q) {

    if (q == NULL || isEmpty(q))
        return NULL;

    T* value = malloc(q->size);
    memcpy(value, q->front->data, q->size);
    
    node *aux = q->front;
    q->front = aux->next;

    if (aux == q->rear)
        q->rear = NULL;

    free(aux);

    return value;
}

T* peek(const queue *q) {

    if (q == NULL || isEmpty(q))
        return NULL;

    T* value = malloc(q->size);
    memcpy(value, q->front->data, q->size);

    return value;
}

int isEmpty(const queue *q) {
    return q == NULL || q->front == NULL;
}
