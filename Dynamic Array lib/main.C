#include <stdio.h>
#include "dynamiclib.h"

int main()
{
    // Initialize two dynamic arrays with an initial size of 5
    array array1, array2;
    init_array(&array1, 5);
    init_array(&array2, 5);

    // Add elements to array1
    printf("Adding elements to array1...\n");
    array1.add(&array1, 10);
    array1.add(&array1, 20);
    array1.add(&array1, 30);
    array1.add(&array1, 40);
    array1.add(&array1, 50);

    // Add elements to array2
    printf("Adding elements to array2...\n");
    array2.add(&array2, 100);
    array2.add(&array2, 200);
    array2.add(&array2, 300);

    // Print both arrays
    printf("Printing array1:\n");
    array1.print(&array1);  // Output: Array elements: 10 20 30 40 50
    printf("Printing array2:\n");
    array2.print(&array2);  // Output: Array elements: 100 200 300

    // Alter an element in array1 (changing value at index 2 to 99)
    printf("Altering element at index 2 in array1...\n");
    array1.alter(&array1, 2, 99);  // Changes array1[2] from 30 to 99
    printf("Array1 after alteration:\n");
    array1.print(&array1);  // Output: Array elements: 10 20 99 40 50

    // Find index of a value in array1
    printf("Finding index of value 99 in array1...\n");
    int index = array1.find(&array1, 99);
    if (index != -1)
    {
        printf("Value 99 found at index %d\n", index);
    }
    else
    {
        printf("Value 99 not found.\n");
    }

    // Get an element by index in array2
    printf("Getting element at index 1 in array2...\n");
    int element = array2.get(&array2, 1);  // Should return 200
    if (element != -1)
    {
        printf("Element at index 1 in array2 is %d\n", element);  // Output: 200
    }

    // Remove an element from array1 (remove element at index 3)
    printf("Removing element at index 3 in array1...\n");
    array1.remove(&array1, 3);  // Removes array1[3] (which is 40)
    printf("Array1 after removal:\n");
    array1.print(&array1);  // Output: Array elements: 10 20 99 50

    // Try to get an element from an invalid index in array1
    printf("Trying to access invalid index 10 in array1...\n");
    int invalid_element = array1.get(&array1, 10);
    if (invalid_element == -1)
    {
        printf("Index 10 is invalid in array1.\n");
    }

    // Free the memory for both arrays
    printf("Freeing array1 and array2...\n");
    array1.free(&array1);
    array2.free(&array2);

    return 0;
}
