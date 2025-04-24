#include "searchtree.h"

void freeNodes(Node* node) 
{// Helper function to free nodes recursively
    if (node == NULL) return;
    freeNodes(node->left);
    freeNodes(node->right);
    free(node);
}


void printInOrder(Node* node) 
{// Function to print nodes in-order
    if (node == NULL) return;
    printInOrder(node->left);
    printf("Key: %d, Name: %s, Value: %.2f\n", node->key, node->name, node->data);
    printInOrder(node->right);
}


void initBinTree(searchtree* tree) 
{// Initializes a binary search tree
    tree->root = NULL;
}


Node* createNode(float data, int key, const char* name) 
{// Creates a new node with given data, key, and name
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->key = key;
        strncpy(newNode->name, name, sizeof(newNode->name) - 1);
        newNode->name[sizeof(newNode->name) - 1] = '\0'; // Ensure null-termination
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}


void insert(searchtree* tree, float data, int key, const char* name) 
{// Inserts a new node with the specified data, key, and name into the binary tree
    Node* newNode = createNode(data, key, name);
    if (!newNode) {
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
        } else {
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


Node* search(Node* root, int key) 
{// Searches for a node with the specified key in the binary tree
    if (root == NULL || root->key == key) 
    {
        return root;
    }
    if (key < root->key) 
    {
        return search(root->left, key);
    } 
    else 
    {
        return search(root->right, key);
    }
}


void freeBinTree(searchtree* tree) 
{// Recursively frees memory of all nodes in the binary tree
    freeNodes(tree->root);
    tree->root = NULL;
}


void printBinTree(const searchtree* tree) 
{// Prints the binary tree in ascending order of keys
    printInOrder(tree->root);
}
