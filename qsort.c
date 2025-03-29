#include <stdio.h>
int part(int a[],int lb, int ub){
  int pivot = a[lb];
  int i=lb+1;
  int j = ub;
  int tmp;
  do{
  while(a[i]<=pivot){
    i++;
  }
  while(a[j]>pivot){
    j--;
  }
  if(i<j){
    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
  }
}while(i<j);

    tmp=a[lb];
    a[lb]=a[j];
    a[j]=tmp;
    return j;
}
void qsort(int arr[],int lb,int ub){
  int pi;
  if(lb<ub){
  pi = part(arr,lb,ub);
  qsort(arr,lb,pi-1);//sort right
  qsort(arr,pi+1,ub);//sort left
  }
}
void printArr(int a[],int n){
  for(int i = 0;i<n;i++){
    printf("%d ",a[i]);
  }
}
int main(){
  int a[]={5,3,6,1,7,10};
  int n=6;
  printArr(a,n);
  printf("\n");
  qsort(a,0,n-1);
  printArr(a,n);
}

