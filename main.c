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
/*
* Excecutes the user input for an RNP calculator
*/
int main()
{
	char eqn[MAX_EQ_LEN];  // string to store the input RPN expression
	char resp[MAX_EQ_LEN]; // string to store the user's response "y" or "n"
	char cont = 'y';
	while (cont == 'y')
	{
		printf("Enter an equation (in RPN):\n");
		fgets(eqn, MAX_EQ_LEN, stdin); // get RPN expression from user
		evaulate(eqn);
		printf("\nEvaluate another? ('y'/'n'): ");
		fgets(resp, MAX_EQ_LEN, stdin); //see if they want to evaluate another
		if (resp[0] == 'n')
		{
			cont = 'n';
			printf("Exiting....");
		}
		while (strlen(resp) > 2 || (resp[0] != 'y' && resp[0] != 'n')) 
		{ // invalid input
			printf("\nPlease enter a valid input.\n");
			printf("Evaluate another? (y/n): ");
			fgets(resp, MAX_EQ_LEN, stdin);
			if (resp[0] == 'n')
			{
				cont = 'n';
				printf("Exiting....\n");
			}
		}
	}
	return 0;
}
