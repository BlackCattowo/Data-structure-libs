#ifndef OUROBOROSLIB_H
#define OUROBOROSLIB_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Node structure for doubly circular linked list.
 */
typedef struct Node 
{
    float data;           /**< Data stored in the node */
    struct Node *prev;    /**< Pointer to the previous node */
    struct Node *next;    /**< Pointer to the next node */
} Node;

/**
 * Doubly circular linked list structure.
 */
typedef struct DoublyCircularLinkedList 
{
    Node *head;           /**< Pointer to the first node */
    Node *tail;           /**< Pointer to the last node */
    int size;             /**< Number of nodes in the list */
} ouroboros;

/**
 * Initializes a doubly circular linked list.
 *
 * @param list Pointer to the doubly circular linked list to initialize.
 */
void init_list(ouroboros *list);

/**
 * Creates a new node with the specified data.
 *
 * @param data The float data to store in the node.
 * @return Pointer to the newly created node.
 */
Node* create_node(float data);

/**
 * Inserts an element at the specified index in the list.
 *
 * @param list Pointer to the doubly circular linked list.
 * @param index Index to insert the element at.
 * @param data Data to insert into the list.
 */
void insert_at(ouroboros *list, int index, float data);

/**
 * Removes an element at the specified index in the list.
 *
 * @param list Pointer to the doubly circular linked list.
 * @param index Index of the element to remove.
 */
void remove_at(ouroboros *list, int index);

/**
 * Finds the index of the first occurrence of the specified data in the list.
 *
 * @param list Pointer to the doubly circular linked list.
 * @param data The data to search for.
 * @return Index of the node containing the data, or -1 if not found.
 */
int get_node(ouroboros *list, float data);

/**
 * Retrieves the data of a node at the specified index.
 *
 * @param list Pointer to the doubly circular linked list.
 * @param index Index of the node to retrieve.
 * @return Data stored at the specified index, or NAN if index is invalid.
 */
float get_element_at(ouroboros *list, int index);

/**
 * Frees all memory allocated for the list.
 *
 * @param list Pointer to the doubly circular linked list.
 */
void free_list(ouroboros *list);

/**
 * Prints all elements in the doubly circular linked list.
 *
 * @param list Pointer to the doubly circular linked list.
 */
void print_list(ouroboros *list);

/**
 * Returns the number of elements in the list.
 *
 * @param list Pointer to the doubly circular linked list.
 * @return Number of elements in the list.
 */
int get_size(ouroboros *list);

#endif // OUROBOROSLIB_H
