#ifndef SINGLYLIB_H
#define SINGLYLIB_H

#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct Node 
{
    float data;
    struct Node *next;
} Node;

// Singly linked list structure
typedef struct SinglyLinkedList 
{
    Node *head;
    int size;
} singly;

/**
 * @brief Initializes the singly linked list.
 * 
 * @param list Pointer to the singly linked list to be initialized.
 */
void init_list(singly *list);

/**
 * @brief Creates a new node with the given data.
 * 
 * @param data Data to store in the new node.
 * @return Node* Pointer to the newly created node.
 */
Node* create_node(float data);

/**
 * @brief Inserts an element at a given index in the list.
 * 
 * @param list Pointer to the singly linked list.
 * @param index Position where the new element should be inserted.
 * @param data Data to store in the new element.
 */
void insert_at(singly *list, int index, float data);

/**
 * @brief Removes an element at a given index from the list.
 * 
 * @param list Pointer to the singly linked list.
 * @param index Position of the element to remove.
 */
void remove_at(singly *list, int index);

/**
 * @brief Finds the index of a node containing the specified data.
 * 
 * @param list Pointer to the singly linked list.
 * @param data Data to search for.
 * @return int Index of the found node, or -1 if not found.
 */
int get_node(singly *list, float data);

/**
 * @brief Retrieves the element at a specific index in the list.
 * 
 * @param list Pointer to the singly linked list.
 * @param index Position of the element to retrieve.
 * @return float Data stored at the specified index, or -1 if index is out of bounds.
 */
float get_element_at(singly *list, int index);

/**
 * @brief Frees the allocated memory for the list and its elements.
 * 
 * @param list Pointer to the singly linked list.
 */
void free_list(singly *list);

/**
 * @brief Prints the elements of the list.
 * 
 * @param list Pointer to the singly linked list.
 */
void print_list(singly *list);

/**
 * @brief Returns the size of the list.
 * 
 * @param list Pointer to the singly linked list.
 * @return int Size of the list.
 */
int get_size(singly *list);

#endif
