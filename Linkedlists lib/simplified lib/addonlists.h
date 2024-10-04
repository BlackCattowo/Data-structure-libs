#ifndef ADDONLISTS_H
#define ADDONLISTS_H

#include "linkedlists.h"

// Function to invert elements between two positions (I, J)in the linked list
void swap(linkedlist *list, int I, int J) 
{
    // Checks the vality of the input
    if (I < 0 || J >= list->size || I >= J) 
    {
        return;
    }

    // Finde the nodes between I and J
    Node *start = list->head;
    Node *end = list->head;

    
    for (int index = 0; index < I; index++) 
    {// Traverse to I node
        start = start->next;
    }
    for (int index = 0; index < J; index++) 
    {// Traverse to J node
        end = end->next;
    }

    // Swap the elements
    while (I < J) 
    {
        // Swap elements from I to J
        float temp = start->data;
        start->data = end->data;
        end->data = temp;

        // Move traverse list from both sides
        start = start->next;
        end = end->prev;

        // Update Index
        I++;
        J--;
    }
}


// Function to move a whole section of the linked list before a certain position
void move_sequence_beforeP(linkedlist *list, int X1, int Y1, int P) 
{
    // Variable declarations
    int I1 = 0;  
    int J1 = 0;   
    int A1 = 0;
    int B1 = 0;

    int sequence1_length = 0;  
    int sequence2_length = 0;  
    int sequence3_length = 0;  
    
    int Y2 = 0;
    int X2 = 0;
    int I2 = 0;
    int J2 = 0;
    int A2 = 0;
    int B2 = 0;

    // Checks the validity of the input
    if (X1 < 0 || Y1 >= list->size || X1 > Y1 || P > list->size || (P - sequence1_length < 0) || P == Y1) 
    {
        return;
    }

    if(P > Y1)
    {// When P comes before Y1
        I1 = (Y1 + 1);  
        J1 = (P - 1);   

        // calculate the positions after moving the sequence
        Y2 = J1;
        X2 = (Y2 - (Y1 - X1));
        I2 = X1;
        J2 = (I2 + (Y1 - X1));

        sequence1_length = ((Y1 - X1) + 1);  
        sequence2_length = ((J1 - I1) + 1);  
    }

    else if(P == 0)
    {// If P is at zero
        I1 = 0;  
        J1 = (X1 - 1);   

        // calculate the positions after moving the sequence
        X2 = 0;
        Y2 = (Y1 - X1);
        I2 = (Y2 + 1);
        J2 = Y1;

        sequence1_length = ((Y1 - X1) + 1);  
        sequence2_length = ((J1 - I1) + 1);  
    }

    else if(P < X1)
    {// If P comes before X1 there will be 3 subsequencies to be worked around
        sequence1_length = ((Y1 - X1) + 1);  
        sequence2_length = (sequence1_length - 1);  
        sequence3_length = (P - X1);  

        A1 = P;
        B1 = X1 - 1;

        if(sequence1_length > 1)
        {//if sequence 1 contains more than one element
            J1 = (P - 1);   
            I1 = ((J1 + 1) - sequence2_length);  

           // calculate the positions after moving the sequence
            X2 = I1;
            Y2 = P;
            I2 = X1;
            J2 = (I2 + (sequence2_length - 1));
            A2 = J2 + 1;
            B2 = (A2 + sequence3_length - 1);
            
        }
        else if(sequence1_length == 1)
        {//if sequence 1 contains just one element

            // calculate the positions after moving the sequence
            X2 = P;
            Y2 = P;
            A2 = P + 1;
            B2 = (A2 + sequence3_length - 1);
        }
    }

    else if(P < Y1)
    {// Case in which P is between X1 and Y1.
        sequence1_length = ((Y1 - X1) + 1);  
        sequence2_length = (Y1 - P); 

        I1 = (X1 - sequence2_length);  
        J1 = (X1 - 1);   
        
        // calculate the positions after moving the sequence
        X2 = I1;
        Y2 = P;
        J2 = Y1;
        I2 = ((J2 - sequence2_length) + 1);
    }
    Node *current = list->head;

    // Create temporary arrays to save sequences and subsequences
    float *sequence_1 = (float *)malloc(sequence1_length * sizeof(float));  // Sequence 1 (X1 to Y1)
    float *sequence_2 = NULL;
    float *sequence_3 = NULL;
    if(sequence2_length > 0)
    {// Only allocate memory for sequence 2 if sequence2_length is positive
        float *sequence_2 = (float *)malloc(sequence2_length * sizeof(float));  // Sequence 2 (I1 to J1)
    }
    if(sequence3_length > 0)
    {// Only allocate memory for sequence 3 if sequence3_length is positive
        float *sequence_3 = (float *)malloc(sequence3_length * sizeof(float));  // Sequence 3 (A1 to B1) 
    }

    // Create sequence 1 (X1 to Y1)
    current = list->head;
    for (int i = 0; i < X1; i++) 
    {// Traverse list to find the start point of the sequence
        current = current->next;
    }
    for (int i = 0; i < sequence1_length; i++) 
    {// Saves the desired elements in the sequence
        sequence_1[i] = current->data;
        current = current->next;
    }

    if(sequence_2 != NULL)
    {// Create sequence 2 (I1 to J1), if that sequence is being utilized
        current = list->head;
        for (int i = 0; i < I1; i++) 
        {// Traverse list to find the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence2_length; i++) 
        {// Saves the desired elements in the sequence
            sequence_2[i] = current->data;
            current = current->next;
        }
    }

    

    if (sequence_3 != NULL)
    {// Create sequence 3 (A1 to B1), if that sequence is being utilized

        current = list->head;
        for (int i = 0; i < A1; i++) 
        {// Traverse list to find the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence3_length; i++) 
        {// Saves the desired elements in the sequence
            sequence_3[i] = current->data;
            current = current->next;
        }
    }


    if (P > Y1)
    {
        // Paste sequence 1 in the desired position
        current = list->head;
        for (int i = 0; i < X2; i++) 
        {// Traverse list to find the Index of the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence1_length; i++) 
        {// Saves the desired elements on the list
            current->data = sequence_1[i];
            current = current->next;
        }

        // Paste sequence 2 in the desired position
        current = list->head;
        for (int i = 0; i < I2; i++) 
        {// Traverse list to find the Index of the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence2_length; i++) 
        {// Saves the desired elements on the list
            current->data = sequence_2[i];
            current = current->next;
        }
    }
    else
    {
        // Paste sequence 1 in the desired position
        current = list->head;
        for (int i = 0; i < X2; i++) 
        {// Traverse list to find the Index of the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence1_length; i++) 
        {// Saves the desired elements on the list
            current->data = sequence_1[i];
            current = current->next;
        }

        // Paste sequence 2 in the desired position
        current = list->head;
        for (int i = 0; i < I2; i++) 
        {// Traverse list to find the Index of the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence2_length; i++) 
        {// Saves the desired elements on the list
            current->data = sequence_2[i];
            current = current->next;
        }

        // Paste sequence 3 in the desired position
        current = list->head;
        for (int i = 0; i < B2; i++) 
        {// Traverse list to find the Index of the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence3_length; i++) 
        {// Saves the desired elements on the list
            current->data = sequence_3[i];
            current = current->next;
        }
    }

//Debug functions
/*
printf("P = %d, X1 = %d, Y1 = %d, I1 = %d, J1 = %d\n", P, X1, Y1, I1, J1);
printf("X2 = %d, Y2 = %d, I2 = %d, J2 = %d\n", P, X2, Y2, I2, J2);
printf("A1 = %d, B1 = %d, A2 = %d, B2 = %d\n", P, A1, B1, A2, B2);
printf("Sequence 1 lenght: %d\n", sequence1_length);
printf("Sequence 2 lenght: %d\n", sequence2_length);
printf("Sequence 2 lenght: %d\n", sequence3_length);

printf("Lista depois do swap:\n"); 
print_list(&Lista);
*/

    // Free allocated memory
    free(sequence_1);
    if(sequence_2 != NULL)
    {
        free(sequence_2);
    }
    if(sequence_3 != NULL)
    {
        free(sequence_3);
    }
}

/*
NOTE: NOT WORKING PROPERLLY!
Function to move a whole section of the linked list after a certain position.
*/
void move_sequence_afterP(linkedlist *list, int X1, int Y1, int P) 
{// W.I.P.
    // Variable declarations
    int I1 = 0;  
    int J1 = 0;   
    int A1 = 0;
    int B1 = 0;

    int sequence1_length = 0;  
    int sequence2_length = 0;  
    int sequence3_length = 0;  
    
    int Y2 = 0;
    int X2 = 0;
    int I2 = 0;
    int J2 = 0;
    int A2 = 0;
    int B2 = 0;

    // Checks the validity of the input
    if (X1 < 0 || Y1 >= list->size || X1 > Y1 || P >= list->size || (P + 1 + sequence1_length > list->size)) 
    {
        return;
    }

    if(P >= Y1)
    {// When P is after or at the end of the sequence
        I1 = (Y1 + 1);  
        J1 = P;   

        // calculate the positions after moving the sequence
        X2 = P + 1;
        Y2 = X2 + (Y1 - X1);
        I2 = X1;
        J2 = (I2 + (Y1 - X1));

        sequence1_length = ((Y1 - X1) + 1);  
        sequence2_length = ((J1 - I1) + 1);  
    }
    else if(P == 0)
    {// If P is at the start of the list
        I1 = 0;  
        J1 = (X1 - 1);   

        // calculate the positions after moving the sequence
        X2 = 1;
        Y2 = X2 + (Y1 - X1);
        I2 = (Y2 + 1);
        J2 = Y1;

        sequence1_length = ((Y1 - X1) + 1);  
        sequence2_length = ((J1 - I1) + 1);  
    }
    else if(P < X1)
    {// If P comes before X1 there will be 3 subsequences to handle
        sequence1_length = ((Y1 - X1) + 1);  
        sequence2_length = (sequence1_length - 1);  
        sequence3_length = (X1 - (P + 1));  

        A1 = P + 1;
        B1 = X1 - 1;

        if(sequence1_length > 1)
        {//if sequence 1 contains more than one element
            J1 = P;   
            I1 = (P + 1) - sequence2_length;  

           // calculate the positions after moving the sequence
            X2 = P + 1;
            Y2 = X2 + (sequence1_length - 1);
            I2 = X1;
            J2 = (I2 + (sequence2_length - 1));
            A2 = J2 + 1;
            B2 = (A2 + sequence3_length - 1);
        }
        else if(sequence1_length == 1)
        {//if sequence 1 contains just one element
            // calculate the positions after moving the sequence
            X2 = P + 1;
            Y2 = X2;
            A2 = X2 + 1;
            B2 = (A2 + sequence3_length - 1);
        }
    }
    else if(P < Y1)
    {// Case in which P is between X1 and Y1.
        sequence1_length = ((Y1 - X1) + 1);  
        sequence2_length = (Y1 - P); 

        I1 = (X1 - sequence2_length);  
        J1 = (X1 - 1);   
        
        // calculate the positions after moving the sequence
        X2 = P + 1;
        Y2 = X2 + (Y1 - X1);
        J2 = Y1;
        I2 = ((J2 - sequence2_length) + 1);
    }

    Node *current = list->head;

    // Create temporary arrays to save sequences and subsequences
    float *sequence_1 = (float *)malloc(sequence1_length * sizeof(float));  // Sequence 1 (X1 to Y1)
    float *sequence_2 = NULL;
    float *sequence_3 = NULL;
    if(sequence2_length > 0)
    {// Only allocate memory for sequence 2 if sequence2_length is positive
        sequence_2 = (float *)malloc(sequence2_length * sizeof(float));  // Sequence 2 (I1 to J1)
    }
    if(sequence3_length > 0)
    {// Only allocate memory for sequence 3 if sequence3_length is positive
        sequence_3 = (float *)malloc(sequence3_length * sizeof(float));  // Sequence 3 (A1 to B1) 
    }

    // Create sequence 1 (X1 to Y1)
    current = list->head;
    for (int i = 0; i < X1; i++) 
    {// Traverse list to find the start point of the sequence
        current = current->next;
    }
    for (int i = 0; i < sequence1_length; i++) 
    {// Saves the desired elements in the sequence
        sequence_1[i] = current->data;
        current = current->next;
    }

    if(sequence_2 != NULL)
    {// Create sequence 2 (I1 to J1), if that sequence is being utilized
        current = list->head;
        for (int i = 0; i < I1; i++) 
        {// Traverse list to find the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence2_length; i++) 
        {// Saves the desired elements in the sequence
            sequence_2[i] = current->data;
            current = current->next;
        }
    }

    if (sequence_3 != NULL)
    {// Create sequence 3 (A1 to B1), if that sequence is being utilized
        current = list->head;
        for (int i = 0; i < A1; i++) 
        {// Traverse list to find the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence3_length; i++) 
        {// Saves the desired elements in the sequence
            sequence_3[i] = current->data;
            current = current->next;
        }
    }

    // Paste the sequences back into the list
    // Paste sequence 1 in the desired position
    current = list->head;
    for (int i = 0; i < X2; i++) 
    {// Traverse list to find the Index of the start point of the sequence
        current = current->next;
    }
    for (int i = 0; i < sequence1_length; i++) 
    {// Saves the desired elements on the list
        current->data = sequence_1[i];
        current = current->next;
    }

    if (sequence_2 != NULL)
    {// Paste sequence 2 in the desired position
        current = list->head;
        for (int i = 0; i < I2; i++) 
        {// Traverse list to find the Index of the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence2_length; i++) 
        {// Saves the desired elements on the list
            current->data = sequence_2[i];
            current = current->next;
        }
    }

    if (sequence_3 != NULL)
    {// Paste sequence 3 in the desired position
        current = list->head;
        for (int i = 0; i < A2; i++) 
        {// Traverse list to find the Index of the start point of the sequence
            current = current->next;
        }
        for (int i = 0; i < sequence3_length; i++) 
        {// Saves the desired elements on the list
            current->data = sequence_3[i];
            current = current->next;
        }
    }

    // Free allocated memory
    free(sequence_1);
    if(sequence_2 != NULL)
    {
        free(sequence_2);
    }
    if(sequence_3 != NULL)
    {
        free(sequence_3);
    }
}

#endif // ADDONLISTS_H
