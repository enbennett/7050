#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs4050.h"
#include "BFS.h"

// define node structure
struct node
{
    int number;
    struct node * next;
};

// initalizing front and rear of queue to null
struct node * front = NULL;
struct node * rear = NULL;


// adding nodes to queue
void enqueue(int val)
{
    // create a new node containing the value we are enqueueing 
    struct node * n = malloc(sizeof(struct node));
    n->number = val;
    n->next = NULL;

    if(front == NULL) // if list is empty
    {
        // new node becomes front and rear
        front = n;
        rear = n;
        return;
    }

    // if list is not empty
    rear->next = n; // move rear to new node
    rear = n; // rear is at new node
}

// removing nodes from queue
int dequeue()
{

    if (front == NULL) // if the list is empty
    {
        return -1;
    }
    else // if the list isn't empty
    {
        struct node * ptr = front;
        int num = front->number; // get current head of list number
        front = front->next; // move front to next in line
        free(ptr); // free number we are dequeueing
        return num; // return number to function
    }
}

void printq() //print queue function, used mostly during debugging
{
    // Print numbers
    struct node * ptr = NULL;
    for (ptr = front; ptr != NULL; ptr = front->next)
    {
        printf("%i\n", ptr->number);
    }
    free(ptr);
}


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


    V[u].color = GRAY; // mark gray as we are visiting here first
    enqueue(u);

    while(front != NULL) // while there are items in the queue
    {
        u = dequeue(); // pull head of queue
        
        PAdjacency temp = V[u].list;
        while(temp != NULL) // scroll through all of the connecting nodes in adjacency list
        {
            if(V[(temp->pEdge->to)-1].color == WHITE) // if the to node hasn't been visited
            {
                V[(temp->pEdge->to)-1].color = GRAY; // mark as visited
                V[(temp->pEdge->to)-1].d = V[u].d + 1;
                V[(temp->pEdge->to)-1].predecessor = V[u].number;
                enqueue((temp->pEdge->to)-1); // add to queue
            }
            if(V[(temp->pEdge->from)-1].color == WHITE) // if the from node hasn't been visited (only important for undirected graphs)
            {
                V[(temp->pEdge->from)-1].color = GRAY; // mark as visited
                V[(temp->pEdge->from)-1].d = V[u].d + 1;
                V[(temp->pEdge->from)-1].predecessor = V[u].number;
                enqueue((temp->pEdge->from)-1); // add to queue
            }
            temp = temp->next;

        }
        V[u].color = BLACK; // mark current node as black as it is finished
        printf(" %i ", V[u].number); // print finished vertex
        
    }

    printf("\n");

    
}



