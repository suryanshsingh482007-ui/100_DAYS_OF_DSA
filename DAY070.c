#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct HeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    struct HeapNode** array;
};

struct Node* createNode(int v, int weight) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = weight;
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

void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* heapNode = malloc(sizeof(struct HeapNode));
    heapNode->v = v;
    heapNode->dist = dist;
    return heapNode;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct HeapNode* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i;
    for (i = 0; i < minHeap->size; ++i) {
        if (minHeap->array[i]->v == v) break;
    }
    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(struct MinHeap* minHeap, int v) {
    for (int i = 0; i < minHeap->size; i++) {
        if (minHeap->array[i]->v == v) return true;
    }
    return false;
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->numVertices;
    int dist[V];
    struct MinHeap* minHeap = malloc(sizeof(struct MinHeap));
    minHeap->capacity = V;
    minHeap->size = V;
    minHeap->array = malloc(V * sizeof(struct HeapNode*));

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v] = newHeapNode(v, dist[v]);
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    while (minHeap->size != 0) {
        struct HeapNode* heapNode = extractMin(minHeap);
        int u = heapNode->v;

        struct Node* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
        free(heapNode);
    }

    for (int i = 0; i < V; ++i) printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int n = 5;
    struct Graph* graph = createGraph(n);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 3);

    dijkstra(graph, 0);

    return 0;
}