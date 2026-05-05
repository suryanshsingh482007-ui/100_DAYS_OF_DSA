#include <stdio.h>
#include <stdlib.h>

void buildGraph() {
    int n, m, directed;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);

    // Dynamic allocation of 2D array initialized to 0
    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Check for valid bounds (assuming 0 to n-1 indexing)
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
            if (!directed) {
                adj[v][u] = 1; // Symmetric for undirected
            }
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
}

int main() {
    buildGraph();
    return 0;
}