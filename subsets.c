#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100


void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}


void findSubsets(int set[], int n, int subset[], int subSize, int index, 
                 int sum, int targetSum, int remainingSum) {
    
    
    if (sum == targetSum) {
        printSubset(subset, subSize);
        return;
    }
    
    
    
    
    
    if (index == n || sum > targetSum || (sum + remainingSum < targetSum)) {
        return;
    }
    
    
    subset[subSize] = set[index];
    findSubsets(set, n, subset, subSize + 1, index + 1, 
                sum + set[index], targetSum, remainingSum - set[index]);
    
    
    findSubsets(set, n, subset, subSize, index + 1, 
                sum, targetSum, remainingSum - set[index]);
}


void sumOfSubsets(int set[], int n, int targetSum) {
    
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += set[i];
    }
    
    
    int subset[MAX_SIZE];
    
    printf("Subsets with sum %d:\n", targetSum);
    findSubsets(set, n, subset, 0, 0, 0, targetSum, totalSum);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 35;
    
    sumOfSubsets(set, n, targetSum);
    
    return 0;
}