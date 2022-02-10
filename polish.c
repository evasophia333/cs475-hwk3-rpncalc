// TODO implementation of evaluate() goes here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//evaulates the user input
void evaulate(char input[])
{
    //check element, if number then push and have a counter to make sure there are
    //more than two numbers
    //if not a number then if there have been two previous numbers pop them off
    //and either add, sub, div (check zero), or multiply
    //if other then print invalid input
    struct Node *head = NULL;
    char delim[] = " ";
    char space = " ";
    char* ptr = strtok(input, "\t");

    while (ptr != NULL)
    {
        printf("\nElement: %d\n",*ptr);
        if (*ptr == '+')
        { 
            if (size() < 2)
            {
                printf("Error: insufficient operands");
                return;
            }
            else
            {
                double result = pop(&head) + pop(&head);
                push(&head, result);
            }
        }
        else if (*ptr == '-')
        {
            if (size() < 2)
            {
                printf("Error: insufficient operands");
                printf("%d", size());
                return;
            }
            else
            {
                double result = pop(&head) - pop(&head);
                push(&head, result);
            }
        }
        else if (*ptr == '*')
        {
            if (size() < 2)
            {
                printf("Error: insufficient operands");
                return;
            }
            else
            {
                double result = pop(&head) * pop(&head);
                push(&head, result);
            }
        }
        else if (*ptr == '/')
        {
            if (size() < 2)
            {
                printf("Error: insufficient operands");
                return;
            }
            else
            {
                double elem1 = pop(&head);
                if (elem1 == 0)
                {
                    printf("Error: Divide by zero! Not possible.");
                    return;
                }
                else
                {
                    double result = pop(&head) / elem1;
                    push(&head, result);
                }
            }
        }
        else
        {
            push(&head, *ptr - 48);
        }
        ptr = strtok(NULL, " ");
    }
    if (size() == 1)
    {
        printList(head);
    }
    else
    {
        printf("\n Error: too many operands");
        printf("%d",size());
    }
}