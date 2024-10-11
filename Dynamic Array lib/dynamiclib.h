#ifndef DYNAMICLIB_H
#define DYNAMICLIB_H

#include <stdio.h>
#include <stdlib.h>

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
void init_array(array *vetor, size_t initial_size);
void print_array(array *vetor);
int find_index(array *vetor, int value);
int get_element(array *vetor, size_t index); // Declaration for get function

// Function definitions
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

void alter_element(array *vetor, size_t index, int value)
{
    if (index < vetor->count)
    {
        vetor->element[index] = value;
    }
}

void free_array(array *vetor)
{
    free(vetor->element);
    vetor->element = NULL;
    vetor->count = 0;
    vetor->size = 0;
}

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

void init_array(array *vetor, size_t initial_size)
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
