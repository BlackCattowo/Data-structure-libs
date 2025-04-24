#include "binarytree.h"

Node* initTree() 
{
    return NULL;
}

Node* createNode(int key) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertLeft(Node* parent, int key) 
{
    if (!parent || parent->left) return NULL;
    parent->left = createNode(key);
    return parent->left;
}

Node* insertRight(Node* parent, int key) 
{
    if (!parent || parent->right) return NULL;
    parent->right = createNode(key);
    return parent->right;
}

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

void printPreOrder(Node* root) 
{
    if (!root) return;
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node* root) 
{
    if (!root) return;
    printInOrder(root->left);
    printf("%d ", root->key);
    printInOrder(root->right);
}

void printPostOrder(Node* root) 
{
    if (!root) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->key);
}

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

Node* find(Node* root, int key) 
{
    if (!root) return NULL;
    if (root->key == key) return root;

    Node* found = find(root->left, key);
    if (found) return found;
    return find(root->right, key);
}

void freeTree(Node* root) 
{
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

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

int updateValueByIndex(Node* root, int index, int newValue) 
{
    int currentIndex = 0;
    return _updateValueByIndexHelper(root, index, newValue, &currentIndex);
}
