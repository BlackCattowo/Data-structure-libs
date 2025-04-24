#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

/** 
 * @brief Node structure for a binary tree.
 * 
 * This structure represents a node in the binary tree. Each node stores 
 * an integer key and has pointers to its left and right children.
 */
typedef struct node 
{
    int key; /**< The key stored in the node. */
    struct node *left; /**< Pointer to the left child. */
    struct node *right; /**< Pointer to the right child. */
} Node;

/**
 * @brief Initializes an empty tree.
 * 
 * @return NULL pointer representing an empty tree.
 */
Node* initTree(); 

/**
 * @brief Creates a new node with the given key.
 * 
 * @param key The key to store in the node.
 * 
 * @return Pointer to the newly created node.
 */
Node* createNode(int key); 

/**
 * @brief Inserts a node as the left child of a given parent.
 * 
 * @param parent Pointer to the parent node.
 * @param key The key to store in the new left child node.
 * 
 * @return Pointer to the new left child node, or NULL if insertion fails.
 */
Node* insertLeft(Node* parent, int key); 

/**
 * @brief Inserts a node as the right child of a given parent.
 * 
 * @param parent Pointer to the parent node.
 * @param key The key to store in the new right child node.
 * 
 * @return Pointer to the new right child node, or NULL if insertion fails.
 */
Node* insertRight(Node* parent, int key); 

/**
 * @brief Automatically inserts a node at the next valid position (BFS style).
 * 
 * @param root Pointer to the root node.
 * @param key The key to store in the new node.
 * 
 * @return The updated root pointer after insertion.
 */
Node* insertAuto(Node* root, int key); 

/**
 * @brief Prints the tree in pre-order traversal.
 * 
 * @param root Pointer to the root node.
 */
void printPreOrder(Node* root); 

/**
 * @brief Prints the tree in in-order traversal.
 * 
 * @param root Pointer to the root node.
 */
void printInOrder(Node* root); 

/**
 * @brief Prints the tree in post-order traversal.
 * 
 * @param root Pointer to the root node.
 */
void printPostOrder(Node* root); 

/**
 * @brief Prints the tree in level-order traversal (BFS).
 * 
 * @param root Pointer to the root node.
 */
void printLevelOrder(Node* root); 

/**
 * @brief Finds a node by key using DFS.
 * 
 * @param root Pointer to the root node.
 * @param key The key of the node to find.
 * 
 * @return Pointer to the found node, or NULL if not found.
 */
Node* find(Node* root, int key); 

/**
 * @brief Recursively frees all nodes in the tree.
 * 
 * @param root Pointer to the root node.
 */
void freeTree(Node* root); 

/**
 * @brief Updates a node's key by its DFS index.
 * 
 * @param root Pointer to the root node.
 * @param index The DFS index of the node to update.
 * @param newValue The new key value.
 * 
 * @return 1 if the update is successful, 0 if the node is not found.
 */
int updateValueByIndex(Node* root, int index, int newValue); 

#endif // BINARYTREE_H
