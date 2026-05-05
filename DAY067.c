#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
}

void topoSortUtil(int v, bool visited[], int stack[], int* stackIdx, struct Graph* graph) {
    visited[v] = true;

    struct Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            topoSortUtil(connectedVertex, visited, stack, stackIdx, graph);
        }
        temp = temp->next;
    }

    stack[(*stackIdx)++] = v;
}

void topologicalSort(struct Graph* graph) {
    int* stack = malloc(graph->numVertices * sizeof(int));
    int stackIdx = 0;
    bool* visited = malloc(graph->numVertices * sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++) visited[i] = false;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            topoSortUtil(i, visited, stack, stackIdx, graph);
        }
    }

    printf("Topological Order: ");
    while (stackIdx > 0) {
        printf("%d ", stack[--stackIdx]);
    }
    printf("\n");

    free(stack);
    free(visited);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}