#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1e9

void floydWarshall(int** graph, int n) {
    int i, j, k;
    int** dist = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) free(dist[i]);
    free(dist);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    floydWarshall(graph, n);

    for (int i = 0; i < n; i++) free(graph[i]);
    free(graph);

    return 0;
}