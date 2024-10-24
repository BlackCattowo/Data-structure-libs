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
void init_list(doubly *list) 
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**
 * @brief Creates a new node with the given data.
 * 
 * @param data Data to store in the new node.
 * @return Node* Pointer to the newly created node.
 */
Node* create_node(float data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

/**
 * @brief Inserts an element at a specified index in the list.
 * 
 * @param list Pointer to the doubly linked list.
 * @param index Position where the new element should be inserted.
 * @param data Data to store in the new element.
 */
void insert_at(doubly *list, int index, float data) 
{
    Node *new_node = create_node(data);

    if (index <= 0 || list->size == 0) 
    {
        new_node->next = list->head;
        if (list->head != NULL) 
        {
            list->head->prev = new_node;
        }
        list->head = new_node;
        if (list->tail == NULL) 
        {
            list->tail = new_node;
        }
    }
    else if (index >= list->size) 
    {
        new_node->prev = list->tail;
        if (list->tail != NULL) 
        {
            list->tail->next = new_node;
        }
        list->tail = new_node;
    }
    else 
    {
        Node *current = list->head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }

        new_node->next = current;
        new_node->prev = current->prev;
        if (current->prev != NULL) 
        {
            current->prev->next = new_node;
        }
        current->prev = new_node;
    }

    list->size++;
}

/**
 * @brief Removes an element at a given index from the list.
 * 
 * @param list Pointer to the doubly linked list.
 * @param index Position of the element to remove.
 */
void remove_at(doubly *list, int index) 
{
    if (list->size == 0 || index < 0 || index >= list->size) 
    {
        return;
    }

    Node *current = list->head;

    if (index == 0) 
    {
        list->head = current->next;
        if (list->head != NULL) 
        {
            list->head->prev = NULL;
        }
        else 
        {
            list->tail = NULL;
        }
        free(current);
    }
    else if (index == list->size - 1) 
    {
        current = list->tail;
        list->tail = current->prev;
        if (list->tail != NULL) 
        {
            list->tail->next = NULL;
        }
        free(current);
    }
    else 
    {
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }

    list->size--;
    if (list->size == 0) 
    {
        list->tail = NULL;
    }
}

/**
 * @brief Finds the index of a node containing the specified data.
 * 
 * @param list Pointer to the doubly linked list.
 * @param data Data to search for.
 * @return int Index of the found node, or -1 if not found.
 */
int get_node(doubly *list, float data) 
{
    int index = 0;
    Node *current = list->head;

    while (current != NULL && current->data != data) 
    {
        current = current->next;
        index++;
    }

    if (current == NULL) 
    {
        return -1;
    }

    return index;
}

/**
 * @brief Retrieves the element at a specific index in the list.
 * 
 * @param list Pointer to the doubly linked list.
 * @param index Position of the element to retrieve.
 * @return float Data stored at the specified index, or -1 if index is out of bounds.
 */
float get_element_at(doubly *list, int index) 
{
    if (index < 0 || index >= list->size) 
    {
        printf("Index out of bounds.\n");
        return -1;
    }

    Node *current;
    if (index > list->size / 2) 
    {
        current = list->tail;
        for (int i = list->size - 1; i > index; i--) 
        {
            current = current->prev;
        }
    } 
    else 
    {
        current = list->head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }
    }

    return current->data;
}

/**
 * @brief Frees the allocated memory for the list and its elements.
 * 
 * @param list Pointer to the doubly linked list.
 */
void free_list(doubly *list) 
{
    Node *current = list->head;
    Node *next_node;

    while (current != NULL) 
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**
 * @brief Prints the elements of the list.
 * 
 * @param list Pointer to the doubly linked list.
 */
void print_list(doubly *list) 
{
    Node *current = list->head;
    while (current != NULL) 
    {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

/**
 * @brief Returns the size of the list.
 * 
 * @param list Pointer to the doubly linked list.
 * @return int Size of the list.
 */
int get_size(doubly *list) 
{
    return list->size;
}


#endif
