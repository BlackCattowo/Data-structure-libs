#include "queueLib.h"

// Pushes a new element to the queue
void push_element(queue *Q, int value)
{
    if (Q->count < Q->size)
    {
        Q->element[(Q->front + Q->count) % Q->size] = value;
        Q->count++;
    }
    else
    {
        size_t new_size = Q->size * 2;
        Q->element = (int *)realloc(Q->element, new_size * sizeof(int));
        if (Q->element)
        {
            Q->size = new_size;
            Q->element[(Q->front + Q->count) % Q->size] = value;
            Q->count++;
        }
        else
        {
            fprintf(stderr, "Error reallocating memory.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Ejects the first element from the queue
void eject_element(queue *Q)
{
    if (Q->count > 0)
    {
        Q->front = (Q->front + 1) % Q->size;
        Q->count--;
    }
}

// Returns the first element in the queue
int first_element(queue *Q)
{
    if (Q->count > 0)
        return Q->element[Q->front];
    else
        fprintf(stderr, "Queue is empty.\n");
    return -1;
}

// Returns the last element in the queue
int last_element(queue *Q)
{
    if (Q->count > 0)
        return Q->element[(Q->front + Q->count - 1) % Q->size];
    else
        fprintf(stderr, "Queue is empty.\n");
    return -1;
}

// Frees the memory allocated for the queue
void free_queue(queue *Q)
{
    free(Q->element);
    Q->element = NULL;
    Q->count = 0;
    Q->size = 0;
    Q->front = 0;
}

// Prints the elements of the queue
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
            printf("%d ", Q->element[(Q->front + i) % Q->size]);
        }
        printf("\n");
    }
}

// Initializes the queue with a specified initial size
void set_queue(queue *Q, size_t initial_size)
{
    Q->size = initial_size;
    Q->count = 0;
    Q->front = 0;
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
    Q->print = print_queue;
}
