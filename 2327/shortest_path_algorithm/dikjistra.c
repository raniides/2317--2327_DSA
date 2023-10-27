#include <stdio.h>
#include <limits.h>

#define V 6

void dijkstra(int graph[V][V], int src) {
    int dist[V], sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V];
    int src;

    printf("Enter the graph matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
