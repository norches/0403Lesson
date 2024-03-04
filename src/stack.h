#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* init_stack(int capacity);
int is_full(Stack* stack);
int is_empty(Stack* stack);
void push(Stack* stack, int el);
int peek(Stack* stack);
int pop(Stack* stack);
void destroy(Stack* stack);

#endif