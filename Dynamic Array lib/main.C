#include <stdio.h>
#include "arraylib.h"

int main() 
{
    // Inicializando um DynamicArray
    vetor vetor_ex;
    vetor_ex.size = 5;
    vetor_ex.count = 0;
    vetor_ex.element = (int *)malloc(vetor_ex.size * sizeof(int));
    vetor_ex.add = add_element;
    vetor_ex.remove = remove_element;
    vetor_ex.alter = alter_element;
    vetor_ex.free = free_array;

    // Usando as funções
    vetor_ex.add(&vetor_ex, 10);
    vetor_ex.add(&vetor_ex, 20);
    printf("Adicionado: 10 e 20\n");

    vetor_ex.alter(&vetor_ex, 0, 15); // Alterar o primeiro elemento para 15
    printf("Alterado o primeiro elemento para: %d\n", vetor_ex.element[0]);

    vetor_ex.remove(&vetor_ex, 1); // Remover o segundo elemento (20)
    printf("Removido o segundo elemento\n");

    // Imprimindo os elementos restantes
    printf("Elementos restantes: ");
    for (size_t i = 0; i < vetor_ex.count; i++) {
        printf("%d ", vetor_ex.element[i]);
    }
    printf("\n");

    // Liberar a memória
    vetor_ex.free(&vetor_ex);

    return 0;
}
