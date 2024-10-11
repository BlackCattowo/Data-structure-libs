#ifndef ARRAYLIB_H
#define ARRAYLIB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Dynamic_Array
{
    int *element;      // Ponteiro para o array de inteiros
    size_t size;    // Tamanho do array
    size_t count;   // Número de element atualmente no array
    void (*add)(struct Dynamic_Array (*array), int value);    // Função para adicionar elemento
    void (*remove)(struct Dynamic_Array (*array), size_t index); // Função para remover elemento
    void (*alter)(struct Dynamic_Array (*array), size_t index, int value); // Função para alterar elemento
    void (*free)(struct Dynamic_Array (*array)); // Função para liberar memória
} vetor;

// Funções para manipulação do list
void add_element(list (*array), int value) 
{
    if (array->count < array->size) 
    {
        array->element[array->count++] = value;
    } else 
    {
        // Lógica para aumentar o tamanho do array, se necessário
        size_t new_size = array->size * 2;
        array->element = (int *)realloc(array->element, new_size * sizeof(int));
        if (array->element) 
        {
            array->size = new_size;
            array->element[array->count++] = value;
        } else 
        {
            fprintf(stderr, "Erro ao realocar memória.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void remove_element(list (*array), size_t index) 
{
    if (index < array->count) {
        for (size_t i = index; i < array->count - 1; i++) 
        {
            array->element[i] = array->element[i + 1];
        }
        array->count--;
    }
}

void alter_element(list (*array), size_t index, int value) 
{
    if (index < array->count) 
    {
        array->element[index] = value;
    }
}

void free_array(list (*array)) 
{
    free(array->element);
    array->element = NULL; // Para evitar ponteiros soltos
    array->count = 0;
    array->size = 0;
}

#endif // SET_ARRAY_H
