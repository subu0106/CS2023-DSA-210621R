#include <iostream>
#include <limits.h>

#define V 6

using namespace std;

void printSolution(int distance[], int src)
{
    cout << endl
         << "Vertex \t\t Distance from Source " << src << endl;
    int average = 0;
    for (int i = 0; i < V; i++)
    {
        average += distance[i] / 5;
        cout << i << " \t\t " << distance[i] << endl;
    }
    cout << endl;
    cout << "Average time : " << average << endl;
}

int minimumDistance(int distance[], bool sptSet[])
{
    int minimum = INT_MAX, minimum_index;

    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && distance[v] <= minimum)
        {
            minimum = distance[v];
            minimum_index = v;
        }
    }

    return minimum_index;
}

void dijkstra(int graph[V][V], int src)
{
    int distance[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    distance[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minimumDistance(distance, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printSolution(distance, src);
}

int main()
{
    int graph[V][V] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};

    dijkstra(graph, 5);

    return 0;
}