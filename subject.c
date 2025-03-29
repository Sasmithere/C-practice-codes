#include <stdio.h>
#include "gstio.h"

int main(){
  int avg,sub1,sub2,sub3;
  sub1 = get_int("enter sub 1 marks :");
  sub2 = get_int("enter sub 2 marks :");
  sub3 = get_int("enter sub 3 marks :");
    avg = (sub1+sub2+sub3)/3;
  if (avg >= 90){
    printf("Grade A");
      
  }
  else if(avg>80){
      printf("grade B");
        }
  else
  {
      printf("grade C");
  }
  
  
}