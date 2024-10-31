#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for binary tree
typedef struct Node 
{
    float data;        // Float value associated with the node
    int key;         // Unique integer key for the node
    char name[50];     // Name associated with the node
    struct Node* left; // Pointer to the left child
    struct Node* right; // Pointer to the right child
} Node;

// Binary tree structure to manage the root node
typedef struct 
{// Root node of the binary tree
    Node* root;
} searchtree;


// Helper functions 
void freeNodes(Node* node) 
{//free nodes recursively
    if (node == NULL) return;
    freeNodes(node->left);
    freeNodes(node->right);
    free(node);
}
void printInOrder(Node* node) 
{//print nodes in-order
    if (node == NULL) return;
    printInOrder(node->left);
    printf("Key: %d, Name: %s, Value: %.2f\n", node->key, node->name, node->data);
    printInOrder(node->right);
}


/**
 * Initializes a binary search tree.
 *
 * @param tree Pointer to the binary tree to initialize.
 */
void initBinTree(searchtree* tree) 
{
    tree->root = NULL;
}

/**
 * Creates a new node with given data, key, and name.
 *
 * @param data Float value to store in the node.
 * @param key Integer key associated with the node.
 * @param name String with the name associated with the node.
 * @return Pointer to the newly created node.
 */
Node* createNode(float data, int key, const char* name) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) 
    {
        newNode->data = data;
        newNode->key = key;
        strncpy(newNode->name, name, sizeof(newNode->name) - 1);
        newNode->name[sizeof(newNode->name) - 1] = '\0'; // Ensure null-termination
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

/**
 * Inserts a new node with the specified data, key, and name into the binary tree.
 *
 * @param tree Pointer to the binary tree where the node will be inserted.
 * @param data Float value to store in the node.
 * @param key Integer key associated with the node.
 * @param name String with the name associated with the node.
 */
void insert(searchtree* tree, float data, int key, const char* name) 
{
    Node* newNode = createNode(data, key, name);
    if (!newNode) 
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }

    if (tree->root == NULL) 
    {
        tree->root = newNode;
        return;
    }

    Node* current = tree->root;
    Node* parent = NULL;

    while (current != NULL) 
    {
        parent = current;
        if (key < current->key) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }

    if (key < parent->key) 
    {
        parent->left = newNode;
    } 
    else 
    {
        parent->right = newNode;
    }
}

/**
 * Searches for a node with the specified key in the binary tree.
 *
 * @param root Pointer to the root node of the tree (or subtree) to search.
 * @param key Key to search for in the tree.
 * @return Pointer to the node if found, otherwise NULL.
 */
Node* search(Node* root, int key) 
{
    if (root == NULL || root->key == key) 
    {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    } 
    else 
    {
        return search(root->right, key);
    }
}

/**
 * Recursively frees memory of all nodes in the binary tree, releasing resources.
 *
 * @param tree Pointer to the binary tree whose nodes will be freed.
 */
void freeBinTree(searchtree* tree) 
{

    freeNodes(tree->root);
    tree->root = NULL;
}

/**
 * Prints the binary tree in ascending order of keys.
 *
 * @param tree Pointer to the binary tree to print.
 */
void printBinTree(const searchtree* tree) 
{
    printInOrder(tree->root);
}


#endif // SEARCHTREE_H
