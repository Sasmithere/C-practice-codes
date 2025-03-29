//scope of variable 
#include <stdio.h> 
#include "gstio.h"
int b=50; 
int nopemain(){
  int a=20, b=60;
  {
    int a=30, b=40;
    printf("The value of a = %d and b = %d of inner block and their sum is %d\n", a, b, a+b);
  }
    
  printf("The value of a = %d and b = %d of outer block and their sum is  %d\n", a, b, a+b);
}