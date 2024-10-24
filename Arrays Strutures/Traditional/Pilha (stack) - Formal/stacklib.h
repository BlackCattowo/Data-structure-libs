#ifndef STACKLIB_H
#define STACKLIB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *element;
    size_t size;
    size_t count;
    void (*push)(struct Stack *S, int value);
    void (*pop)(struct Stack *S);
    int (*last)(struct Stack *S);
    void (*free)(struct Stack *S);
    void (*print)(struct Stack *S);
} stack;

void set_stack(stack *S, size_t initial_size);
void push_element(stack *S, int value);
void pop_element(stack *S);
int last_element(stack *S);
void free_stack(stack *S);
void print_stack(stack *S);

#endif // STACKLIB_H
