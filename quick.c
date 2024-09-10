#include <stdio.h> 
#include <stdlib.h>  
#include <time.h>  

int partition(int a[], int low, int high) {  
    int pivot = a[low], i = low + 1, j = high;  
    while (1) {  
        while (i <= high && a[i] <= pivot) i++;  
        while (j > low && a[j] > pivot) j--;  
        if (i < j) { int temp = a[i]; a[i] = a[j]; a[j] = temp; }  
        else { a[low] = a[j]; a[j] = pivot; return j; }  
    }  }  

void quick_sort(int a[], int low, int high) {  
    if (low < high) {  
        int j = partition(a, low, high);  
        quick_sort(a, low, j - 1);  
        quick_sort(a, j + 1, high);  
    }  }  

int main() {  
    int n, a[200000];  
    printf("Enter number of student records: ");  
    scanf("%d", &n);  
    if (n > 200000) return 1; // Error check

    srand(time(NULL));  
    for (int i = 0; i < n; i++) a[i] = rand() % 100;  
    printf("Roll numbers: ");  
    for (int i = 0; i < n; i++) printf("%d ", a[i]);  

    clock_t start = clock();  
    quick_sort(a, 0, n - 1);  
    printf("\nSorted roll numbers: ");  
    for (int i = 0; i < n; i++) printf("%d ", a[i]);  
    printf("\nRun time: %f seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);  

    return 0;  
}
