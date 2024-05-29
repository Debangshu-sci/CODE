#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define N 5

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
{   printf("Edge \tWeight\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\t----\t%d\n", i, dist[i]);
    }
    printf("\n");
}

void DijKastra(int adj[][N], int source)
{
    int dist[N];
    int parent[N];
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
            if (!sptSet[v] && adj[u][v] && dist[u] != INT_MAX && adj[u][v] < dist[v])
            {
                dist[v] =  adj[u][v];
                parent[v]=u;
            }
        }
    }
    PrintSol(dist);
}
int main()
{
    int adj[][N] =
        {
            { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
            
            
            
            
            
            
            
            
    DijKastra(adj,3);
    return 0;
}