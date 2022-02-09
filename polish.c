// TODO implementation of evaluate() goes here
#include <stdio.h>
#include <stdlib.h>
//evaulates the user input 
double evaulate(char input[]){
//check element, if number then push and have a counter to make sure there are
//more than two numbers 
//if not a number then if there have been two previous numbers pop them off
//and either add, sub, div (check zero), or multiply
//if other then print invalid input 
struct Node* head = NULL;
 int size = sizeof(input)/sizeof(input[0]);
    // construct a linked list
    for (int i = size-1; i >= 0; i--) {
        push(&head, input[i]);
    }
}
