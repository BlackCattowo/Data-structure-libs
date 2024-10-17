#ifndef QUEUELIB_H
#define QUEUELIB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *element;
    size_t size;
    size_t count;
    void (*push)(struct Queue *Q, int value);
    void (*eject)(struct Queue *Q);
    int (*first)(struct Queue *Q);
    int (*last)(struct Queue *Q);
    void (*free)(struct Queue *Q);
    void (*print)(struct Queue *Q);
} queue;

// Function declarations
void push_element(queue *Q, int value);
void eject_element(queue *Q);
int first_element(queue *Q);
int last_element(queue *Q);
void free_queue(queue *Q);
void print_queue(queue *Q);
void set_queue(queue *Q, size_t initial_size);

/**
 * Pushes a new element to the end of the queue.
 * If the queue is full, it reallocates memory and doubles the size of the queue.
 *
 * @param Q Pointer to the queue.
 * @param value Integer value to be added to the queue.
 */
void push_element(queue *Q, int value)
{
    if (Q->count < Q->size)
    {
        Q->element[Q->count++] = value;
    }
    else
    {
        size_t new_size = Q->size * 2;
        Q->element = (int *)realloc(Q->element, new_size * sizeof(int));
        if (Q->element)
        {
            Q->size = new_size;
            Q->element[Q->count++] = value;
        }
        else
        {
            fprintf(stderr, "Error reallocating memory.\n");
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * Ejects the first element from the queue (FIFO).
 * All elements are shifted left to maintain the order.
 *
 * @param Q Pointer to the queue.
 */
void eject_element(queue *Q)
{
    if (Q->count > 0)
    {
        for (size_t i = 0; i < Q->count - 1; i++)
        {
            Q->element[i] = Q->element[i + 1];
        }
        Q->count--;
    }
    else
    {
        printf("Queue is empty. Nothing to eject.\n");
    }
}

/**
 * Returns the first element in the queue.
 * If the queue is empty, prints an error and returns -1.
 *
 * @param Q Pointer to the queue.
 * @return First element of the queue or -1 if empty.
 */
int first_element(queue *Q)
{
    if (Q->count > 0)
    {
        return Q->element[0];
    }
    else
    {
        fprintf(stderr, "Queue is empty. No first element.\n");
        return -1;
    }
}

/**
 * Returns the last element in the queue.
 * If the queue is empty, prints an error and returns -1.
 *
 * @param Q Pointer to the queue.
 * @return Last element of the queue or -1 if empty.
 */
int last_element(queue *Q)
{
    if (Q->count > 0)
    {
        return Q->element[Q->count - 1];
    }
    else
    {
        fprintf(stderr, "Queue is empty. No last element.\n");
        return -1;
    }
}

/**
 * Frees the memory allocated for the queue.
 *
 * @param Q Pointer to the queue.
 */
void free_queue(queue *Q)
{
    free(Q->element);
    Q->element = NULL;
    Q->count = 0;
    Q->size = 0;
}

/**
 * Prints the elements of the queue to the console.
 * If the queue is empty, prints a message indicating that.
 *
 * @param Q Pointer to the queue.
 */
void print_queue(queue *Q)
{
    if (Q->count == 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (size_t i = 0; i < Q->count; i++)
        {
            printf("%d ", Q->element[i]);
        }
        printf("\n");
    }
}

/**
 * Initializes the queue with a specified initial size.
 * Allocates memory and sets the size and count.
 * Also assigns function pointers for queue operations.
 *
 * @param Q Pointer to the queue to initialize.
 * @param initial_size Initial size of the queue.
 */
void set_queue(queue *Q, size_t initial_size)
{
    Q->size = initial_size;
    Q->count = 0;
    Q->element = (int *)malloc(Q->size * sizeof(int));
    if (Q->element == NULL)
    {
        fprintf(stderr, "Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    Q->push = push_element;
    Q->eject = eject_element;
    Q->first = first_element;
    Q->last = last_element;
    Q->free = free_queue;
    Q->print = print_queue; // Assign the print function
}

#endif // QUEUELIB_H
