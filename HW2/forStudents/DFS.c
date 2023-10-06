#include <stdio.h>
#include "cs4050.h"
#include "DFS.h"

void VisitDFS(int time, int i, Vertex * V, int countV, Edge * E, int countE);

void PrintDFS(Vertex * V, int countV, Edge * E, int countE)
{
    // initialize variables
    for(int i=0; i<countV; i++)
    {
        V[i].color = WHITE;
        V[i].d = 0;
        V[i].predecessor = 0;
    }
    int time = 0;

     printf("\nDFS: \n"); // print statement to indicate what search we are printing

     for (int i =0; i<countV; i++)
     {
        if (V[i].color == WHITE) // check if it's been visited
            {
                VisitDFS(time, i, V, countV, E, countE); // use separate visit function we can call recursively
            }
     }
     printf("\n");
}

void VisitDFS(int time, int i, Vertex * V, int countV, Edge * E, int countE)
{
    time = time + 1;   
    V[i].d = time;
    V[i].color = GRAY; // mark gray as we are visiting

    PAdjacency temp = V[i].list;
    while(temp != NULL) // scroll through all of the connecting nodes in adjacency list
    {
        if(V[(temp->pEdge->to)-1].color == WHITE) // if we haven't visited yet
        {
            V[(temp->pEdge->to)-1].predecessor = V[i].number; 
            VisitDFS(time, ((temp->pEdge->to)-1), V, countV, E, countE); // visit and then recursively process so we will get to edge of graph
        }
        temp = temp->next;
    }
    
    time = time + 1;
    V[i].f = time;
    V[i].color = BLACK; // mark black as it is finished
    printf(" %i ", V[i].number); // print finished vertex
}
