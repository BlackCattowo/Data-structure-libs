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

// Function declarations
void push_element(stack *S, int value);
void pop_element(stack *S);
int last_element(stack *S);
void free_stack(stack *S);
void print_stack(stack *S);
void set_stack(stack *S, size_t initial_size);

/**
 * Pushes a new element to the top of the stack.
 * If the stack is full, it reallocates memory and doubles the size of the stack.
 *
 * @param S Pointer to the stack.
 * @param value Integer value to be added to the stack.
 */
void push_element(stack *S, int value)
{
    if (S->count < S->size)
    {
        S->element[S->count++] = value;
    }
    else
    {
        size_t new_size = S->size * 2;
        S->element = (int *)realloc(S->element, new_size * sizeof(int));
        if (S->element)
        {
            S->size = new_size;
            S->element[S->count++] = value;
        }
        else
        {
            fprintf(stderr, "Error reallocating memory.\n");
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * Pops (removes) the last element from the stack (LIFO).
 *
 * @param S Pointer to the stack.
 */
void pop_element(stack *S)
{
    if (S->count > 0)
    {
        S->count--;
    }
    else
    {
        printf("Stack is empty. Nothing to pop.\n");
    }
}

/**
 * Returns the last element in the stack.
 * If the stack is empty, prints an error and returns -1.
 *
 * @param S Pointer to the stack.
 * @return Last element of the stack or -1 if empty.
 */
int last_element(stack *S)
{
    if (S->count > 0)
    {
        return S->element[S->count - 1];
    }
    else
    {
        fprintf(stderr, "Stack is empty. No last element.\n");
        return -1;
    }
}

/**
 * Frees the memory allocated for the stack.
 *
 * @param S Pointer to the stack.
 */
void free_stack(stack *S)
{
    free(S->element);
    S->element = NULL;
    S->count = 0;
    S->size = 0;
}

/**
 * Prints the elements of the stack to the console.
 * If the stack is empty, prints a message indicating that.
 *
 * @param S Pointer to the stack.
 */
void print_stack(stack *S)
{
    if (S->count == 0)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (size_t i = 0; i < S->count; i++)
        {
            printf("%d ", S->element[i]);
        }
        printf("\n");
    }
}

/**
 * Initializes the stack with a specified initial size.
 * Allocates memory for the stack and sets the size and count.
 * Also assigns function pointers for operations.
 *
 * @param S Pointer to the stack to initialize.
 * @param initial_size Initial size of the stack.
 */
void set_stack(stack *S, size_t initial_size)
{
    S->size = initial_size;
    S->count = 0;
    S->element = (int *)malloc(S->size * sizeof(int));
    if (S->element == NULL)
    {
        fprintf(stderr, "Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    S->push = push_element;
    S->pop = pop_element;
    S->last = last_element;
    S->free = free_stack;
    S->print = print_stack;
}

#endif // STACKLIB_H
