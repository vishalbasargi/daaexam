#include <stdio.h>

int count = 0, w[10], d, x[10];

void subset(int cs, int k, int r) {
    if (cs == d) {
        printf("\nSubset solution = %d\n", ++count);
        for (int i = 0; i < k; i++)
            if (x[i]) printf("%d\n", w[i]);
        return;
    }
    if (k < 10) {
        if (cs + w[k] <= d) {
            x[k] = 1;
            subset(cs + w[k], k + 1, r - w[k]);
        }
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
}

int main() {
    int n, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("Enter required sum: ");
    scanf("%d", &d);

    if (sum < d) {
        printf("No solution exists.\n");
    } else {
        printf("The solution is:\n");
        subset(0, 0, sum);
    }
    return 0;
}
