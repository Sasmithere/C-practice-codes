#include <stdio.h>
#include <string.h>

int is_substring(const char *str1, const char *str2) {
    return strstr(str1, str2) != NULL;
}

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "world";
    
    if (is_substring(str1, str2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    
    char str3[] = "python";
    
    if (is_substring(str1, str3)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    
    return 0;
}

