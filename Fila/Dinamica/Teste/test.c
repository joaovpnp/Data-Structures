#include <stdio.h>
#include <stdlib.h>
#include "../queue.h"

int main() {
    queue *q = createQueue(sizeof(int));

    int values[] = {10, 20, 30, 40, 50};

    printf("\n[Adding elements...]\n");
    for (int i = 0; i < 5; i++) {
        printf("Element: %d\n", values[i]);
        enqueue(&values[i], q);
    }

    int *v = (int*) peek(q);
    if (v != NULL) {
        printf("\nFirst element (peek): %d\n", *v);
        free(v);
    }

    printf("\n[Removing elements...]\n");
    while (!isEmpty(q)) {
        int *element = (int*) dequeue(q);
        printf("Element: %d\n", *element);
        free(element);
    }

    printf("Testing Queue Underflow: ");
    if ((int*) dequeue(q) == NULL)
        printf("queue underflow\n");
    else
        printf("error\n");

    printf("\n[Adding elements...]\n");
    for (int i = 0; i < 5; i++) {
        printf("Element: %d\n", values[i]);
        enqueue(&values[i], q);
    }

    destroyQueue(q);
    printf("\n[Queue deallocated]\n");

    return 0;
}