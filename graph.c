#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printSolution(int *color, int V);
bool isSafe(int v, bool **graph, int *color, int c, int V);
bool graphColoringUtil(bool **graph, int m, int *color, int v, int V);
bool graphColoring(bool **graph, int m, int V);
bool **createGraph(int V);
void freeGraph(bool **graph, int V);

bool isSafe(int v, bool **graph, int *color, int c, int V)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool **graph, int m, int *color, int v, int V)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {

        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1, V))
                return true;

            color[v] = 0;
        }
    }
    
    return false;
}

bool graphColoring(bool **graph, int m, int V)
{
    int *color = (int *)malloc(V * sizeof(int));
    if (color == NULL) {
        printf("Memory allocation failed\n");
        return false;
    }
    
    for (int i = 0; i < V; i++)
        color[i] = 0;

    bool result = graphColoringUtil(graph, m, color, 0, V);
    
    if (result == false) {
        printf("Solution does not exist\n");
        free(color);
        return false;
    }

    printSolution(color, V);
    free(color);
    return true;
}

void printSolution(int *color, int V)
{
    printf("Solution Exists: Following are the assigned colors\n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

bool **createGraph(int V)
{
    bool **graph = (bool **)malloc(V * sizeof(bool *));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    for (int i = 0; i < V; i++) {
        graph[i] = (bool *)malloc(V * sizeof(bool));
        if (graph[i] == NULL) {
            printf("Memory allocation failed\n");
            for (int j = 0; j < i; j++)
                free(graph[j]);
            free(graph);
            return NULL;
        }
    }
    
    return graph;
}

void freeGraph(bool **graph, int V)
{
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);
}

int main()
{
    int V, m, i, j;
    
    printf("Enter number of vertices (V): ");
    scanf("%d", &V);
    
    if (V <= 0) {
        printf("Invalid number of vertices\n");
        return 1;
    }
    
    bool **graph = createGraph(V);
    if (graph == NULL) {
        return 1;
    }
    
    printf("Enter the adjacency matrix (%d x %d) with 0s and 1s:\n", V, V);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            int value;
            scanf("%d", &value);
            graph[i][j] = (value == 1);
        }
    }
    
    printf("Enter number of colors (m): ");
    scanf("%d", &m);
    
    if (m <= 0) {
        printf("Invalid number of colors\n");
        freeGraph(graph, V);
        return 1;
    }
    
    graphColoring(graph, m, V);
    
    freeGraph(graph, V);
    
    return 0;
}