#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  



void insertionSort(long long arr[], int n) {  
    for (int i = 1; i < n; i++) {  
        long long key = arr[i];  
        int j = i - 1;  
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];  
        arr[j + 1] = key;  
    }  }  
    
int main() {  
    int n;  
    printf("Enter number of phone numbers: ");  
    scanf("%d", &n);  
    long long phones[n];  

    srand(time(0));  
    for (int i = 0; i < n; i++)  
        phones[i] = (7 + rand() % 3) * 1000000000LL + rand() % 100000000;  

    clock_t start_time = clock();  
    insertionSort(phones, n);  
    printf("Sorted phone numbers:\n");  
    for (int i = 0; i < n; i++) printf("%lld\n", phones[i]);  
    printf("Time taken: %f seconds\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);  

    return 0;  
}
