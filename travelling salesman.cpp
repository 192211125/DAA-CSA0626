#include <stdio.h>
#include <stdlib.h>
int min(int x, int y) {
    return (x < y) ? x : y;
}
int tsp(int **graph, int V, int start) {
    int **dp = (int **)malloc((1 << V) * sizeof(int *));
    for (int i = 0; i < (1 << V); i++) {
        dp[i] = (int *)malloc(V * sizeof(int));
    }
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }
    dp[1][start] = 0;
    for (int mask = 1; mask < (1 << V); mask++) {
        for (int j = 0; j < V; j++) {
            if (mask & (1 << j)) {
                for (int k = 0; k < V; k++) {
                    if (!(mask & (1 << k))) {
                        if (dp[mask][j] != -1) {
                            if (dp[mask | (1 << k)][k] == -1) {
                                dp[mask | (1 << k)][k] = dp[mask][j] + graph[j][k];
                            } else {
                                dp[mask | (1 << k)][k] = min(dp[mask | (1 << k)][k], dp[mask][j] + graph[j][k]);
                            }
                        }
                    }
                }
            }
        }
    }
    int minCost = -1;
    for (int i = 0; i < V; i++) {
        if (dp[(1 << V) - 1][i] != -1) {
            if (minCost == -1 || minCost > dp[(1 << V) - 1][i] + graph[i][start]) {
                minCost = dp[(1 << V) - 1][i] + graph[i][start];
            }
        }
    }
    for (int i = 0; i < (1 << V); i++) {
        free(dp[i]);
    }
    free(dp);
    return minCost;
}
int main() {
    int V;
    printf("Enter the number of cities: ");
    scanf("%d", &V);
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int start = 0; start < V; start++) {
        int minCost = tsp(graph, V, start);
        printf("Minimum cost for the Traveling Salesman Problem starting from city %d is: %d\n", start, minCost);
    }
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
