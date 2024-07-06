#include <stdio.h>

typedef struct { int u, v, cost; } edge;

int find(int v, int parent[]) {
    while (parent[v] != v) v = parent[v];
    return v;
}

void union_ij(int i, int j, int parent[]) {
    parent[j] = i;
}

void kruskal(int n, edge e[], int m) {
    int count = 0, k = 0, sum = 0, t[10][2], parent[10];
    edge temp;

    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - 1 - i; j++)
            if (e[j].cost > e[j + 1].cost) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }

    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; count != n - 1 && i < m; i++) {
        int u = e[i].u, v = e[i].v;
        int root_u = find(u, parent), root_v = find(v, parent);

        if (root_u != root_v) {
            t[k][0] = u; t[k][1] = v; k++; count++; sum += e[i].cost;
            union_ij(root_u, root_v, parent);
        }
    }

    if (count == n - 1) {
        printf("Spanning tree exists\nThe spanning tree is:\n");
        for (int i = 0; i < n - 1; i++) printf("%d  %d\t", t[i][0], t[i][1]);
        printf("\nCost of the spanning tree: %d\n", sum);
    } else {
        printf("\nSpanning tree does not exist\n");
    }
}

int main() {
    int n, m;
    edge e[20];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edge list (u v cost):\n");
    for (int i = 0; i < m; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].cost);

    kruskal(n, e, m);

    return 0;
}
