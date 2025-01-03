#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_words(char *str) {
    char *words[100];
    int word_count = 0;
    char *token = strtok(str, " ,.");
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, " ,.");
    }
    
    for (int i = 0; i < word_count / 2; i++) {
        char *temp = words[i];
        words[i] = words[word_count - 1 - i];
        words[word_count - 1 - i] = temp;
    }
    
    for (int i = 0; i < word_count; i++) {
        printf("%s", words[i]);
        if (i < word_count - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char str[] = "Hello, world. This is a test.";
    reverse_words(str);
    return 0;
}
