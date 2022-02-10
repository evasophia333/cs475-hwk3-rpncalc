/**
 * Evaulation for an RPN calculator
 * Author: Eva Sophia Shimanski 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**
 * Evaluates RPN expression
 * @param input pointer to the user input
 */
void evaulate(char *input)
{
    struct Node *head = NULL;
    char* ptr = NULL;
    ptr = strtok(input, " \n\t"); //split input by space, tab or new line
    while (ptr != NULL)
    {
        if (*ptr == '+') //addition
        { 
            if (size() < 2) //catch too few numbers
            {
                printf("Error: insufficient operands\n");
                emptyStack(&head);
                return;
            }
            else
            {
                double result = pop(&head) + pop(&head);
                push(&head, result);
            }
        }
        else if (*ptr == '-') //subtraction
        {
            if (size() < 2) //catch too few numbers
            {
                printf("Error: insufficient operands\n");
                emptyStack(&head);
                return;
            }
            else
            {
                double elem1 = pop(&head);
                double result = pop(&head) - elem1;
                push(&head, result);
            }
        }
        else if (*ptr == '*')
        {
            if (size() < 2) //catch too few numbers
            {
                printf("Error: insufficient operands\n");
                emptyStack(&head);
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
                printf("Error: insufficient operands\n");
                emptyStack(&head);
                return;
            }
            else
            {
                double elem1 = pop(&head);
                if (elem1 == 0) //catch divide by zero error
                {
                    printf("Error: Divide by zero! Not possible.\n");
                    emptyStack(&head);
                    return;
                }
                else
                {
                    double result = pop(&head) / elem1;
                    push(&head, result);
                }
            }
        }
        else if(isdigit(*ptr)) //add numbers
        {
            double num = atof(ptr);
            push(&head, num);
        }else
        {
            printf("Error: Unknown Character %c\n",*ptr);
            emptyStack(&head);
            return;
        }
        ptr = strtok(NULL, " \n\t");
    }
    if (size() == 1) //print the list and empty the stack
    {
        printList(head);
        emptyStack(&head); 
    }
    else //too many numbers print error and empty stack
    {
        printf("\n Error: too many operands\n");
        emptyStack(&head);
    }
}