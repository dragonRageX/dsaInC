#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   //header file to use the boolean data-type
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

///FOR WEIGHTED BI-DIRECTIONAL GRAPH

int vertices = 6;   //no.of vertices in the graph

void printSolution(int distanceFromSource[])
{
    for (int i = 0; i < vertices; i++)
    {
        printf("%d \n", distanceFromSource[i]);
    }
}

int nextParentNode(int graph[6][6], bool visitedVertices[], int u)
{
    int max = 0;
    int maxElementIndex;
    for(int i = 0; i < vertices; i++)
    {
        if(visitedVertices[i] == false && graph[u][i] > max)
        {
            max = graph[u][i];
            maxElementIndex = i;
        }
    }
    return maxElementIndex;
}

void dijkstra(int graph[6][6], int source)
{
    int distanceFromSource[6];
    for(int i = 0; i < vertices; i++)
    {
        distanceFromSource[i] = 100000;   //a very large value
    }
    distanceFromSource[source] = 0;
    bool visitedVertices[6];
    for(int i = 0; i < vertices; i++)
    {
        visitedVertices[i] = false;
    }
    int u = source;   //parent index
    visitedVertices[u] = true;
    for(int i = 1; i < vertices; i++)
    {
        //relaxation
        for(int v = 0; v < vertices; v++)
        {
            if(graph[u][v] > 0)   //immediate neighbours of u
            {
                distanceFromSource[v] = MIN(distanceFromSource[u] + graph[u][v], distanceFromSource[v]);
            }
        }
        //next neighbour
        u = nextParentNode(graph, visitedVertices, u);
        visitedVertices[u] = true;
    }

    printSolution(distanceFromSource);
}

int main()
{
    int graph[6][6] = {{0,4,5,0,0,0},
                       {4,0,11,9,7,0},
                       {5,11,0,0,3,0},
                       {0,9,0,0,13,2},
                       {0,7,3,13,0,6},
                       {0,0,0,2,6,0}};   //6 vertices in the graph
    int source = 0;   //source node: A
    dijkstra(graph, source);

    return 0;
}

///ALTERNATE APPROACH: (RECOMMENDED)
/*
#include <limits.h>
#define V 6 // Number of vertices in the graph

//Function to find the vertex with minimum distance
int minDist(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

//Function to print the constructed distance array
void printSolution(int distance[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << (char)(i+65) << " \t\t"<<distance[i]<< endl;
}

// Function that implements Dijkstra's algorithm
void dijkstra(int graph[V][V], int src)
{
    int distance[V]; //inititalizing output array

    bool sptSet[V]; // list of visisted nodes

    // Initializing all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX, sptSet[i] = false;

    // Setting distance of source as 0
    distance[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {

        //calling minDistance to pick next vertex
        int u = minDist(distance, sptSet);

        // Mark the picked vertex as visited
        sptSet[u] = true;

        //Relaxing all neighbours of U
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver function
int main()
{

    //Example graph
    //Same as Graph in example diagram above

    int graph[V][V] = { {0,4,5,0,0,0},
                        {4,0,11,9,7,0},
                        {5,11,0,0,3,0},
                        {0,9,0,0,13,2},
                        {0,7,3,13,0,6},
                        {0,0,0,2,6,0}};
     int source=0;
    dijkstra(graph, source);

    return 0;
}*/
