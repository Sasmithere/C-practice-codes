#include <stdio.h>
#include "gstio.h"

int main(){
  int a , b , c ;
  a=get_int("enter side a:");
  b=get_int("enter side b:");
  c=get_int("enter side c:");

  if ((a==0) || (b==0) || (c==0))
  {
    printf("triangle not possible");
    }
  
   else if ((a==b) && (a==c)){
    printf("equilateral triangle");
    }
  else if ((a==b && a != c) || (a==c && a!=b) || (b==c && c != a))
    {
    printf("isoceles triangle");
    }
  else if (a+b>c || a+c>b || b+c>a)
  {
    printf("scalene triangle");
  }
    
  else 
  {
    printf("triangle not possible");
  }
  }


  