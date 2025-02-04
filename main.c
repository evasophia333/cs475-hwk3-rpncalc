/*
 ============================================================================
 Name        : main.c
 Author      : Eva Sophia Shimanski, Kate Schuh
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Deadlock detection algorithm
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "DDetect.h"


/*
* Main method and file handling for Deadlock Detection algorithm
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

	// TODO initialize graph
	Graph *g = createGraph();
	//printf("Created graph\n");
	//rag_print(g);

	// do commands
	int pid;
	char event;
	int lockid;
	while( fscanf(file, "%d %c %d", &pid, &event, &lockid) != EOF )
    {
        //printf("%d %c %d\n", pid, event, lockid);
		if (event == 'R')
		{
			//printf("Requesting...\n");
			rag_request(g, pid, lockid);
		}
		else if (event == 'A')
		{
			//printf("Allocating...\n");
			rag_alloc(g, pid, lockid);
		}
		else if (event == 'D')
		{
			//printf("Releasing...\n");
			rag_dealloc(g, pid, lockid);
		}
		//rag_print(g);
    }

	rag_print(g);

	// run deadlock detection algorithm
	deadlock_detect(g);

    fclose(file);
	return 0;
}
