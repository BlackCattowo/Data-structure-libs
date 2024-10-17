#ifndef QUEUELIB_H
#define QUEUELIB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *element;
    size_t size;
    size_t count;
    size_t front;  // Pointer to the front element
    void (*push)(struct Queue *Q, int value);
    void (*eject)(struct Queue *Q);
    int (*first)(struct Queue *Q);
    int (*last)(struct Queue *Q);
    void (*free)(struct Queue *Q);
    void (*print)(struct Queue *Q);
} queue;

void set_queue(queue *Q, size_t initial_size);
void push_element(queue *Q, int value);
void eject_element(queue *Q);
int first_element(queue *Q);
int last_element(queue *Q);
void free_queue(queue *Q);
void print_queue(queue *Q);

#endif // QUEUELIB_H
