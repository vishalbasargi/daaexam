#include <stdio.h>

#define MAX_VERTICES 10
#define INF 999

void floyd(int n, int W[MAX_VERTICES][MAX_VERTICES], int D[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            D[i][j] = W[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
}

int main() {
    int n, W[MAX_VERTICES][MAX_VERTICES], D[MAX_VERTICES][MAX_VERTICES];
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &W[i][j]);

    floyd(n, W, D);

    printf("\nAll pair shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", D[i][j]);
        printf("\n");
    }

    return 0;
}
