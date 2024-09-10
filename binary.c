#include <stdio.h>  
#include <time.h>  

int binarySearch(int arr[], int size, int key) {  
    int low = 0, high = size - 1;  
    while (low <= high) {  
        int mid = (low + high) / 2;  
        if (arr[mid] == key) return mid;  
        (arr[mid] < key) ? (low = mid + 1) : (high = mid - 1);  
    }  
    return -1;  
}  
int main() {  
    int n, productID;  
    printf("Enter number of products: ");  
    scanf("%d", &n);  

    int products[n];  
    printf("Enter sorted product IDs:\n");  
    for (int i = 0; i < n; i++) scanf("%d", &products[i]);  

    printf("Enter product ID to search: ");  
    scanf("%d", &productID);  

    clock_t start_time = clock();  
    int result = binarySearch(products, n, productID);  
    printf(result == -1 ? "Product not available\n" : "Product available at index %d\n", result + 1);  
    printf("Time taken: %f seconds\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);  

    return 0;  
}

/*
Enter the number of Products: 10

Sorted Product ID List is:  
 1  2   3   4   5   6   7   10  15  20

Enter the Product ID to be searched: 15
Product found!!
Product 15 found in position 9

Time taken to search is 0.934521
*/
