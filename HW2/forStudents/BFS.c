#include <stdio.h>
#include <string.h>
#include "cs4050.h"
#include "BFS.h"

void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{
    // initialize variables
    for(int i=0; i<countV; i++)
    {
        V[i].color = WHITE;
        V[i].d = 0;
        V[i].predecessor = 0;
    }

    printf("\nBFS: \n"); // print statement to indicate what search we are printing
    int u = s-1; // assuming s is the vertex number, adjacency list value will be one back

    // initalize queue
    int queue[countV];
    memset(queue, 0, countV*sizeof(int));
    int front = 0;
    int rear = 0;

    V[u].color = GRAY; // mark gray as we are visiting here first
    queue[rear++] = u; // enqueue our start point

    while(front != rear)
    {
        u = queue[front++]; // dequeue where we are
        
        PAdjacency temp = V[u].list;
        while(temp != NULL) // scroll through all of the connecting nodes in adjacency list
        {
            if(V[(temp->pEdge->to)-1].color == WHITE) // if they haven't been visited
            {
                V[(temp->pEdge->to)-1].color = GRAY; // mark as visited
                V[(temp->pEdge->to)-1].d = V[u].d + 1;
                V[(temp->pEdge->to)-1].predecessor = V[u].number;
                queue[rear++] = (temp->pEdge->to)-1; // add to queue for processing
            }
            temp = temp->next;
        }
        V[u].color = BLACK; // mark black as it is finished 
        printf(" %i ", V[u].number); // print finished vertex

    }
    printf("\n");
    

}
