#include <stdio.h>
#include <stdlib.h>
#include "../priorityQueue.h"

typedef struct {
    int value;
} Item;

int compareItem(const Item *a, const Item *b) {
    if (a->value < b->value) return -1;
    else if (a->value > b->value) return 1;
    else return 0;
}

void printItem(Item *item) {
    if (item != NULL) {
        printf("%d ", item->value);
    }
}

void testPriorityQueue(PRIORITY_TYPE type, const char *typeName) {
    printf("Testing %s priority queue:\n", typeName);

    priorityQueue *q = createQueue(sizeof(Item), (priorityRuler)compareItem, type);

    Item items[] = {{10}, {5}, {20}, {15}, {5}};
    printf("Enqueuing: ");
    for (int i = 0; i < 5; i++) {
        printItem(&items[i]);
        enqueue(&items[i], q);
    }
    
    printf("\nDequeuing elements: ");
    while (!isEmpty(q)) {
        Item *v = (Item *)dequeue(q);
        printItem(v);
        free(v);
    }
    printf("\n");

    destroyQueue(q);
}

int main() {
    
    printf("\n\n");
    testPriorityQueue(MAX, "MAX");

    printf("\n\n");
    testPriorityQueue(MIN, "MIN");

    printf("\n\n");
    return 0;
}