#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    
    for (i = 0; i < n-1; i++) {
        
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        
        
        swap(&arr[min_idx], &arr[i]);
    }
}


void insertionSort(int arr[], int n) {
    int i, key, j;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n);
    
    selectionSort(arr1, n);
    printf("Array sorted with Selection Sort: ");
    printArray(arr1, n);
    
    printf("\nOriginal array: ");
    printArray(arr2, n);
    
    insertionSort(arr2, n);
    printf("Array sorted with Insertion Sort: ");
    printArray(arr2, n);
    
    return 0;
}