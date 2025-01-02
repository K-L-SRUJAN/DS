#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX] = {0};

void dfs(int graph[MAX][MAX], int start, int n) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] && !visited[i]) {
            dfs(graph, i, n);
        }
    }
}

int main() {
    int n, start, graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(graph, start, n);
    return 0;
}
