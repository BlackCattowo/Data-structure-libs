#include "circularlib.h"
#include <math.h> // for NAN

void init_list(circular *list) 
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

Node* create_node(float data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

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

int get_size(circular *list) 
{
    return list->size;
}
