#include <stdio.h>
#include "searchtree.h"

int main() {
    searchtree tree;

    // Initialize tree
    initBinTree(&tree);
    printf("Árvore binária inicializada.\n\n");

    // Insert nodes
    insert(&tree, 3.14, 10, "Pi");
    insert(&tree, 2.71, 5, "Euler");
    insert(&tree, 1.41, 15, "RaizQuadrada");
    insert(&tree, 0.577, 2, "Gama");
    insert(&tree, 1.618, 7, "Ouro");

    printf("Elementos inseridos na árvore.\n\n");

    // Print the tree in-order
    printf("Impressão da árvore em ordem crescente de chaves:\n");
    printBinTree(&tree);
    printf("\n");

    // Search for a node
    int searchKey = 5;
    Node* found = search(tree.root, searchKey);
    if (found) {
        printf("Resultado da busca: Nó encontrado com chave %d -> Nome: %s, Valor: %.3f\n",
               found->key, found->name, found->data);
    } else {
        printf("Resultado da busca: Nó com chave %d não encontrado.\n", searchKey);
    }

    // Free the tree
    freeBinTree(&tree);
    printf("\nÁrvore binária liberada.\n");

    return 0;
}
