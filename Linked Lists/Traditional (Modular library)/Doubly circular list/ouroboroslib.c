#include "ouroboroslib.h"
#include <math.h> // for NAN

void init_list(ouroboros *list) 
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Node* create_node(float data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_at(ouroboros *list, int index, float data) 
{
    Node *new_node = create_node(data);

    if (index <= 0 || list->size == 0) 
    {
        if (list->size == 0) 
        {
            list->head = new_node;
            list->tail = new_node;
            new_node->next = new_node;
            new_node->prev = new_node;
        } 
        else 
        {
            new_node->next = list->head;
            new_node->prev = list->tail;
            list->tail->next = new_node;
            list->head->prev = new_node;
            list->head = new_node;
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
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;

        if (current == list->tail) 
        {
            list->tail = new_node;
        }
    }

    list->size++;
}

void remove_at(ouroboros *list, int index) 
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
            list->head->prev = list->tail;
            list->tail->next = list->head;
            free(current);
        }
    } 
    else 
    {
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == list->tail) 
        {
            list->tail = current->prev;
        }

        free(current);
    }

    list->size--;
}

int get_node(ouroboros *list, float data) 
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

float get_element_at(ouroboros *list, int index) 
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

void free_list(ouroboros *list) 
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

void print_list(ouroboros *list) 
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

int get_size(ouroboros *list) 
{
    return list->size;
}
