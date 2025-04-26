#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

int main() {

    stack* intStack = createStack(sizeof(int));

    int a = 10, b = 20, c = 30;

    push(&a, intStack);
    push(&b, intStack);
    push(&c, intStack);

    printf("Stack top (peek): ");
    int* topo = (int*)peek(intStack);
    if (topo) {
        printf("%d\n", *topo);
        free(topo);
    }

    printf("Pop:\n");
    while (!stackIsEmpty(intStack)) {
        int* valor = (int*)pop(intStack);
        if (valor) {
            printf("%d\n", *valor);
            free(valor);
        }
    }

    printf("\nTesting underflow: ");
    if (pop(intStack) == NULL)
        printf("stack underflow\n");
    else
        printf("error\n");

    destroyStack(intStack);
    printf("\n[Stack deallocated]\n");

    stack* doubleStack = createStack(sizeof(double));

    double x = 3.14, y = 2.718;

    push(&x, doubleStack);
    push(&y, doubleStack);

    double* doubleTop = (double*)peek(doubleStack);
    if (doubleTop) {
        printf("Double stack top: %.3f\n", *doubleTop);
        free(doubleTop);
    }

    destroyStack(doubleStack);
    printf("\n[Stack deallocated]\n");

    return 0;
}
