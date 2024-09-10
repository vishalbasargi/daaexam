#include <stdio.h>  
#include <time.h>  

void merge(int arr[], int l, int m, int r) {  
    int n1 = m - l + 1, n2 = r - m, L[n1], R[n2];  
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];  
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];  

    for (int i = 0, j = 0, k = l; k <= r; k++) {  
        if (j == n2 || (i < n1 && L[i] <= R[j])) arr[k] = L[i++];  
        else arr[k] = R[j++];  
    }  }  
void mergeSort(int arr[], int l, int r) {  
    if (l < r) {  
        int m = l + (r - l) / 2;  
        mergeSort(arr, l, m);  
        mergeSort(arr, m + 1, r);  
        merge(arr, l, m, r);  
    }  }  
int main() {  
    int n;  
    printf("Enter number of employees: ");  
    scanf("%d", &n);  
    int ids[n];  

    printf("Enter employee IDs:\n");  
    for (int i = 0; i < n; i++) {  
        printf("ID for Employee %d: ", i + 1);  
        scanf("%d", &ids[i]);  
    }  

    clock_t start_time = clock();  
    mergeSort(ids, 0, n - 1);  
    double time_taken = (double)(clock() - start_time) / CLOCKS_PER_SEC;  

    printf("Sorted employee IDs:\n");  
    for (int i = 0; i < n; i++) printf("%d\n", ids[i]);  
    printf("Time taken for sorting: %f seconds\n", time_taken);  
    return 0;  
}
