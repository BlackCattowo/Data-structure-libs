#include <stdio.h>
#include "binarytree.h"

int main() {
    // Initialize the tree
    Node* root = initTree();

    // Insert nodes using auto-insertion
    root = insertAuto(root, 10); // root
    insertAuto(root, 20);
    insertAuto(root, 30);
    insertAuto(root, 40);
    insertAuto(root, 50);
    insertAuto(root, 60);

    printf("Tree after auto insertions (Level-order):\n");
    printLevelOrder(root);
    printf("\n");

    // Manually insert nodes
    Node* node = find(root, 20);
    if (node) 
    {
        insertLeft(node, 21);
        insertRight(node, 22);
    }
    node = find(root, 30);
    if (node) 
    {
        insertRight(node, 70);
    }
    node = find(root, 40);
    if (node) 
    {
        insertLeft(node, 23);
        insertRight(node, 24);
    }

    printf("Tree after manual left/right insertions (Level-order):\n");
    printLevelOrder(root);
    printf("\n");

    // Test Pre-order traversal
    printf("Pre-order traversal:\n");
    printPreOrder(root);
    printf("\n");

    // Test In-order traversal
    printf("In-order traversal:\n");
    printInOrder(root);
    printf("\n");

    // Test Post-order traversal
    printf("Post-order traversal:\n");
    printPostOrder(root);
    printf("\n");

    // Search for a specific value
    int searchKey = 30;
    Node* found = find(root, searchKey);
    if (found)
        printf("Found node with key %d\n", found->key);
    else
        printf("Node with key %d not found\n", searchKey);

    // Update value by DFS index
    int indexToUpdate = 3;
    int newValue = 999;
    if (updateValueByIndex(root, indexToUpdate, newValue))
        printf("Updated node at index %d to value %d\n", indexToUpdate, newValue);
    else
        printf("Failed to update node at index %d\n", indexToUpdate);

    // Print tree again after update
    printf("Tree after update (Level-order):\n");
    printLevelOrder(root);
    printf("\n");

    // Clean up
    freeTree(root);
    return 0;
}
