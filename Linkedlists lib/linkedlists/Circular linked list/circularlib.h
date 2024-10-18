#ifndef CIRCULARLIB_H
#define CIRCULARLIB_H

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node 
{
    float data;
    struct Node *next;
} Node;

// Circular linked list structure
typedef struct CircularLinkedList 
{
    Node *head;
    Node *tail;
    int size;
} circular;

// Initialize the circular linked list
void init_list(circular *list) 
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
    new_node->next = NULL;
    return new_node;
}

// Insert an element at a given index
void insert_at(circular *list, int index, float data) 
{
    Node *new_node = create_node(data);

    // Case 1: Insert at the head (position 0)
    if (index <= 0 || list->size == 0) 
    {
        if (list->size == 0) 
        {
            list->head = new_node;
            list->tail = new_node;
            new_node->next = new_node; // Link to itself
        } 
        else 
        {
            new_node->next = list->head;
            list->head = new_node;
            list->tail->next = new_node;
        }
    }
    // Case 2: Insert somewhere else
    else 
    {
        Node *current = list->head;
        for (int i = 0; i < index - 1 && current->next != list->head; i++) 
        {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;

        // Update the tail if the new node is inserted at the end
        if (current == list->tail) 
        {
            list->tail = new_node;
        }
    }

    // Increase the size of the list
    list->size++;
}

// Removes an element at a given index
void remove_at(circular *list, int index) 
{
    if (list->size == 0 || index < 0 || index >= list->size) 
    {
        return;
    }

    Node *current = list->head;

    // Case 1: Remove head
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

        // Update the tail if the last element is removed
        if (current == list->tail) 
        {
            list->tail = prev;
        }

        free(current);
    }

    // Adjust the size
    list->size--;
}

// Find a node by the data stored in it
int get_node(circular *list, float data) 
{
    int index = 0;
    Node *current = list->head;
    
    if (list->size == 0) 
    {
        printf("Element not found.\n");
        return -1;  // Return -1 when not found
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
    
    printf("Element not found.\n");
    return -1;
}

// Free the allocated memory
void free_list(circular *list) 
{
    if (list->size == 0) return;  // No need to free if the list is empty

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

// Print the list
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

// Return the size of the list
int get_size(circular *list) 
{
    return list->size;
}

#endif
