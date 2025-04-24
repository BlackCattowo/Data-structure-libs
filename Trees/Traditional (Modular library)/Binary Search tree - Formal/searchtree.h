#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Node structure for binary tree.
 *
 * This structure represents a node in a binary search tree, containing a float value,
 * a unique integer key, a name, and pointers to the left and right child nodes.
 */
typedef struct Node {
    float data;        ///< Float value associated with the node
    int key;           ///< Unique integer key for the node
    char name[50];     ///< Name associated with the node
    struct Node* left; ///< Pointer to the left child
    struct Node* right; ///< Pointer to the right child
} Node;

/**
 * @brief Binary tree structure to manage the root node.
 *
 * This structure represents the binary search tree itself, with a pointer to the root node.
 */
typedef struct {
    Node* root; ///< Root node of the binary tree
} searchtree;

/**
 * @brief Initializes a binary search tree.
 *
 * This function initializes a binary search tree by setting the root to NULL.
 *
 * @param tree Pointer to the binary tree to initialize.
 */
void initBinTree(searchtree* tree);

/**
 * @brief Creates a new node with given data, key, and name.
 *
 * This function allocates memory for a new node, sets the node's data, key, and name,
 * and initializes the left and right pointers to NULL.
 *
 * @param data Float value to store in the node.
 * @param key Integer key associated with the node.
 * @param name String with the name associated with the node.
 * @return Pointer to the newly created node, or NULL if memory allocation fails.
 */
Node* createNode(float data, int key, const char* name);

/**
 * @brief Inserts a new node with the specified data, key, and name into the binary tree.
 *
 * This function inserts a new node into the binary search tree while maintaining the
 * binary search property (left child < parent < right child).
 *
 * @param tree Pointer to the binary tree where the node will be inserted.
 * @param data Float value to store in the node.
 * @param key Integer key associated with the node.
 * @param name String with the name associated with the node.
 */
void insert(searchtree* tree, float data, int key, const char* name);

/**
 * @brief Searches for a node with the specified key in the binary tree.
 *
 * This function searches for a node in the binary search tree by key. It returns
 * a pointer to the node if found, or NULL if the node is not found.
 *
 * @param root Pointer to the root node of the tree (or subtree) to search.
 * @param key Key to search for in the tree.
 * @return Pointer to the node if found, otherwise NULL.
 */
Node* search(Node* root, int key);

/**
 * @brief Recursively frees memory of all nodes in the binary tree.
 *
 * This function recursively frees the memory of all nodes in the binary tree, ensuring
 * no memory is leaked when the tree is no longer needed.
 *
 * @param tree Pointer to the binary tree whose nodes will be freed.
 */
void freeBinTree(searchtree* tree);

/**
 * @brief Prints the binary tree in ascending order of keys.
 *
 * This function prints the binary tree's nodes in ascending order of their keys
 * by performing an in-order traversal.
 *
 * @param tree Pointer to the binary tree to print.
 */
void printBinTree(const searchtree* tree);

#endif // SEARCHTREE_H
