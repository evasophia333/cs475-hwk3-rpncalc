#include <stdio.h>
#include <stdlib.h>


#define NLOCK 10 
#define NPROC 20 

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
}AdjListNode;
 
// A structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head;
}AdjList;
 

struct Graph {
    int V;
    struct AdjList* array;
}Graph;

/**
 *
 *
 */
struct AdjListNode* newAdjListNode(int dest){
    struct AdjListNode* newNode
        = (struct AdjListNode*)malloc(
            sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

/**
 *
 *
 */
struct Graph* createGraph(int V)
{
    struct Graph* graph
        = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of
    // array will be V
    graph->array = (struct AdjList*)malloc(
        V * sizeof(struct AdjList));
 
    // Initialize each adjacency list as empty by
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i){
        graph->array[i].head = NULL;
    }
 
    return graph;
}



/**
 * adds a request edge to the RAG from pid to lockid
 *
 */ 
void rag_request(int pid, int lockid){

}