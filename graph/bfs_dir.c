#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int start, int end)
{
    graph[start][end] = 1;
    graph[end][start] = 1; 
}

void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex){
    int visited[MAX_VERTICES] = {0}; 
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;
    visited[startVertex] = 1;
    queue[++rear] = startVertex;
    printf("BFS Traversal Order: ");
    while (front != rear){
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);
        for (int i = 0; i < vertices; i++){
            if (graph[currentVertex][i] == 1 && !visited[i]){
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
printf("\n");
}

int main()
{
    int vertices, edges;
    printf("Input the number of vertices: ");
    scanf("%d", &vertices);
    if (vertices <= 0 || vertices > MAX_VERTICES){
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; 
    printf("Input the number of edges: ");
    scanf("%d", &edges);
    if (edges < 0 || edges > vertices * (vertices - 1) / 2){
        printf("Invalid number of edges. Exiting...\n");
        return 1;
    }
    for (int i = 0; i < edges; i++){
        int start, end;
        printf("Input edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);
        if (start < 0 || start >= vertices || end < 0 || end >= vertices){
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }
        addEdge(graph, start, end);
    }  
    int startVertex;
    printf("Input the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);
    BFS(graph, vertices, startVertex);
    return 0;
}

/*
The time complexity of the breadth-first search (BFS) algorithm is O(V + E).

Breadth-first search (BFS) is a graph traversal algorithm that explores all the vertices of a graph in breadth-first order,
 i.e., it explores all the vertices at the present depth before moving on to vertices at the next depth level. 
 The time complexity of BFS is O(V + E),
  where V is the number of vertices and E is the number of edges in the graph.

The BFS algorithm starts at a root node and visits all the adjacent nodes. 
Then for each of those nearest nodes, it explores their unexplored neighbour nodes and so on,
 until it finds the target node. 
 
 BFS uses a queue data structure to keep track of the nodes to be explored.

In terms of time complexity,
 BFS visits each vertex once and traverses each edge once. 
 Therefore, the time complexity is linear in the size of the graph, i.e.,
  the number of vertices plus the number of edges. This is represented as O(V + E).

The 'O' in the time complexity denotes the upper bound of the time required,
 which means the algorithm will not take more time than this.
  'V' represents the number of vertices in the graph.
   As BFS traverses from one node to all its adjacent nodes,
    it visits each vertex once. Hence, 
    'V' is included in the time complexity.

'E' represents the number of edges in the graph. BFS explores each edge once when it checks for a connection from one node to its adjacent node. Therefore, 'E' is also included in the time complexity.

In conclusion, the time complexity of the breadth-first search algorithm is O(V + E), which means it is directly proportional to the size of the graph. This makes BFS a very efficient algorithm for large-scale graph traversal problems.
*/