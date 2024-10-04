#include <stdio.h>
#include <stdlib.h>
#include "linkedlists.h"
#include "addonlists.h"

int main()
{
    char Command;
    int Index = 0, interval_start = 0, interval_end = 0;
    float Element;

    linkedlist Lista;
    init_list(&Lista);

    for(;;)
    {// Input loop
        scanf(" %c", &Command);
        if (Command == 'C')
        {// Creates a new list
            if (get_size(&Lista) == 0)
            {
                init_list(&Lista);
            }
            else
            {
                free_list(&Lista);
                init_list(&Lista);
            }
            
        }
        else if (Command == 'E')
        {// Ends program
            break;
        }
        else
        {
            if (Command == 'P')
            {// Prints list
                print_list(&Lista);
            }
            else if (Command == 'I')
            {// Place a new element in a given position
                scanf(" %d %f", &Index, &Element);
                insert_at((&Lista), Index, Element);   
            }
            else if (Command == 'R')
            {// Removes one element from the list
                scanf(" %d", &Index);
                remove_at((&Lista), Index);
            }
            else if (Command == 'S')
            {// Swap elements inside a given interval
                scanf(" %d %d", &interval_start, &interval_end);
                swap((&Lista), interval_start, interval_end);
            }
            else if (Command == 'F')
            {// Changes the position of a sequence inside the list (after a certain Index)
                scanf(" %d %d %d", &interval_start, &interval_end, &Index);
                move_sequence_afterP((&Lista), interval_start, interval_end, Index);
            }
            else if (Command == 'B')
            {// Changes the position of a sequence inside the list (before a certain Index)
                scanf(" %d %d %d", &interval_start, &interval_end, &Index);
                move_sequence_beforeP((&Lista), interval_start, interval_end, Index);
            }
            else if (Command == 'G')
            {// gets the position of a node given its data
                scanf(" %f", &Element);
                get_node((&Lista), Element);
            }
            else if (Command == 'H')
            {// Returns the size of the list.
                printf("%d", get_size(&Lista));
            }
            else 
            {// Give use information to usr.
                printf("Invalid operation. List of operations: \n");
                printf("(c = command, i = index, x and y = start and end of sequence, d = data.) \n");
                printf("C - Creates list (c)\n");
                printf("E - Ends program (c)\n");
                printf("I - Insert (c i d)\n");
                printf("R - Remove (c i) \n");
                printf("S - Swap elements (c x y) \n");
                printf("F - Move sequence foward (c x y i)\n");
                printf("B - Move sequence backwards (c x y i)\n");
                printf("G - Get Position (c d)\n");
                printf("H - Height/list (c) \n");
                printf("P - Print (c)");
            }
            
        }
    }
}