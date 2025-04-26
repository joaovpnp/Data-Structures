#include <stdio.h>
#include <stdlib.h>
#include "../queue.h"

int main() {

    queue *q = createQueue(5, sizeof(int));

    int i;
    for (i = 1; i <= 5; i++) {
        enqueue(&i, q);
    }

    printf("Testing Queue Overflow: ");
    int overflow = 6;
    if (!enqueue(&overflow, q))
        printf("queue overflow\n");
    else
        printf("error\n");

    printf("First Element: ");
    int *peeked = (int*) peek(q);
    if (peeked) {
        printf("%d\n", *peeked);
        free(peeked);
    }

    printf("Removing elements:\n");
    while (!isEmpty(q)) {
        int *val = (int*) dequeue(q);
        if (val) {
            printf("%d ", *val);
            free(val);
        }
    }
    printf("\n");

    printf("Testing Queue Underflow: ");
    if ((int*) dequeue(q) == NULL)
        printf("queue underflow\n");
    else
        printf("error\n");

    printf("Cloning empty queue and testing clone:\n");
    queue *q2 = clone(q);
    printf("Is cloned queue empty? %s\n", isEmpty(q2) ? "Yes" : "No");

    destroyQueue(q);
    destroyQueue(q2);
    printf("\n[Queue deallocated]\n");

    return 0;
}
