#include <stdio.h>
#include <stdlib.h>


struct Item {
    int value;
    int weight;
    float ratio;  
};


int compare(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    return itemB->ratio > itemA->ratio ? 1 : -1;
}


float fractionalKnapsack(int W, struct Item arr[], int n) {
    
    qsort(arr, n, sizeof(struct Item), compare);
    
    
    int currentWeight = 0;
    
    
    float finalValue = 0.0;
    
    
    for (int i = 0; i < n; i++) {
        
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        
        else {
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((float)remainingWeight / arr[i].weight);
            break;
        }
    }
    
    return finalValue;
}

int main() {
    
    int W = 50;   
    
    struct Item arr[] = {
        {60, 10, 0},
        {100, 20, 0},
        {120, 30, 0}
    };
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    
    for (int i = 0; i < n; i++) {
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }
    
    float maxValue = fractionalKnapsack(W, arr, n);
    
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    
    return 0;
}