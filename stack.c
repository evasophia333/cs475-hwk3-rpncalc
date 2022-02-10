/**
 * Linked list implementation of a stack
 * Author: E Shimanski 
 */
#include <stdio.h>
#include <stdlib.h>

int sizeOfList = 0;

/**
 * Structure of a node for alinked list 
 */
struct Node
{
    double data;
    struct Node *next;
};

/**
 * prints each element of the list 
 * @param n a list of nodes
 */
void printList(struct Node *n)
{
    printf("\n");
    while (n != NULL)
    {
        if (n->next == NULL)
        {
            printf("%f", n->data);
            n = n->next;
        }
        else
        {
            printf(" %f ->", n->data);
            n = n->next;
        }
    }
    printf("\n");
}

/**
 * adds element to the front of a linked list
 * @param prevHead head reference, and newData being the data to add 
 */
void push(struct Node **prevHead, double newData)
{
    //make space for new node
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = newData;     //put in the data
    node->next = (*prevHead); //now change the pointer
    (*prevHead) = node;       //head points to new node
    sizeOfList++;             //update the size of the list
}

/**
 * remove head element from a linked list 
 * @return the number removed 
 * @param node the list of nodes 
 */
double pop(struct Node **node)
{
    if (*node == NULL)
    { //check the node to make sure that it isnt the wrong one
        return -1;
    }
    struct Node *head = *node;
    double deleted = head->data; //pull out data before the node is deleted
    (*node) = (*node)->next;
    free(head);
    sizeOfList--;
    return deleted; //let the user know whichnode is rturned
}

/**
 * lets the user know the size of the list
 * @returns size of the list 
 */
int size()
{
    return sizeOfList;
}

/**
 * Empties the stack 
 * @param list of nodes 
 */
void emptyStack(struct Node *node)
{
    while (size(node) > 0)
    {
        pop(node);
    }
}