#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int to;
    int weight;
    struct Node* next;
} Node;

void add_edge(Node** adj, int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->to = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(adj, u, v, w);
        add_edge(adj, v, u, w);
    }

    int* min_dist = (int*)malloc((n + 1) * sizeof(int));
    bool* visited = (bool*)calloc(n + 1, sizeof(bool));
    for (int i = 0; i <= n; i++) min_dist[i] = INT_MAX;

    int total_weight = 0;
    min_dist[1] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int min_val = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && min_dist[j] < min_val) {
                min_val = min_dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;
        total_weight += min_val;

        Node* curr = adj[u];
        while (curr) {
            if (!visited[curr->to] && curr->weight < min_dist[curr->to]) {
                min_dist[curr->to] = curr->weight;
            }
            curr = curr->next;
        }
    }

    printf("%d\n", total_weight);

    for (int i = 1; i <= n; i++) {
        Node* curr = adj[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(adj);
    free(min_dist);
    free(visited);

    return 0;
}