#include <stdio.h>
#include "gstio.h"
void printArr(int arr[],n){
  for(int i = 0;i<n;i++){
    printf("%d ",arr[i]);
  }
}
int main(){
  int a[]={1,2,3,4,5,6},n=6;
  printArr(a,n);
}