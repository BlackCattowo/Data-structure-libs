#include <stdio.h>
#include "Lists.h"

int main() 
{
    // Inicializando um DynamicArray
    list vetor;
    vetor.size = 5;
    vetor.count = 0;
    vetor.element = (int *)malloc(vetor.size * sizeof(int));
    vetor.add = add_element;
    vetor.remove = remove_element;
    vetor.alter = alter_element;
    vetor.free = free_array;

    // Usando as funções
    vetor.add(&vetor, 10);
    vetor.add(&vetor, 20);
    printf("Adicionado: 10 e 20\n");

    vetor.alter(&vetor, 0, 15); // Alterar o primeiro elemento para 15
    printf("Alterado o primeiro elemento para: %d\n", vetor.element[0]);

    vetor.remove(&vetor, 1); // Remover o segundo elemento (20)
    printf("Removido o segundo elemento\n");

    // Imprimindo os elementos restantes
    printf("Elementos restantes: ");
    for (size_t i = 0; i < vetor.count; i++) {
        printf("%d ", vetor.element[i]);
    }
    printf("\n");

    // Liberar a memória
    vetor.free(&vetor);

    return 0;
}
