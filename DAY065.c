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
    int* visited;
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
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
    
    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

bool isCycleRecursive(struct Graph* graph, int v, int parent) {
    graph->visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!graph->visited[adjVertex]) {
            if (isCycleRecursive(graph, adjVertex, v))
                return true;
        }
        // If an adjacent vertex is visited and not the parent, cycle exists
        else if (adjVertex != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool hasCycle(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (isCycleRecursive(graph, i, -1))
                return true;
        }
    }
    return false;
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

    if (hasCycle(graph))
        printf("Graph contains a cycle\n");
    else
        printf("Graph doesn't contain a cycle\n");

    return 0;
}