
//Linked list implementation of a stack
#include <stdio.h>
#include <stdlib.h>

int sizeOfList=0;

struct Node {
    double data;
    struct Node* next;
};

/*prints each element in a list
*@input node */
void printList(struct Node* n)
{
    while (n != NULL)
    {
        printf(" %f ->", n->data);
        n = n->next;
    }
    printf("\n");
}

/*adds element to the front of a linked list
*@input head reference, and new data to add */
void push(struct Node** prevHead, double newData)
{
    //make space for new node
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data=newData; //put in the data
    node->next = (*prevHead); //now change the pointer
    (*prevHead) = node; //head points to new node
    sizeOfList++; //update the size of the list 
}

double pop(struct Node** node)
{
    if (*node == NULL) { //check the node to make sure that it isnt the wrong one
        return -1;
    }
    struct Node* head = *node;
    double deleted = head->data;//pull out data before the node is deleted
    (*node) = (*node)->next;  
    free(head); 
    return deleted; //let the user know whichnode is rturned
}


/*lets the user know the size of the list
*@returns size of the list */
int size()
{
    return sizeOfList;
}


