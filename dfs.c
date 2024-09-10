#include <stdio.h>  
#include <time.h>  
#define MAX 100  

int adj[MAX][MAX], visited[MAX], n;  

void dfs(int start) {  
    printf("%d ", start);  
    visited[start] = 1;  
    for (int i = 0; i < n; i++)  
        if (adj[start][i] && !visited[i])  
            dfs(i);  
}  

int main() {  
    int start;  
    printf("Enter number of lands: ");  
    scanf("%d", &n);  

    printf("Enter adjacency matrix:\n");  
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)  
            scanf("%d", &adj[i][j]);  

    printf("Enter starting land: ");  
    scanf("%d", &start);  
    clock_t start_time = clock();  
    printf("Lands reachable from %d are: ", start);  
    dfs(start);  

    printf("\nTime taken for DFS: %f seconds\n", 
           (double)(clock() - start_time) / CLOCKS_PER_SEC);  

    return 0;  
}

/*Enter number of lands: 5
Enter adjacency matrix:
0 1 1 1 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0 
Enter starting land: 0
Lands reachable from 0 are: 0 1 4 2 3*/
