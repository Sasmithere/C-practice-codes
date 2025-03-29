#include <stdio.h>
//bubble
// int main(){
//   int i,j,arr[]={1,2,3,4,5,6},n=6,temp;
//   for(i=0;i<n;i++){
//     for(j=0;j<n-1-i;j++){
//       if(arr[j]>arr[j+1]){
//         temp=arr[j];
//         arr[j]=arr[j+1];
//         arr[j+1]=temp;
//       }
//     }
//   }
//   for(int k=0;k<n;k++){
//     printf("%d ",arr[k]);
//   }
// }
//insertion
// int main(){
//   int i,j,a[]={12,54,65,7,15,72},n=6,temp;
//   for(i=0;i<n;i++){
//     temp=a[i];//54
//     j=i-1;//0
//     while(j>=0 && a[j]>temp){
//       a[j+1]=a[j];
//       j--;
//     }
//     a[j+1]=temp;    
//       }
//   for(int k=0;k<n;k++){
//     printf("%d ",a[k]);  }
// }
//selection
// int main(){
//   int i,j,k,a[]={5,1,3,6,4,2},n=6,temp,min;
//   for(i=0;i<n;i++){
//     min=i;
//     for(j=i+1;j<n;j++){
//       if(a[j]<a[min]){
//         min=j;
//       }
//     }
//     temp=a[i];
//     a[i]=a[min];
//     a[min]=temp;
//   }
//   for(int k=0;k<n;k++){
//     printf("%d ",a[k]);  }
// }