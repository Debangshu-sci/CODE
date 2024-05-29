#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define N 9

int GetMin(int dist[], bool sptSet[])
{
    int min = INT_MAX;
    int min_Index;
    for (int i = 0; i < N; i++)
    {
        if (!sptSet[i] && dist[i] < min)
        {
            min = dist[i];
            min_Index = i;
        }
    }
    return min_Index;
}
void PrintSol(int dist[])
{
    for (int i = 0; i < N; i++)
    {
        printf("%d\t\t\t%d\n", i, dist[i]);
    }
    printf("\n");
}
void DijKastra(int adj[][N], int source)
{
    int dist[N];
    bool sptSet[N];
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[source] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int u = GetMin(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < N; v++)
        {
            if (!sptSet[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    PrintSol(dist);
}
int main()
{
    int adj[][N] =
        {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 3, 0, 4, 0, 0, 2},
            {0, 0, 3, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    DijKastra(adj,3);
    return 0;
}