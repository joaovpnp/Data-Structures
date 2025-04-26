#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

typedef struct {
    char name[20];
    int age;
} Person;

int main() {

    printf("\n[Testing int Stack]\n\n");
    stack* intStack = createStack(3, sizeof(int));
    int a = 10, b = 20, c = 30;

    push(&a, intStack);
    push(&b, intStack);
    push(&c, intStack);

    int* intValue = (int*)peek(intStack);
    printf("Stack top (peek): %d\n", *intValue);
    free(intValue);

    printf("\nTesting overflow: ");
    if (!push(&a, intStack))
        printf("stack overflow\n");
    else
        printf("error\n");

    while (!stackIsEmpty(intStack)) {
        int* v = (int*)pop(intStack);
        printf("Pop (int): %d\n", *v);
        free(v);
    }

    printf("\nTesting underflow: ");
    if ((int*) pop(intStack) == NULL)
        printf("stack underflow\n");
    else
        printf("error\n");

    destroyStack(intStack);
    printf("[Stack deallocated]\n");

    printf("\n[Testing double Stack]\n\n");
    stack* doubleStack = createStack(3, sizeof(double));
    double x = 3.14, y = 2.718;

    push(&x, doubleStack);
    push(&y, doubleStack);

    double* valorDouble = (double*)peek(doubleStack);
    printf("\nDouble stack top (peek): %.3f\n", *valorDouble);
    free(valorDouble);

    while (!stackIsEmpty(doubleStack)) {
        double* valor = (double*)pop(doubleStack);
        printf("Pop (double): %.3f\n", *valor);
        free(valor);
    }
    destroyStack(doubleStack);
    printf("[Stack deallocated]\n");

    printf("\n[Testing person Stack]\n\n");
    stack* personStack = createStack(2, sizeof(Person));
    Person p1 = {"Alice", 25};
    Person p2 = {"Bob", 30};

    push(&p1, personStack);
    push(&p2, personStack);

    Person* personTop = (Person*)peek(personStack);
    printf("\nPerson stack top (peek): %s, %d years\n", personTop->name, personTop->age);
    free(personTop);

    while (!stackIsEmpty(personStack)) {
        Person* p = (Person*)pop(personStack);
        printf("Pop (Person): %s, %d years\n", p->name, p->age);
        free(p);
    }
    destroyStack(personStack);
    printf("\n[Stack deallocated]\n");

    return 0;
}
