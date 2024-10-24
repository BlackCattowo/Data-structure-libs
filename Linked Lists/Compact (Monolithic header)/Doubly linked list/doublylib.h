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

// Initialize the doubly linked list
void init_list(doubly *list) 
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Create a new node
Node* create_node(float data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Insert an element somewhere in the list
void insert_at(doubly *list, int Index, float data) 
{
    // Create a new node
    Node *new_node = create_node(data);

    // Case 1: Insert at the head (position 0)
    if (Index <= 0 || list->size == 0) 
    {
        new_node->next = list->head;
        if (list->head != NULL) 
        {
            list->head->prev = new_node;
        }
        list->head = new_node;

        // If the list was empty, the new node is also the tail
        if (list->tail == NULL) 
        {
            list->tail = new_node;
        }
    }
    // Case 2: Insert at the tail (position >= size)
    else if (Index >= list->size) 
    {
        new_node->prev = list->tail;
        if (list->tail != NULL) 
        {
            list->tail->next = new_node;
        }
        list->tail = new_node;
    }
    // Case 3: Insert somewhere in the middle
    else 
    {
        int TailIndex = list->size;

        if (Index > TailIndex / 2)
        {
            // If closer to tail, traverse backwards from tail
            Node *current = list->tail;
            for (int i = TailIndex - 1; i > Index && current != NULL; i--) 
            {
                current = current->prev;  // Traverse backwards
            }

            new_node->prev = current->prev;
            new_node->next = current;

            if (current->prev != NULL) 
            {
                current->prev->next = new_node;
            }
            current->prev = new_node;
        }
        else
        {
            // Otherwise, traverse forwards from head
            Node *current = list->head;
            for (int i = 0; i < Index && current != NULL; i++) 
            {
                current = current->next;  // Traverse forwards
            }

            new_node->next = current;
            new_node->prev = current->prev;

            if (current->prev != NULL) 
            {
                current->prev->next = new_node;
            }
            current->prev = new_node;
        }
    }

    // Increase the size of the list
    list->size++;
}

// Removes an element from the list
void remove_at(doubly *list, int index) 
{
    if (list->size == 0 || index < 0 || index >= list->size) 
    {
        return;  
    }

    Node *current = list->head;

    // Case 1: Remove head
    if (index == 0) 
    {
        list->head = current->next;
        if (list->head != NULL) 
        {
            list->head->prev = NULL;
        }
        else 
        {
            list->tail = NULL; // The list is now empty
        }
        free(current);
    }
    // Case 2: Remove tail
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
    // Case 3: Remove somewhere in the middle
    else 
    {
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

        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }

    // Adjust the size
    list->size--;
    
    // If list is empty, reset the tail
    if (list->size == 0) 
    {
        list->tail = NULL;
    }
}

// Find a node by the data storage on it
int get_node(doubly *list, float data) 
{
    int Index = 0;
    Node *current = list->head;
    
    while (current != NULL && current->data != data) 
    {
        current = current->next;
        Index++;
    }
    
    if (current == NULL) 
    {
        printf("Element not found.\n");
        return -1;  // Return -1 when not found
    }
    
    return Index;
}

// Free the allocated memmory
void free_list(doubly *list) 
{
    if (list->size == 0) return;  // No need to free if the list is empty

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

// Prints the list
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

// Return the size of the list
int get_size(doubly *list) 
{
    return list->size;
}


#endif