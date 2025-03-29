#include "stdio.h"
//WAC that reads numbers from input and stops processing after reading number 42
// int main() {
//   int a=1;
//   while(a!=42){
//     printf("Enter a number:");
//     scanf("%d",&a);

//   }
//   printf("you entered 42");

//   return 0;
// }

//Determine if a watermelon can be split into two parts each of which weights even number of kilos
// int main(){
//   int a;
//   printf("Enter weight of watermelon:");
//   scanf("%d",&a);
//   if(a%2==0){
//     printf("splits in even weights");
//   }
//   else{
//     printf("splits into uneven weights");
//   }
// }


// given a number count the number of digits
// int main(){
//   int a;
//   printf("Enter a number:");
//   scanf("%d",&a);
//   int digits=0;
//   while(a!=0){
//     a=a/10;
//     digits++;
//   }
//   printf("digits are %d",digits);
// }
//given number is leap year or not 
// int main(){
//   int a;
//   scanf("%d",&a);
//   if(a%100==0 && a%400==0 && a%4==0){
//     printf("leap year");
//   }
//   else{
//     printf("not a leap year");
//   }
// }

int main(){
  int arr[5][2] = {{1,2}
                  ,{3,4}
                  ,{5,6}
                  ,{7,8}
                  ,{9,10}};
  int arr1[5][2];
  for(int i=0;i<5;i++){
    for(int j=0;j<2;j++){
      arr1[i][j]=arr[i][1-j];
    }
  }
   for(int i=0;i<5;i++){
      for(int j=0;j<2;j++){
        printf("[%d]",arr1[i][j]);
      }
     printf("\n");
    } 
}
