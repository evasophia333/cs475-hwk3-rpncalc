/*
 ============================================================================
 Name        : PolishSol.c
 Author      : Eva Sophia Shimanski
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 /* maximum RPN expression input length */

int main()
{
	/*
	char eqn[MAX_EQ_LEN];  // string to store the input RPN expression
	char resp[MAX_EQ_LEN]; // string to store the user's response "y" or "n"
	char cont = 'y';
	while (cont == 'n') //CHANGE TO y
	{
		printf("Enter an equation (in RPN):\n");
		// scanf("%s", ); //add elements each to stack
	}
	// points to the head node of the linked list
	*/
	struct Node *head = NULL;
	push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

	printf("before pop:");
	printList(head); //print list before the pop
	int i = pop(&head);
	printf("\nThe popped node is %d\n", i);

	//print remaining linked list
	printList(head);
	return 0;
}
