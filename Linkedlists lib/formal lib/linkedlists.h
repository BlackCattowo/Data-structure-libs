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
// Creates a new node
Node* create_node(float data);

// Doubly linked list structure
typedef struct DoublyLinkedList 
{
    Node *head;
    Node *tail;
    int size;
} linkedlist;
// Initiate list
void init_list(linkedlist *list);
// Gets size of the likedlist.
int get_size(linkedlist *list);


// Insert a node containing data in a defined Index of the linkedlist
void insert_at(linkedlist *list, int Index, float data);

// Removes a node in a given Index of the linkedlist
void remove_at(linkedlist *list, int index);

// Gets the Index of a node of the linkedlist bsed on its stored data
int get_node(linkedlist *list, float data);

// Gets the Index of a node of the linkedlist bsed on its data
void free_list(linkedlist *list);

// Prints all the data stored into the linked list
void print_list(linkedlist *list);

#endif
