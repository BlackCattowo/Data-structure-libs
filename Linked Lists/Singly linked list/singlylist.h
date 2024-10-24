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

// Initialize the singly linked list
void init_list(singly *list) 
{
    list->head = NULL;
    list->size = 0;
}

// Create a new node
Node* create_node(float data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert an element at a given index
void insert_at(singly *list, int index, float data) 
{
    Node *new_node = create_node(data);

    // Case 1: Insert at the head (position 0)
    if (index <= 0 || list->size == 0) 
    {
        new_node->next = list->head;
        list->head = new_node;
    }
    // Case 2: Insert somewhere else
    else 
    {
        Node *current = list->head;
        for (int i = 0; i < index - 1 && current->next != NULL; i++) 
        {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    // Increase the size of the list
    list->size++;
}

// Removes an element at a given index
void remove_at(singly *list, int index) 
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
        free(current);
    }
    // Case 2: Remove from somewhere else
    else 
    {
        Node *prev = NULL;
        for (int i = 0; i < index; i++) 
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
    }

    // Adjust the size
    list->size--;
}

// Find a node by the data stored in it
int get_node(singly *list, float data) 
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
        printf("Element not found.\n");
        return -1;  // Return -1 when not found
    }
    
    return index;
}

// Free the allocated memory
void free_list(singly *list) 
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
    list->size = 0;
}

// Print the list
void print_list(singly *list) 
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
int get_size(singly *list) 
{
    return list->size;
}

#endif
