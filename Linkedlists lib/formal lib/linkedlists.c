#include "linkedlists.h"

// Create a new node
Node* create_node(float data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Initialize the doubly linked list
void init_list(linkedlist *list) 
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
// Return the size of the list
int get_size(linkedlist *list) 
{
    return list->size;
}


// Insert an element somewhere in the list
void insert_at(linkedlist *list, int Index, float data) 
{
    Node *new_node = create_node(data);

    if (Index <= 0 || list->size == 0) 
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
    else if (Index >= list->size) 
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
        int TailIndex = list->size;

        if (Index > TailIndex / 2)
        {
            Node *current = list->tail;
            for (int i = TailIndex - 1; i > Index && current != NULL; i--) 
            {
                current = current->prev;
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
            Node *current = list->head;
            for (int i = 0; i < Index && current != NULL; i++) 
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
    }

    list->size++;
}

// Removes an element from the list
void remove_at(linkedlist *list, int index) 
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

    list->size--;

    if (list->size == 0) 
    {
        list->tail = NULL;
    }
}

// Find a node by the data storage on it
int get_node(linkedlist *list, float data) 
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
        return -1;
    }
    
    return Index;
}

// Free the allocated memory
void free_list(linkedlist *list) 
{
    if (list->size == 0) return;

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
