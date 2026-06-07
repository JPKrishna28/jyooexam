#include "graph_traversal.h"

// Graph creation
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Add edge
void addEdge(Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1; // For undirected graph
}

// ========== DEPTH-FIRST SEARCH (DFS) ==========
void dfsUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] == 1 && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

void dfs(Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS from vertex %d: ", start);
    dfsUtil(graph, start, visited);
    printf("\n");
}

// ========== BREADTH-FIRST SEARCH (BFS) ==========
typedef struct {
    int arr[MAX_VERTICES];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int vertex) {
    if (q->rear < MAX_VERTICES - 1) {
        q->arr[++q->rear] = vertex;
    }
}

int dequeue(Queue* q) {
    if (q->front <= q->rear) {
        return q->arr[q->front++];
    }
    return -1;
}

int isQueueEmpty(Queue* q) {
    return q->front > q->rear;
}

void bfs(Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0};
    Queue* q = createQueue();
    
    visited[start] = 1;
    enqueue(q, start);
    printf("BFS from vertex %d: ", start);
    
    while (!isQueueEmpty(q)) {
        int vertex = dequeue(q);
        printf("%d ", vertex);
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adj[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

// ========== TOPOLOGICAL SORT ==========
void topologicalSortUtil(Graph* graph, int vertex, int visited[], 
                         int stack[], int* stackTop) {
    visited[vertex] = 1;
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] == 1 && !visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, stackTop);
        }
    }
    
    stack[(*stackTop)++] = vertex;
}

void topologicalSort(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stackTop = 0;
    
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackTop);
        }
    }
    
    printf("Topological Sort: ");
    for (int i = stackTop - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// ========== CYCLE DETECTION ==========
int dfsCheckCycle(Graph* graph, int vertex, int visited[], int recStack[]) {
    visited[vertex] = 1;
    recStack[vertex] = 1;
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] == 1) {
            if (!visited[i] && dfsCheckCycle(graph, i, visited, recStack))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }
    
    recStack[vertex] = 0;
    return 0;
}

void detectCycle(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int recStack[MAX_VERTICES] = {0};
    
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            if (dfsCheckCycle(graph, i, visited, recStack)) {
                printf("Cycle detected in graph!\n");
                return;
            }
        }
    }
    printf("No cycle detected in graph!\n");
}

// Demo function
void demo() {
    printf("=== GRAPH TRAVERSAL METHODS ===\n\n");
    
    Graph* graph = createGraph(5);
    
    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    
    printf("Graph Structure:\n");
    printf("Vertices: 0, 1, 2, 3, 4\n");
    printf("Edges: (0-1), (0-2), (1-2), (1-3), (2-4), (3-4)\n\n");
    
    printf("1. DEPTH-FIRST SEARCH (DFS):\n");
    dfs(graph, 0);
    printf("\n");
    
    printf("2. BREADTH-FIRST SEARCH (BFS):\n");
    bfs(graph, 0);
    printf("\n");
    
    printf("3. TOPOLOGICAL SORT:\n");
    topologicalSort(graph);
    printf("\n");
    
    printf("4. CYCLE DETECTION:\n");
    detectCycle(graph);
}

int main() {
    demo();
    return 0;
}
