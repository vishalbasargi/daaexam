#include <stdio.h>  
#include <time.h>  

void heapify(int h[], int n, int i) {  
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;  
    if (left < n && h[left] > h[largest]) largest = left;  
    if (right < n && h[right] > h[largest]) largest = right;  
    if (largest != i) {  
        int temp = h[i]; h[i] = h[largest]; h[largest] = temp;  
        heapify(h, n, largest);  
    }  }  

void heapsort(int h[], int n) {  
    for (int i = n / 2 - 1; i >= 0; i--) heapify(h, n, i);  
    for (int i = n - 1; i > 0; i--) {  
        int temp = h[0]; h[0] = h[i]; h[i] = temp;  
        heapify(h, i, 0);  
    }  }  

int main() {  
    int n, h[20];  
    printf("Enter number of resumes: ");  
    scanf("%d", &n);  
    if (n > 20) return 1;  
   printf("Enter resumes: ");  
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);  

    clock_t start = clock();  
    heapsort(h, n);  
    printf("Sorted ranks:\n");  
    for (int i = 0; i < n; i++) printf("%d\t", h[i]);  
    printf("\nRun time: %f seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);  

    return 0;  
}
