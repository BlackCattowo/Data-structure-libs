#include <stdio.h>
#include "stackLib.h" // Include the Stack library

int main()
{
    // Declare a stack
    stack myStack;

    // Initialize the stack with an initial size of 4
    set_stack(&myStack, 4);

    // Push elements into the stack
    printf("Pushing elements onto the stack:\n");
    myStack.push(&myStack, 10);
    myStack.push(&myStack, 20);
    myStack.push(&myStack, 30);
    myStack.push(&myStack, 40);

    // Print the stack
    printf("Stack after pushing elements:\n");
    myStack.print(&myStack);

    // Pop (remove) the last element from the stack
    printf("Popping the last element from the stack.\n");
    myStack.pop(&myStack);

    // Print the stack after popping
    printf("Stack after popping the last element:\n");
    myStack.print(&myStack);

    // Get the last element
    int last = myStack.last(&myStack);
    printf("Last element in the stack: %d\n", last);

    // Push another element onto the stack
    printf("Pushing another element (50) onto the stack:\n");
    myStack.push(&myStack, 50);

    // Print the stack again
    printf("Stack after pushing another element:\n");
    myStack.print(&myStack);

    // Free the memory allocated for the stack
    myStack.free(&myStack);
    printf("Stack memory freed.\n");

    return 0;
}
