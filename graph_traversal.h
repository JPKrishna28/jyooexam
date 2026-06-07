#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int vertices;
} Graph;

typedef struct {
    int arr[MAX_VERTICES];
    int front, rear;
} Queue;

// ========== GRAPH CREATION ==========
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int u, int v);

// ========== DEPTH-FIRST SEARCH ==========
void dfsUtil(Graph* graph, int vertex, int visited[]);
void dfs(Graph* graph, int start);

// ========== BREADTH-FIRST SEARCH ==========
void bfs(Graph* graph, int start);

// ========== SHORTEST PATH ==========
void dijkstra(Graph* graph, int start);

// ========== UTILITY FUNCTIONS ==========
void displayGraph(Graph* graph);
void displayAdjacencyMatrix(Graph* graph);

#endif // GRAPH_TRAVERSAL_H
