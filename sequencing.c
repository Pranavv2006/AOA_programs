#include <stdio.h>
#include <stdlib.h>


struct Job {
    char id;     
    int deadline; 
    int profit;   
};


int compareJobs(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}


int min(int a, int b) {
    return (a < b) ? a : b;
}


void scheduleJobs(struct Job jobs[], int n) {
    
    qsort(jobs, n, sizeof(struct Job), compareJobs);
    
    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    
    
    char result[maxDeadline + 1];
    
    for (int i = 0; i <= maxDeadline; i++) {
        result[i] = '-';
    }
    
    
    for (int i = 0; i < n; i++) {
        
        for (int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {
            
            if (result[j] == '-') {
                result[j] = jobs[i].id;
                break;
            }
        }
    }
    
    
    printf("Scheduled Jobs: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (result[i] != '-') {
            printf("%c ", result[i]);
        }
    }
    printf("\n");
    
    
    int totalProfit = 0;
    for (int i = 1; i <= maxDeadline; i++) {
        if (result[i] != '-') {
            for (int j = 0; j < n; j++) {
                if (jobs[j].id == result[i]) {
                    totalProfit += jobs[j].profit;
                    break;
                }
            }
        }
    }
    printf("Total profit: %d\n", totalProfit);
}

int main() {
    
    struct Job jobs[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    
    printf("Job scheduling to maximize profit:\n");
    scheduleJobs(jobs, n);
    
    return 0;
}