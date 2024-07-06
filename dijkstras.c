#include <stdio.h>

#define MAX 10
#define INF 999

int choose(int dist[], int s[], int n) {
    int min = INF, j = -1;
    for (int w = 1; w <= n; w++) {
        if (dist[w] < min && !s[w]) {
            min = dist[w];
            j = w;
        }
    }
    return j;
}

void shortest_path(int v, int cost[][MAX], int dist[], int n) {
    int s[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        dist[i] = cost[v][i];
    }
    s[v] = 1;
    dist[v] = 0;

    for (int num = 2; num <= n; num++) {
        int u = choose(dist, s, n);
        s[u] = 1;
        for (int w = 1; w <= n; w++) {
            if (!s[w] && (dist[u] + cost[u][w] < dist[w])) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int cost[MAX][MAX], dist[MAX], n, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &v);

    shortest_path(v, cost, dist, n);

    printf("\nShortest distances from vertex %d:\n", v);
    for (int i = 1; i <= n; i++) {
        printf("%d to %d = %d\n", v, i, dist[i]);
    }

    return 0;
}
