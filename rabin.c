#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#define d 256 

void search(char pat[], char txt[], int q) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0; 
    int t = 0; 
    int h = 1; 
    int found = 0; 
    
    for (i = 0; i < M - 1; i++) 
        h = (h * d) % q; 
        
    for (i = 0; i < M; i++) { 
        p = (d * p + pat[i]) % q; 
        t = (d * t + txt[i]) % q; 
    } 
    
    for (i = 0; i <= N - M; i++) { 
        if (p == t) { 
            for (j = 0; j < M; j++) { 
                if (txt[i + j] != pat[j]) 
                    break; 
            } 
            
            if (j == M) {
                printf("Pattern found at index %d\n", i);
                found = 1;
            }
        } 
        
        if (i < N - M) { 
            t = (d * (t - txt[i] * h) + txt[i + M]) % q; 
            
            if (t < 0) 
                t = (t + q); 
        } 
    }
    
    if (!found) {
        printf("Pattern not found in the text\n");
    }
} 

int main() 
{ 
    char *txt = NULL;
    char *pat = NULL;
    int q = 101; 
    size_t txt_size = 0;
    size_t pat_size = 0;
    
    printf("Enter the text: ");
    getline(&txt, &txt_size, stdin);
    size_t txt_len = strlen(txt);
    if (txt[txt_len - 1] == '\n') {
        txt[txt_len - 1] = '\0';
    }
    
    printf("Enter the pattern to search: ");
    getline(&pat, &pat_size, stdin);
    size_t pat_len = strlen(pat);
    if (pat[pat_len - 1] == '\n') {
        pat[pat_len - 1] = '\0';
    }
    
    search(pat, txt, q);
    
    free(txt);
    free(pat);
    
    return 0; 
}