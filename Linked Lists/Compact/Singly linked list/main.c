#include "singlylib.h"

int main() 
{
    // Initialize two linked lists
    singly list1;
    singly list2;
    
    init_list(&list1);
    init_list(&list2);

    // Insert elements into list1
    insert_at(&list1, 0, 10.0);
    insert_at(&list1, 1, 20.5);
    insert_at(&list1, 2, 30.2);
    insert_at(&list1, 1, 15.0);  // Insert 15.0 at index 1

    // Insert elements into list2
    insert_at(&list2, 0, 5.5);
    insert_at(&list2, 1, 25.3);

    // Print both lists
    printf("Contents of list1:\n");
    print_list(&list1);
    
    printf("\nContents of list2:\n");
    print_list(&list2);

    // Get the size of the lists
    printf("\nSize of list1: %d\n", get_size(&list1));
    printf("Size of list2: %d\n", get_size(&list2));

    // Find the index of a specific node by its value in list1
    float search_value = 20.5;
    int found_index = get_node(&list1, search_value);
    if (found_index != -1) 
    {
        printf("\nElement %.2f found at index %d in list1.\n", search_value, found_index);
    } 
    else 
    {
        printf("\nElement %.2f not found in list1.\n", search_value);
    }

    // Retrieve an element at a specific index in list1
    float element = get_element_at(&list1, 2);
    if (element != -1) 
    {
        printf("\nElement at index 2 in list1: %.2f\n", element);
    }

    // Remove an element at a specific index in list1
    remove_at(&list1, 1);
    printf("\nContents of list1 after removing element at index 1:\n");
    print_list(&list1);
    printf("\nSize of list1 after removing element: %d\n", get_size(&list1));

    // Free both lists
    free_list(&list1);
    free_list(&list2);

    return 0;
}