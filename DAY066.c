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
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
}

bool isCycleUtil(struct Graph* graph, int v, bool visited[], bool recStack[]) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        struct Node* temp = graph->adjLists[v];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex] && isCycleUtil(graph, adjVertex, visited, recStack)) {
                return true;
            } else if (recStack[adjVertex]) {
                return true;
            }
            temp = temp->next;
        }
    }
    recStack[v] = false; // Remove from recursion stack before backtracking
    return false;
}

bool hasCycle(struct Graph* graph) {
    bool* visited = calloc(graph->numVertices, sizeof(bool));
    bool* recStack = calloc(graph->numVertices, sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++) {
        if (isCycleUtil(graph, i, visited, recStack)) {
            free(visited);
            free(recStack);
            return true;
        }
    }

    free(visited);
    free(recStack);
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