#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int v, int adj[MAX][MAX], int n_adj[MAX]) {
    int in_degree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int topo_order[MAX];
    int count = 0;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < n_adj[i]; j++) {
            int neighbor = adj[i][j];
            in_degree[neighbor]++;
        }
    }

    for (int i = 0; i < v; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        for (int i = 0; i < n_adj[u]; i++) {
            int neighbor = adj[u][i];
            in_degree[neighbor]--;

            if (in_degree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    if (count != v) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int v = 6;
    int adj[MAX][MAX];
    int n_adj[MAX] = {0}; 


    adj[5][n_adj[5]++] = 2;
    adj[5][n_adj[5]++] = 0;

    adj[4][n_adj[4]++] = 0;
    adj[4][n_adj[4]++] = 1;
    adj[2][n_adj[2]++] = 3;
 
    adj[3][n_adj[3]++] = 1;

    topologicalSort(v, adj, n_adj);

    return 0;
}