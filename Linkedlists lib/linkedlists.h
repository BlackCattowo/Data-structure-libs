#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

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
} linkedlist;

// Initialize the doubly linked list
void init_list(linkedlist *list) 
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

// Insert an element somewere in the list
void insert_at(linkedlist *list, int Index, float data) 
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
        Node *current = list->head;
        for (int i = 0; i < Index - 1 && current != NULL; i++) 
        {
            current = current->next;
        }
        
        new_node->next = current->next;
        new_node->prev = current;
        
        if (current->next != NULL) 
        {
            current->next->prev = new_node;
        }
        current->next = new_node;
    }

    // Increase the size of the list
    list->size++;
}

// remove an element somewere in the list
void remove_at(linkedlist *list, int position) 
{
    // Check if the list is empty or the position is invalid
    if (list->size == 0 || position < 0 || position >= list->size) 
    {
        return;  // Do nothing
    }
    
    Node *current = list->head;

    // Case 1: Removing the head (position 0)
    if (position == 0) 
    {
        list->head = current->next;  // Move head to the next node
        if (list->head != NULL) 
        {
            list->head->prev = NULL;
        }
        else 
        {
            // If the list becomes empty, also set the tail to NULL
            list->tail = NULL;
        }
        free(current);
    }
    // Case 2: Removing the tail (last position)
    else if (position == list->size - 1) 
    {
        current = list->tail;  // Get the tail node
        list->tail = current->prev;  // Move tail to the previous node
        if (list->tail != NULL) 
        {
            list->tail->next = NULL;
        }
        free(current);
    }
    // Case 3: Removing a node in the middle
    else 
    {
        // Traverse to the node at position X
        for (int i = 0; i < position; i++) 
        {
            current = current->next;
        }

        // Adjust the pointers to bypass the current node
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }

    // Decrease the size of the list
    list->size--;
}

// Get the position of a node from the list (by value)
int get_node(linkedlist *list, float data) 
{
    int Index = 0;
    Node *current = list->head;
    
    // Search for the nod
    while (current != NULL && current->data != data) 
    {
        current = current->next;
        (Index++);
    }
    
    if (current == NULL) 
    {
        printf("Element not found.\n");
        return(0);
    }
    
    else
    {
        return(Index);
    }
}

// Free the entire list
void free_list(linkedlist *list) 
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

// Print the list (for testing purposes)
void print_list(linkedlist *list) 
{
    Node *current = list->head;
    
    while (current != NULL) 
    {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to check the size of the list
int get_size(linkedlist *list) 
{
    return list->size;
}

#endif // SET_LINKEDLISTS_H
