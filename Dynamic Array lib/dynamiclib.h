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
    int (*get)(struct Dynamic_Array *vetor, size_t index); // New function pointer for get element by index
} array;

// Function declarations
void add_element(array *vetor, int value);
void remove_element(array *vetor, size_t index);
void alter_element(array *vetor, size_t index, int value);
void free_array(array *vetor);
void set_array(array *vetor, size_t initial_size);
void print_array(array *vetor);
int find_index(array *vetor, int value);
int get_element(array *vetor, size_t index); // Declaration for get function

/**
 * Adds a new element to the dynamic array.
 * If the array is full, it will reallocate memory and double the size of the array.
 *
 * @param vetor Pointer to the dynamic array.
 * @param value Integer value to be added to the array.
 */
void add_element(array *vetor, int value)
{
    if (vetor->count < vetor->size)
    {
        vetor->element[vetor->count++] = value;
    }
    else
    {
        size_t new_size = vetor->size * 2;
        vetor->element = (int *)realloc(vetor->element, new_size * sizeof(int));
        if (vetor->element)
        {
            vetor->size = new_size;
            vetor->element[vetor->count++] = value;
        }
        else
        {
            fprintf(stderr, "Erro ao realocar memória.\n");
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * Removes an element at a specific index from the dynamic array.
 * All elements after the removed element are shifted left.
 *
 * @param vetor Pointer to the dynamic array.
 * @param index Index of the element to remove.
 */
void remove_element(array *vetor, size_t index)
{
    if (index < vetor->count)
    {
        for (size_t i = index; i < vetor->count - 1; i++)
        {
            vetor->element[i] = vetor->element[i + 1];
        }
        vetor->count--;
    }
}

/**
 * Alters the value of an existing element at a specific index in the array.
 *
 * @param vetor Pointer to the dynamic array.
 * @param index Index of the element to be altered.
 * @param value New value to set at the specified index.
 */
void alter_element(array *vetor, size_t index, int value)
{
    if (index < vetor->count)
    {
        vetor->element[index] = value;
    }
}

/**
 * Frees the memory allocated for the dynamic array.
 * This function releases the memory used by the array and resets the count and size to zero.
 *
 * @param vetor Pointer to the dynamic array.
 */
void free_array(array *vetor)
{
    free(vetor->element);
    vetor->element = NULL;
    vetor->count = 0;
    vetor->size = 0;
}

/**
 * Prints the elements of the dynamic array to the console.
 * If the array is empty, it prints a message indicating that.
 *
 * @param vetor Pointer to the dynamic array.
 */
void print_array(array *vetor)
{
    if (vetor->count == 0)
    {
        printf("Array is empty.\n");
    }
    else
    {
        printf("Array elements: ");
        for (size_t i = 0; i < vetor->count; i++)
        {
            printf("%d ", vetor->element[i]);
        }
        printf("\n");
    }
}

/**
 * Finds the index of the first occurrence of a specified value in the dynamic array.
 *
 * @param vetor Pointer to the dynamic array.
 * @param value The integer value to search for.
 * @return Index of the first occurrence of the value, or -1 if the value is not found.
 */
int find_index(array *vetor, int value)
{
    for (size_t i = 0; i < vetor->count; i++)
    {
        if (vetor->element[i] == value)
        {
            return i;
        }
    }
    return -1;
}

/**
 * Retrieves the element at a specific index in the dynamic array.
 * If the index is out of bounds, it returns -1 and prints an error message.
 *
 * @param vetor Pointer to the dynamic array.
 * @param index Index of the element to retrieve.
 * @return Value at the specified index, or -1 if the index is invalid.
 */
int get_element(array *vetor, size_t index) // New get function
{
    if (index < vetor->count)
    {
        return vetor->element[index]; // Return the element at the given index
    }
    else
    {
        fprintf(stderr, "Index out of bounds.\n");
        return -1; // Return error code if index is invalid
    }
}

/**
 * Initializes the dynamic array with a specified initial size.
 * Allocates memory for the array and sets the size and count.
 * Also assigns function pointers for operations like add, remove, alter, etc.
 *
 * @param vetor Pointer to the dynamic array to initialize.
 * @param initial_size Initial size of the dynamic array.
 */
void set_array(array *vetor, size_t initial_size)
{
    vetor->size = initial_size;
    vetor->count = 0;
    vetor->element = (int *)malloc(vetor->size * sizeof(int));
    if (vetor->element == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    vetor->add = add_element;
    vetor->remove = remove_element;
    vetor->alter = alter_element;
    vetor->free = free_array;
    vetor->print = print_array;
    vetor->find = find_index;
    vetor->get = get_element; // Assign the get function
}

#endif // DYNAMICLIB_H
