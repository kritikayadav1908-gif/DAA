#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    int i, words = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        // Check if the current character is a space 
        // and the next character is not space or null
        if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && 
            (str[i + 1] != ' ' && str[i + 1] != '\n' && str[i + 1] != '\t' && str[i + 1] != '\0')) {
            words++;
        }
    }

    // If the string is not empty, add 1 for the first word
    if (strlen(str) > 1)
        words++;

    printf("Number of words = %d\n", words);

    return 0;
}
