/*
 ============================================================================
 Name        : main.c
 Author      : Eva Sophia Shimanski, Kate Schuh
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "DDetect.h"


/*
* Excecutes the user input for an RNP calculator
*/
int main(int argc, char *argv[])
{
	if (argc != 2) 
	{
		printf("Usage: ./Deadlock <scenario file>\n");
		exit(1);
	}
	

	FILE * file;
	file = fopen(argv[1], "r");
	if (file == NULL) 
	{
		printf("File not found: %s\n", argv[1]);
		exit(1);
	}

	// initialize graph etc

	int pid;
	char event;
	int lockid;
	while( fscanf(file, "%d %c %d", &pid, &event, &lockid) != EOF )
    {
        printf("%d %c %d\n", pid, event, lockid);
		if (event == 'R')
		{
			
		}
		else if (event == 'A')
		{

		}
		else if (event == 'D')
		{

		}
    }

    fclose(file);
	return 0;
}
