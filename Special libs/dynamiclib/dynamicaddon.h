#ifndef DYNAMICADDON_H
#define DYNAMICADDON_H

#include "dynamiclib.h" // Inclui a biblioteca principal de arrays dinâmicos

/**
 * Sequential search function with comparison count.
 * Searches for a specified value in the dynamic array.
 * Unlike the MTF search, this function does not modify the order of elements.
 * If the value is not found, it is added to the array.
 * 
 * @param vetor Pointer to the dynamic array.
 * @param value Value to search for.
 * @return Number of comparisons made if successful, -1 if not found.
 */
int sequential_search(array *vetor, int value)
{
    int comparisons = 0;

    // Iterate through the array to search for the value
    for (size_t i = 0; i < vetor->count; i++)
    {
        comparisons++;
        if (vetor->element[i] == value)
        {
            return comparisons; // Success, value found
        }
    }

    // Element not found, add the value to the array
    add_element(vetor, value);

    return comparisons; // Return number of comparisons even if not found
}

/**
 * Move to Front (MTF) search function with comparison count.
 * Searches for a specified value in the dynamic array.
 * If the value is found, it moves the value to the front of the array
 * and returns the number of comparisons made.
 * 
 * @param vetor Pointer to the dynamic array.
 * @param value Value to search for and move to the front.
 * @return Number of comparisons made if successful, -1 if not found.
 */
int MTF_search(array *vetor, int value)
{
    int comparisons = 0;

    // Iterate manually to count comparisons
    for (size_t i = 0; i < vetor->count; i++)
    {
        comparisons++;
        if (vetor->element[i] == value)
        {
            // If the element is already at the front, no need to move
            if (i == 0)
            {
                return comparisons; // Success, no movement needed
            }

            // Store the value to be moved
            int found_value = vetor->element[i];

            // Shift all elements to the right from the first to the found index
            for (size_t j = i; j > 0; j--)
            {
                vetor->element[j] = vetor->element[j - 1];
            }

            // Place the found value at the front
            vetor->element[0] = found_value;

            return comparisons; // Success, return number of comparisons
        }
    }

    // Element not found
    add_element(vetor, value);
    MTF_search(vetor, value);
    return comparisons;
}

/**
 * Transpose search function with comparison count.
 * Searches for a specified value in the dynamic array.
 * If the value is found, it is moved one position forward in the array.
 * If the value is not found, it is added at the beginning of the array.
 * 
 * @param vetor Pointer to the dynamic array.
 * @param value Value to search for and transpose.
 * @return Number of comparisons made if successful, -1 if not found.
 */
int transpose_search(array *vetor, int value)
{
    int comparisons = 0;

    // Iterate through the array to search for the value
    for (size_t i = 0; i < vetor->count; i++)
    {
        comparisons++;
        if (vetor->element[i] == value)
        {
            // If it's already at the beginning, no need to transpose
            if (i == 0)
            {
                return comparisons; // Success, no movement needed
            }

            // Swap the found element with the previous one (move forward by 1 position)
            int temp = vetor->element[i];
            vetor->element[i] = vetor->element[i - 1];
            vetor->element[i - 1] = temp;

            return comparisons; // Success, return number of comparisons
        }
    }

    // Element not found, add it at the beginning
    // Shift all elements to the right to make space for the new one
    for (size_t j = vetor->count; j > 0; j--)
    {
        vetor->element[j] = vetor->element[j - 1];
    }
    vetor->element[0] = value;
    vetor->count++;

    return comparisons;
}

/**
 * Count-based search function with comparison count.
 * Searches for a specified value in the dynamic array and tracks how many times it was accessed.
 * The element is placed before any element with a higher access count.
 * If the value is found, its count is incremented. If not, it is added to the array and its count starts at 1.
 * 
 * @param vetor Pointer to the dynamic array.
 * @param counter Pointer to the counter array that tracks accesses.
 * @param value Value to search for and update count.
 * @return Number of comparisons made during the search.
 */
int count_search(array *vetor, array *counter, int value)
{
    int comparisons = 0;

    /*
    printf("\nDebug counter 1 - Start: \n"); 
    printf("Value: %d\n", value); 
    print_array(vetor); 
    print_array(counter); 
    printf("Comparisons: %d\n", comparisons);
    */    

    // Iterate through the array to search for the value
    for (size_t i = 0; i < vetor->count; i++)
    {
        comparisons++;
        if (vetor->element[i] == value)
        {
            // Increment the access count for this element
            counter->element[i]++;

            // Move the element forward based on its new count
            int current_count = counter->element[i];
            size_t j = i;

            // Move element forward until it finds an element with a strictly higher count
            while (j > 0 && counter->element[j - 1] <= current_count)
            {
                // Swap the elements in both the main array and the counter array
                int temp_value = vetor->element[j];
                vetor->element[j] = vetor->element[j - 1];
                vetor->element[j - 1] = temp_value;

                int temp_count = counter->element[j];
                counter->element[j] = counter->element[j - 1];
                counter->element[j - 1] = temp_count;

                j--;
            }

            /*
            printf("\nDebug counter 1.1 - Success: \n"); 
            print_array(vetor); 
            print_array(counter); 
            printf("Comparisons: %d\n", comparisons);
            */

            return comparisons; // Success, return number of comparisons
        }
    }

    // Element not found, add it at the end of the array and set its count to 1
    add_element(vetor, value);
    add_element(counter, 0); // Initialize its count to 1

    /*
    printf("\nDebug counter 2 - Add: \n"); 
    print_array(vetor); 
    print_array(counter); 
    printf("Comparisons: %d\n", comparisons);
    */

    // Move the newly added element forward based on its count
    size_t k = vetor->count - 1;
    while (k > 0 && counter->element[k - 1] <= 1)
    {
        // Swap the new element forward
        int temp_value = vetor->element[k];
        vetor->element[k] = vetor->element[k - 1];
        vetor->element[k - 1] = temp_value;

        int temp_count = counter->element[k];
        counter->element[k] = counter->element[k - 1];
        counter->element[k - 1] = temp_count;

        k--;
    }

    /*
    printf("\nDebug counter 3 - End: \n"); 
    print_array(vetor); 
    print_array(counter); 
    printf("Comparisons: %d\n", comparisons);
    */

    count_search(vetor, counter, value); // Recursive call for the added element
    return comparisons;
}


#endif // DYNAMICADDON_H
