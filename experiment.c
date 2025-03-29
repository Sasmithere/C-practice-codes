//to read input while execution 
#include <stdio.h> 
#include "gstio.h" 
int main(void) {
    int a, b; // variable declaration 
    // read input while program execution 
    a = get_int("Enter the value of a\t"); 
    b = get_int("Enter the value of b\t"); 
    printf("The values of a and b are %d %d\n", a, b);
}
