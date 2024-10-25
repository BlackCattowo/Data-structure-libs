#ifndef CIRCULARLIB_H
#define CIRCULARLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // for NAN

// Node structure for circular linked list
typedef struct Node 
{
    float data;           /**< Value stored in the node */
    struct Node *next;    /**< Pointer to the next node */
} Node;

// Circular linked list structure
typedef struct CircularLinkedList 
{
    Node *head;           /**< Pointer to the first node */
    Node *tail;           /**< Pointer to the last node */
    int size;             /**< Number of nodes in the list */
} circular;

/**
 * Initializes a circular linked list.
 *
 * @param list Pointer to the circular linked list to initialize.
 */
void init_list(circular *list) 
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}


/**
 * Creates a new node with the specified data.
 *
 * @param data The float data to store in the node.
 * @return Pointer to the newly created node.
 */
Node* create_node(float data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/**
 * Inserts an element at the specified index in the list.
 *
 * @param list Pointer to the circular linked list.
 * @param index Index to insert the element at.
 * @param data Data to insert into the list.
 */
void insert_at(circular *list, int index, float data) 
{
    Node *new_node = create_node(data);

    if (index <= 0 || list->size == 0) 
    {
        if (list->size == 0) 
        {
            list->head = new_node;
            list->tail = new_node;
            new_node->next = new_node;
        } 
        else 
        {
            new_node->next = list->head;
            list->head = new_node;
            list->tail->next = new_node;
        }
    } 
    else 
    {
        Node *current = list->head;
        for (int i = 0; i < index - 1 && current->next != list->head; i++) 
        {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;

        if (current == list->tail) 
        {
            list->tail = new_node;
        }
    }

    list->size++;
}

/**
 * Removes an element at the specified index in the list.
 *
 * @param list Pointer to the circular linked list.
 * @param index Index of the element to remove.
 */
void remove_at(circular *list, int index) 
{
    if (list->size == 0 || index < 0 || index >= list->size) 
    {
        return;
    }

    Node *current = list->head;

    if (index == 0) 
    {
        if (list->size == 1) 
        {
            free(current);
            list->head = NULL;
            list->tail = NULL;
        } 
        else 
        {
            list->head = current->next;
            list->tail->next = list->head;
            free(current);
        }
    } 
    else 
    {
        Node *prev = NULL;
        for (int i = 0; i < index; i++) 
        {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;

        if (current == list->tail) 
        {
            list->tail = prev;
        }

        free(current);
    }

    list->size--;
}

/**
 * Finds the index of the first occurrence of the specified data in the list.
 *
 * @param list Pointer to the circular linked list.
 * @param data The data to search for.
 * @return Index of the node containing the data, or -1 if not found.
 */
int get_node(circular *list, float data) 
{
    int index = 0;
    Node *current = list->head;

    if (list->size == 0) 
    {
        return -1;
    }

    do 
    {
        if (current->data == data) 
        {
            return index;
        }
        current = current->next;
        index++;
    } while (current != list->head);

    return -1;
}

/**
 * Retrieves the data of a node at the specified index.
 *
 * @param list Pointer to the circular linked list.
 * @param index Index of the node to retrieve.
 * @return Data stored at the specified index, or NAN if index is invalid.
 */
float get_element_at(circular *list, int index) 
{
    if (index < 0 || index >= list->size || list->size == 0) 
    {
        return NAN; // Return NaN if index is out of bounds or list is empty
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) 
    {
        current = current->next;
    }
    
    return current->data;
}

/**
 * Frees all memory allocated for the list.
 *
 * @param list Pointer to the circular linked list.
 */
void free_list(circular *list) 
{
    if (list->size == 0) return;

    Node *current = list->head;
    Node *next_node;

    do 
    {
        next_node = current->next;
        free(current);
        current = next_node;
    } while (current != list->head);

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**
 * Prints all elements in the circular linked list.
 *
 * @param list Pointer to the circular linked list.
 */
void print_list(circular *list) 
{
    if (list->size == 0) return;

    Node *current = list->head;
    do 
    {
        printf("%.2f ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

/**
 * Returns the number of elements in the list.
 *
 * @param list Pointer to the circular linked list.
 * @return Number of elements in the list.
 */
int get_size(circular *list) 
{
    return list->size;
}

#endif // CIRCULARLIB_H
