#include <stdio.h>

#include "stack.h"

int main() {
    printf("Hello, World!\n");
    int n = 7;

    Stack* my_stack = init_stack(n);

    printf("Начните запихивать в стек, затем как закончите введите\n");
    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        push(my_stack, input);
    }

    for (int i = 0; i < n; i++) {
        printf("%d>", my_stack->array[i]);
    }

    destroy(my_stack);
}