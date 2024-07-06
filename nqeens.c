#include <stdio.h>
#include <stdlib.h>

int x[20];

int place(int k, int i) {
    for (int j = 1; j < k; j++)
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    return 1;
}

void nqueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (int a = 1; a <= n; a++)
                    printf("%d\t", x[a]);
                printf("\n");
            } else {
                nqueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    nqueens(1, n);
    return 0;
}
