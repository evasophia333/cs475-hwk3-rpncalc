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
	//push(&head, 7);
	//push(&head, 1);
	//push(&head, '+');
	char keys[22] = "10\t4\t-";
	evaulate(keys);
	//print remaining linked list

	return 0;
}
