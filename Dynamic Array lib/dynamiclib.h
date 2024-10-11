#ifndef DYNAMICLIB_H
#define DYNAMICLIB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Dynamic_Array
{
    int *element;      // Ponteiro para o array de inteiros
    size_t size;    // Tamanho do array
    size_t count;   // Número de element atualmente no array
    void (*add)(struct Dynamic_Array (*vetor), int value);    // Função para adicionar elemento
    void (*remove)(struct Dynamic_Array (*vetor), size_t index); // Função para remover elemento
    void (*alter)(struct Dynamic_Array (*vetor), size_t index, int value); // Função para alterar elemento
    void (*free)(struct Dynamic_Array (*vetor)); // Função para liberar memória
} array;

// Funções para manipulação do list
void add_element(array (*vetor), int value) 
{
    if (vetor->count < vetor->size) 
    {
        vetor->element[vetor->count++] = value;
    } else 
    {
        // Lógica para aumentar o tamanho do array, se necessário
        size_t new_size = vetor->size * 2;
        vetor->element = (int *)realloc(vetor->element, new_size * sizeof(int));
        if (vetor->element) 
        {
            vetor->size = new_size;
            vetor->element[vetor->count++] = value;
        } else 
        {
            fprintf(stderr, "Erro ao realocar memória.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void remove_element(array (*vetor), size_t index) 
{
    if (index < vetor->count) {
        for (size_t i = index; i < vetor->count - 1; i++) 
        {
            vetor->element[i] = vetor->element[i + 1];
        }
        vetor->count--;
    }
}

void alter_element(array (*vetor), size_t index, int value) 
{
    if (index < vetor->count) 
    {
        vetor->element[index] = value;
    }
}

void free_array(array (*vetor)) 
{
    free(vetor->element);
    vetor->element = NULL; // Para evitar ponteiros soltos
    vetor->count = 0;
    vetor->size = 0;
}

#endif // DYNAMICLIB_H
