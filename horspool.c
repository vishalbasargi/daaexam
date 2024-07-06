#include <stdio.h>
#include <string.h>

#define MAX 256

void shifttable(char p[], int t[]) {
    int m = strlen(p);
    for (int i = 0; i < MAX; i++) 
        t[i] = m;
    for (int j = 0; j < m - 1; j++) 
        t[p[j]] = m - 1 - j;
}

int horspool(char src[], char p[], int t[]) {
    int n = strlen(src), m = strlen(p), i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && p[m - 1 - k] == src[i - k]) k++;
        if (k == m) return i - m + 1;
        i += t[src[i]];
    }
    return -1;
}

int main() {
    char src[100], p[100];
    int t[MAX];

    printf("Enter the text:\n");
    scanf("%s", src);

    printf("Enter the pattern:\n");
    scanf("%s", p);

    shifttable(p, t);
    int pos = horspool(src, p, t);

    if (pos >= 0) printf("\nPattern found at position %d\n", pos + 1);
    else printf("\nPattern not found\n");
    return 0;
}
