//print sum of 10 natural num
#include <stdio.h>
#include "gstio.h"
/*int main(){
  int a,b=0,c=0;
  scanf("%d",&a);
  while(a!=0){
    b=b+1;
    a=a-1;
    c=c+b;
  }
  printf("sum of n natural num %d ",c);
}*/
//Write a program in C to display n terms of natural number and their sum
/*int main(){
  int a,b=0,c=0;
  scanf("%d",&a);
  printf("The first %d natural number is :\n",a);
  while(a!=0){
    b=b+1;
    printf("%d ",b);
    a=a-1;
    c=c+b;
  }
  printf("\nsum of n natural num %d ",c);
  }
*/
//Write a program in C to read 10 numbers from keyboard and find their sum and average. 
/*int main(){
  int a;
  float b,c;
  scanf("%d",&a);
  for(int i=1;i<=a;i++){
    b=get_int("enter num %d:",i);
    c=c+b;
    (
  }
  printf("\nthe sum of %d num is: %f\n",a,c);
  printf("\nthe avg is : %f",c/a);
  
}
*/
/*Write a program in C to make such a pattern like right angle triangle with a number which will repeat a number in a row.
int main(){
  int a=5;
  for(int i=0;i<=a;i++){
    for(int j=1;j<=i;j++){
      if(i==j){
        printf("%d",j);
      }
      else{
        printf("%d",i);
      }
    }
    printf("\n");
  }
*/
/*int main(){
  int a=32;
  do{
    printf("%d",a);
    a++;
  }while(a<=30);
  return 0;
}
#include <stdio.h>

int main(){
    int a,b,Tsum=0,temp;
    scanf("%d",&a);
    temp=a;
    while(a!=0){
         rem=a % 10;
         Tsum=Tsum+(b*b*b);
         a=a/10;
    }
    if(Tsum==temp)
         printf("armstrong");
    else
         printf("not armstrong");

}
#include <stdio.h>

// Explain your logic here as comments
//first finding all prime numbers 
//i is iterative and will find remainder with num and store in p as 1
//if num%i is 0 then p will take value 1 if not then 0 
//c counts the number of prime factors by adding p to c.
//

#include <stdio.h>
int numberOfPrimeFactors(int n);
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", numberOfPrimeFactors(n));
	return 0;
}
int numberOfPrimeFactors(int n)
{
    int i, j,p,c;
    for(i=2; i<=n; i++)
    {
        if(n%i==0)
        {
            p = 1;
            for(j=2; j<=i/2; j++)
            {
                if(i%j==0)
                {
                    p = 0;
                    break;
                }
            }

            if(p==1)
            {
                c=c+p;
            }
            
        }
        
    }
    printf("%d",c);
    return 0;
}
	
*/	

/*int main(){
  int m,c=0,a,b;
  m=375;
  b=m;
  while(m!=0){
    a=m%10;
    c=c+a*a*a;
    m=m/10;
  }
  if(b==c){
    printf("num %d is armstrong",c);
  }
  else{
    printf("num %d is not armstrong",c);
  }
}
*/
/*Write a program in C to display the pattern like a pyramid using asterisk and each row contain an odd number of asterisks. Go to the editor

   *
  ***
 *****
*/
int main(){
  int n=10;
  for(int i=0;i<=n;i++){
    for(int j=n;j>i;j--){
      if(i>=j){
        printf("*");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
}

/*int main(){
  int a;
  float b;
  a=12;
  b=(float)150.150/10;
  printf("%f",b);
}
*/
/*void shift(int a,int b);
int main(){
  int a,b,temp;
  a=10;
  b=20;
  shift(a,b);
  printf("shifted %d ,%d",a,b);
}
void shift(int a,int b){
  int temp;
  temp=a;
  a=b;
  b=temp;
}
*/
/*int main(){
  int a,b,c,d,e,f,r;
  scanf("%d",&a);
  scanf("%d",&b);
  a=a%10;
  b=b%10;
  a=a*a;
  b=b*b;
  c=a+b;
  printf("sum of squares %d",c);
  
  
}
*/
