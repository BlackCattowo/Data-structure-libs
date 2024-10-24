#ifndef DYNAMICLIB_H
#define DYNAMICLIB_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Struct representing a dynamic array.
 * - `element`: Pointer to the array of integers.
 * - `size`: Current allocated size of the array.
 * - `count`: Current number of elements in the array.
 * - Function pointers for operations: add, remove, alter, free, print, find, get.
 */
typedef struct Dynamic_Array
{
    int *element;
    size_t size;
    size_t count;
    void (*add)(struct Dynamic_Array *vetor, int value);
    void (*remove)(struct Dynamic_Array *vetor, size_t index);
    void (*alter)(struct Dynamic_Array *vetor, size_t index, int value);
    void (*free)(struct Dynamic_Array *vetor);
    void (*print)(struct Dynamic_Array *vetor);
    int (*find)(struct Dynamic_Array *vetor, int value);
    int (*get)(struct Dynamic_Array *vetor, size_t index);
} array;

// Function declarations
void add_element(array *vetor, int value);
void remove_element(array *vetor, size_t index);
void alter_element(array *vetor, size_t index, int value);
void free_array(array *vetor);
void set_array(array *vetor, size_t initial_size);
void print_array(array *vetor);
int find_index(array *vetor, int value);
int get_element(array *vetor, size_t index);

#endif // DYNAMICLIB_H
