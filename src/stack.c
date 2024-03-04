#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* init_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->array = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;

    return stack;
}

int is_full(Stack* stack) { return stack->top == stack->capacity; }

int is_empty(Stack* stack) { return stack->top == -1; }

void push(Stack* stack, int el) {
    if (is_full(stack)) exit(1);
    (stack->top)++;
    stack->array[stack->top] = el;
}

int peek(Stack* stack) {
    if (is_empty(stack)) exit(1);
    return stack->array[stack->top];
}

int pop(Stack* stack) {
    int popped_value = peek(stack);
    (stack->top)--;
    return popped_value;
}

void destroy(Stack* stack) {
    free(stack->array);
    free(stack);
}
