#include "stack.h"
#include <stddef.h>
int sizeOfList=0;


/*prints each element in a list
*@input node */
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}
/*adds element to the front of a linked list
*@input head reference, and new data to add */
void push(struct Node** prevHead, double newData)
{
    //make space for new node
    struct Node* node = (Node*) malloc(sizeof(struct Node));
    node->data=newData; //put in the data
    node->next = (*prevHead); //now change the pointer
    (*prevHead) = node; //head points to new node
    sizeOfList++; //update the size of the list 
}
/*lets the user know the size of the list
*@returns size of the list */
int size(){
    return sizeOfList;
}


