#include <stdio.h>
#include <ctype.h>   

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // read input including spaces

    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {   // check if character is lowercase
            str[i] = toupper(str[i]);
        }
    }

    printf("String in uppercase: %s", str);

    return 0;
}
