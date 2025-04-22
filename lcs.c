#include <stdio.h>
#include <string.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}


void lcs(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    
    
    int L[m+1][n+1];
    
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    
    int lcsLength = L[m][n];
    printf("Length of LCS: %d\n", lcsLength);
    
    
    char lcsString[lcsLength + 1];
    lcsString[lcsLength] = '\0';
    
    
    int i = m, j = n;
    int index = lcsLength - 1;
    
    while (i > 0 && j > 0) {
        
        if (X[i-1] == Y[j-1]) {
            lcsString[index] = X[i-1];
            i--;
            j--;
            index--;
        }
        
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    
    
    printf("LCS: %s\n", lcsString);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    printf("String 1: %s\n", X);
    printf("String 2: %s\n", Y);
    
    lcs(X, Y);
    
    return 0;
}