#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int arr[] = {5, 3, 1, 2, 6}, size = 5, temp;
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  // bubble sort
  // for(int i=0;i<size;i++){
  //   for(int j=0;j<size;j++){
  //     if(arr[i]<arr[j]){
  //       temp=arr[i];
  //       arr[i]=arr[j];
  //       arr[j]=temp;
  //     }
  //   }
  // }

  // selection sort
  // int min=0;
  // for(int i=0;i<size-1;i++){
  //   min=i;
  //   for(int j=i+1;j<size;j++){
  //   if(arr[j]<arr[min]){
  //       min=j;}
  //   if(min!=i){
  //       temp=min;
  //       min=arr[i];
  //       arr[i]=temp;}

  //   }
  // }
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < size - 1; i++) {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < size; j++)
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }

    // Swap the found minimum element with the first element
    if (min_idx != i) {
      swap(&min_idx, &i);
    }
  }

  printf("\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}