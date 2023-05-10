#include <stdio.h>
#include <stdlib.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int vertices = 5;   //no.of vertices in the graph

void printSolution(int distanceFromSource[])
{
    for (int i = 0; i < vertices; i++)
    {
        printf("%d \n", distanceFromSource[i]);
    }
}

int nextParentNode(int graph[5][5], int u)   //a slightly different way of selecting the next parent node: finding the neighbor vertex with the least edge weight of all neighboring vertices
{
    int min = 100000;
    int minElementIndex;
    for(int i = 0; i < vertices; i++)
    {
        if(graph[u][i] < min/* && graph[u][i] != 100000*/)
        {
            min = graph[u][i];
            minElementIndex = i;
        }
    }
    return minElementIndex;
}

void bellmanFord(int graph[5][5], int source)
{
    int distanceFromSource[5];
    for(int i = 0; i < vertices; i++)
    {
        distanceFromSource[i] = 100000;
    }
    distanceFromSource[source] = 0;
    int u = source;   //parent index
    //relaxation
    for(int i = 1; i < vertices; i++)   //the shortest path from the source to any other vertex can have at most |vertices| - 1 edges
    {
        for(int v = 0; v < vertices; v++)
        {
            if(graph[u][v] != 100000)   //only the immediate neighbours of the parent
            {
                distanceFromSource[v] = MIN(distanceFromSource[u] + graph[u][v], distanceFromSource[v]);
            }
        }
        u = nextParentNode(graph, u);
    }
    //step-3: check for negative-weight cycles
    for(int u = 0; u < vertices; u++)
    {
        for(int v = 0; v < vertices; v++)
        {
            if(distanceFromSource[u] + graph[u][v] < distanceFromSource[v])
            {
                //distanceFromSource[v] = distanceFromSource[u] + graph[u][v];
                printf("There exists a negative weight cycle in the Graph!");
                //printSolution(distanceFromSource);
                return;
            }
        }
    }
    printSolution(distanceFromSource);
}

int main()
{
    int graph[5][5] = {{0, -1, 4, 100000, 100000},   //the very large value (100000) signifies that that vertex is not directly connected to a particular vertex
                       {100000, 0, 3, 2, 2},
                       {100000, 100000, 0, 100000, 100000},
                       {100000, 1, 5, 0, 100000},
                       {100000, 100000, 100000, -3, 0}};   //5 vertices in the graph
    int source = 0;   //source node: A
    bellmanFord(graph, source);

    return 0;
}
