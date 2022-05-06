#include <stdio.h>
#include <stdlib.h>


#define NLOCK 10 
#define NPROC 20 
#define LOCK 0
#define PROC 1

int cycleNumber = 0;

typedef struct AdjListNode {
    int id;
    int lockOrProc;
    struct AdjListNode* next;
}AdjListNode;
 
// A structure to represent an adjacency list
typedef struct AdjList {
    int id;
    int lockOrProc;
    struct AdjListNode* head;
}AdjList;
 

typedef struct Graph {
    int V;
    struct AdjList* array;
}Graph;

/**
 *
 *
 */
struct AdjListNode* newAdjListNode(int id, int lockOrProc)
{
    AdjListNode* newNode
        = (AdjListNode*)malloc(
            sizeof(AdjListNode));
    newNode->id = id;
    newNode->lockOrProc = lockOrProc;
    newNode->next = NULL;
    return newNode;
}

/**
 *
 *
 */
struct Graph* createGraph()
{
    struct Graph* graph
        = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = NLOCK + NPROC;
 
    // Create an array of adjacency lists.  Size of
    // array will be V
    graph->array = (struct AdjList*)malloc((NLOCK + NPROC) * sizeof(struct AdjList));
 
    // Initialize each adjacency list as empty by
    // making head as NULL
    int i;
    for (i = 0; i < NPROC; i++){
        graph->array[i].id = i;
        graph->array[i].lockOrProc = PROC;
        graph->array[i].head = NULL;
    }
    for (i = NPROC; i < (NPROC + NLOCK); i++){
        graph->array[i].id = i;
        graph->array[i].lockOrProc = LOCK;
        graph->array[i].head = NULL;
    }
 
    return graph;
}

void freeGraph(Graph *graph)
{
    AdjListNode *check = NULL;
    AdjListNode *prev = NULL;
    int i;
    for (i = 0; i < (NPROC + NLOCK); i++)
    {
        check = graph->array[i].head;
        while (check->next != NULL)
        {
            prev = check;
            check = check->next;
            free(prev);
        }
    }
    free(graph->array);
    free(graph);
}



/**
 * adds a request edge to the RAG from pid to lockid
 *
 */ 
void rag_request(Graph *graph, int pid, int lockid)
{
    // create a node
    AdjListNode *newNode = newAdjListNode(lockid, LOCK);
    // search for source in array (linear)
    int i;
    for (i = 0; i < NPROC; i++)
    {
        if (graph->array[i].id == pid){
            // figure out where in it's list to put it
            newNode->next = graph->array[i].head;
            graph->array[i].head = newNode;
        }
    }
    

}

/**
 *
 *
 */
void rag_alloc(Graph *graph, int pid, int lockid)
{
    // create a node
    AdjListNode *newNode = newAdjListNode(pid, PROC);
    // search for source in array (linear)
    int i;
    for (i = NPROC; i < (NPROC + NLOCK); i++)
    {
        printf("%d\n",lockid);
        printf("%d\n",graph->array[i].id);
        if (graph->array[i].id == (lockid + NPROC)){
            printf("Hellor\n");
            // figure out where in it's list to put it
            newNode->next = graph->array[i].head;
            graph->array[i].head = newNode;
        }
    }

    /*
    // remove request edge
    AdjListNode *check = NULL;
    AdjListNode *prev = NULL;
    for (i = 0; i < NPROC; i++)
    {
        if (graph->array[i].id == pid){
            // figure out where in it's list to put it
            check = graph->array[i].head;
            while (check->next != NULL)
            {
                if (check->id == lockid && check->lockOrProc == LOCK)
                {
                    if (prev == NULL)
                    {
                        graph->array[i].head = check->next;
                    }
                    else{
                        prev->next = check->next;
                    }
                    free(check);
                    break;
                    
                }
                prev = check;
                check = check->next;
            }
        }
    }
    */
}

/**
 *
 *
 */
void rag_dealloc(Graph *graph, int pid, int lockid)
{
    // remove allocation edge
    AdjListNode *check = NULL;
    AdjListNode *prev = NULL;
    int i;
    for (i = NPROC; i < (NPROC + NLOCK); i++)
    {
        if (graph->array[i].id == lockid){
            // figure out where in it's list to put it
            check = graph->array[i].head;
            while (check->next != NULL)
            {
                if (check->id == pid && check->lockOrProc == PROC)
                {
                    if (prev == NULL)
                    {
                        graph->array[i].head = check->next;
                    }
                    else{
                        prev->next = check->next;
                    }
                    free(check);
                    break;
                    
                }
                prev = check;
                check = check->next;
            }
        }
    }
}

/**
 *
 *
 */
void rag_print(Graph *graph)
{
    printf("Printing...\n");
    int i;
    AdjListNode *check = NULL;
    //for (i = 0; i < NPROC; i++)
    for ( i = 0; i < 5; i++)
    {
        check = graph->array[i].head;
        printf("Node pid=%d -> { ", i);
        while (check != NULL)
        {
            printf("lockid=%d ", check->id);
            check = check->next;
        }
        printf(" }\n");
    }

    //for ( i = NPROC; i < (NPROC + NLOCK); i++)
    for ( i = 5; i < 8; i++)
    {
        check = graph->array[i].head;
        printf("Node lockid=%d -> { ", i);
        while (check != NULL)
        {
            printf("pid=%d ", check->id);
            check = check->next;
        }
        printf(" }\n");
    }
}

/**
 *
 *
 */
void deadlock_detect(Graph *graph)
{
    //
}

/*
int icCycle(int i, int *visited, int *recStack, Graph *graph)
{
    if (recStack[i])
    {
        return 1; // true
    }

    if (visited[i])
    {
        return 0; // false
    }

    visited[i] = 1;

    recStack[i] = 1;
    AdjList *array = graph->array[i];

    AdjListNode *check = array->head;
    while (check != NULL)
    {
        if (isCycle(check->id, visited, recStack, graph))
        {
            return 1;
        }

        check = check->next;
    }
    recStack[i] = 0;
    return 0;
}
*/