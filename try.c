#include <stdio.h>

// void selectionSort(int arr[], int n){
//   for(int i = 1;i<n;i++){
//     int j=i-1;
//     int temp = arr[i];
//     while(j>=0 && arr[j]>temp){
//       arr[j+1]=arr[j];
//       j--;
//    }
//     arr[j+1]=temp;
//   }
// }

// int main(){
//   int arr[]={10,5,3,8,1,6,2};
//   int n=sizeof(arr)/sizeof(arr[0]);
//   selectionSort(arr,n);
//   for(int i=0;i<n;i++){
//     printf("%d ",arr[i]);
//   }
// }

void swap(int a,int b){
  int temp = a;
  a = b;
  b = temp;
}

void insertionSort(int arr[],int n){
  for(int i=1;i<n;i++){
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
      arr[j + 1] = arr[j];
      j = j - 1;
      }
      arr[j + 1] = key;
    }
  }

int main(){
  int arr[]={10,5,3,8,1,6,2};
  int n=sizeof(arr)/sizeof(arr[0]);
  insertionSort(arr,n);
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);}
}