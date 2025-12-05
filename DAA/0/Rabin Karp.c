#include<stdio.h>
#include<string.h>
#define d 256

void search(char pattern[], char text[], int q){
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0, t = 0;
    int h = 1;

    for(i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for(i = 0; i < m; i++){
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for(i = 0; i <= n - m; i++){
        if(p == t){
            for(j = 0; j < m; j++){
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j == m)
                printf("Pattern found at index %d\n", i);
        }
    }
}    
        int main(){
    char text[100], pattern[50];
    int q = 97;

    printf("Enter text: ");
    fgets(text, 100, stdin);

    printf("Enter pattern: ");
    fgets(pattern, 50, stdin);

    search(pattern, text, q);
    return 0;
}