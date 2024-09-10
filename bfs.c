#include <stdio.h>  
#include <time.h> 
#define MAX 100  
int adj[MAX][MAX], visited[MAX], queue[MAX], front = 0, rear = -1, n;  

void bfs(int start) {  
    visited[start] = 1;   
    queue[++rear] = start;  
    while (front <= rear) {  
        int city = queue[front++];  
        printf("%d ", city);  
        for (int i = 0; i < n; i++)  
            if (adj[city][i] && !visited[i]) 
                queue[++rear] = i, visited[i] = 1;  
    }  }  

int main() {  
    int start;  
    printf("Enter number of cities: ");  
    scanf("%d", &n);  
    printf("Enter adjacency matrix:\n");  
    for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)  
            scanf("%d", &adj[i][j]);  

    printf("Enter starting city: ");  
    scanf("%d", &start);  
    clock_t start_time = clock();  // Start timing  
    printf("Cities reachable from %d are: ", start);  
    bfs(start);  
    printf("\nTime taken for BFS: %f seconds\n", 
           (double)(clock() - start_time) / CLOCKS_PER_SEC);  
    return 0;  
}


/*Enter number of cities: 5
Enter adjacency matrix:
0 1 1 1 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Enter starting city: 0
Cities reachable from 0 are: 0 1 2 3 4
Time taken for BFS: 0.002000 seconds*/
