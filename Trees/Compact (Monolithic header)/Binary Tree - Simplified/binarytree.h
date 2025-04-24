#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

/** Node structure for a binary tree */
typedef struct node 
{
    int key;
    struct node *left;
    struct node *right;
} Node;

/**
 * Initializes an empty tree
 * @return NULL pointer representing an empty tree
 */
Node* initTree() 
{
    return NULL;
}

/**
 * Creates a new node with given key
 * @param key The key to store in the node
 * @return Pointer to the newly created node
 */
Node* createNode(int key) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/**
 * Inserts a node as the left child of a given parent
 * @param parent Pointer to the parent node
 * @param key Value of the new node
 * @return Pointer to the new node or NULL if insertion fails
 */
Node* insertLeft(Node* parent, int key) 
{
    if (!parent || parent->left) return NULL;
    parent->left = createNode(key);
    return parent->left;
}

/**
 * Inserts a node as the right child of a given parent
 * @param parent Pointer to the parent node
 * @param key Value of the new node
 * @return Pointer to the new node or NULL if insertion fails
 */
Node* insertRight(Node* parent, int key) 
{
    if (!parent || parent->right) return NULL;
    parent->right = createNode(key);
    return parent->right;
}

/**
 * Automatically inserts a node at the next valid position (BFS style)
 * @param root Pointer to the root node
 * @param key Value to insert
 * @return Updated root pointer
 */
Node* insertAuto(Node* root, int key) 
{
    Node* newNode = createNode(key);
    if (!root) return newNode;

    Node** queue = (Node**)malloc(1000 * sizeof(Node*));
    int front = 0, back = 0;
    queue[back++] = root;

    while (front < back) 
    {
        Node* curr = queue[front++];

        if (!curr->left) 
        {
            curr->left = newNode;
            break;
        } else if (!curr->right) 
        {
            curr->right = newNode;
            break;
        }

        queue[back++] = curr->left;
        queue[back++] = curr->right;
    }

    free(queue);
    return root;
}

/**
 * Prints the tree in pre-order traversal
 * @param root Pointer to the root node
 */
void printPreOrder(Node* root) 
{
    if (!root) return;
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

/**
 * Prints the tree in in-order traversal
 * @param root Pointer to the root node
 */
void printInOrder(Node* root) 
{
    if (!root) return;
    printInOrder(root->left);
    printf("%d ", root->key);
    printInOrder(root->right);
}

/**
 * Prints the tree in post-order traversal
 * @param root Pointer to the root node
 */
void printPostOrder(Node* root) 
{
    if (!root) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->key);
}

/**
 * Prints the tree in level-order traversal (BFS)
 * @param root Pointer to the root node
 */
void printLevelOrder(Node* root) 
{
    if (!root) return;
    Node** queue = (Node**)malloc(1000 * sizeof(Node*));
    int front = 0, back = 0;
    queue[back++] = root;

    while (front < back) 
    {
        Node* curr = queue[front++];
        printf("%d ", curr->key);
        if (curr->left) queue[back++] = curr->left;
        if (curr->right) queue[back++] = curr->right;
    }
    free(queue);
}

/**
 * Finds a node by key using DFS
 * @param root Root node to search from
 * @param key Key to find
 * @return Pointer to the found node or NULL if not found
 */
Node* find(Node* root, int key) 
{
    if (!root) return NULL;
    if (root->key == key) return root;

    Node* found = find(root->left, key);
    if (found) return found;
    return find(root->right, key);
}

/**
 * Recursively frees all nodes in the tree
 * @param root Pointer to the root node
 */
void freeTree(Node* root) 
{
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/**
 * Internal helper to update value by DFS index
 */
int _updateValueByIndexHelper(Node* root, int index, int newValue, int* currentIndex) 
{
    if (!root) return 0;

    if (*currentIndex == index) 
    {
        root->key = newValue;
        return 1;
    }

    (*currentIndex)++;
    if (_updateValueByIndexHelper(root->left, index, newValue, currentIndex)) return 1;
    if (_updateValueByIndexHelper(root->right, index, newValue, currentIndex)) return 1;

    return 0;
}

/**
 * Updates a node's key by its DFS index
 * @param root Pointer to the root
 * @param index DFS index of the node
 * @param newValue New key value
 * @return 1 if successful, 0 if not found
 */
int updateValueByIndex(Node* root, int index, int newValue) 
{
    int currentIndex = 0;
    return _updateValueByIndexHelper(root, index, newValue, &currentIndex);
}

#endif // BINARYTREE_H
