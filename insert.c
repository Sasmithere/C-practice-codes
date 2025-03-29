#include <stdio.h>

void printArr(int a[],int n){
  for(int i = 0;i<n;i++){
    printf("%d ",a[i]);
  }
}

int main(void){
  int arr[]= {12, 11, 13, 5, 6},key=0,j;
  printArr(arr,5);
  for(int i=0;i<5;i++){
    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
    
  }
  printf("\n");
  printArr(arr,5);
}