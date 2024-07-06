#include <stdio.h>

int max(int x, int y) { 
    return (x > y) ? x : y; 
}

void printTable(int n, int m, int v[][10]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%4d ", v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void knap(int n, int w[], int value[], int m, int v[][10]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j < w[i]) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], value[i] + v[i - 1][j - w[i]]);
            }
        }
    }
    printf("Final DP table after processing all items:\n");
    printTable(n, m, v); // Print the final table
}

int main() {
    int n, w[10], value[10], m, v[10][10];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of %d items:\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter values of %d items:\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &m);

    knap(n, w, value, m, v);

    printf("\nOptimal knapsack solution: %d\n", v[n][m]);
    return 0;
}
