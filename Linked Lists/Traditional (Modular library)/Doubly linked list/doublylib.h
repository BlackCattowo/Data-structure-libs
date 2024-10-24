#ifndef DOUBLYLIB_H
#define DOUBLYLIB_H

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node 
{
    float data;
    struct Node *prev;
    struct Node *next;
} Node;

// Doubly linked list structure
typedef struct DoublyLinkedList 
{
    Node *head;
    Node *tail;
    int size;
} doubly;

/**
 * @brief Initializes the doubly linked list.
 * 
 * @param list Pointer to the doubly linked list to be initialized.
 */
void init_list(doubly *list);

/**
 * @brief Inserts an element at a specified index in the list.
 * 
 * @param list Pointer to the doubly linked list.
 * @param index Position where the new element should be inserted.
 * @param data Data to store in the new element.
 */
void insert_at(doubly *list, int index, float data);

/**
 * @brief Removes an element at a given index from the list.
 * 
 * @param list Pointer to the doubly linked list.
 * @param index Position of the element to remove.
 */
void remove_at(doubly *list, int index);

/**
 * @brief Finds the index of a node containing the specified data.
 * 
 * @param list Pointer to the doubly linked list.
 * @param data Data to search for.
 * @return int Index of the found node, or -1 if not found.
 */
int get_node(doubly *list, float data);

/**
 * @brief Retrieves the element at a specific index in the list.
 * 
 * @param list Pointer to the doubly linked list.
 * @param index Position of the element to retrieve.
 * @return float Data stored at the specified index, or -1 if index is out of bounds.
 */
float get_element_at(doubly *list, int index);

/**
 * @brief Frees the allocated memory for the list and its elements.
 * 
 * @param list Pointer to the doubly linked list.
 */
void free_list(doubly *list);

/**
 * @brief Prints the elements of the list.
 * 
 * @param list Pointer to the doubly linked list.
 */
void print_list(doubly *list);

/**
 * @brief Returns the size of the list.
 * 
 * @param list Pointer to the doubly linked list.
 * @return int Size of the list.
 */
int get_size(doubly *list);

#endif
