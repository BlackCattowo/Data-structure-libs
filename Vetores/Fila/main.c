#include <stdio.h>
#include "queueLib.h" // Include the Queue library

int main()
{
    // Declare a queue
    queue myQueue;

    // Initialize the queue with an initial size of 4
    set_queue(&myQueue, 4);

    // Push elements into the queue
    printf("Pushing elements into the queue:\n");
    myQueue.push(&myQueue, 10);
    myQueue.push(&myQueue, 20);
    myQueue.push(&myQueue, 30);
    myQueue.push(&myQueue, 40);

    // Print the queue
    printf("Queue after pushing elements:\n");
    myQueue.print(&myQueue);

    // Eject (remove) the first element from the queue
    printf("Ejecting the first element from the queue.\n");
    myQueue.eject(&myQueue);

    // Print the queue after ejection
    printf("Queue after ejecting the first element:\n");
    myQueue.print(&myQueue);

    // Get the first element
    int first = myQueue.first(&myQueue);
    printf("First element in the queue: %d\n", first);

    // Get the last element
    int last = myQueue.last(&myQueue);
    printf("Last element in the queue: %d\n", last);

    // Push another element into the queue
    printf("Pushing another element (50) into the queue:\n");
    myQueue.push(&myQueue, 50);

    // Print the queue again
    printf("Queue after pushing another element:\n");
    myQueue.print(&myQueue);

    // Free the memory allocated for the queue
    myQueue.free(&myQueue);
    printf("Queue memory freed.\n");

    return 0;
}


