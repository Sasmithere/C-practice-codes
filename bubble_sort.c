#include <stdio.h>
void bsort(int * , int);
int main(void) 
{
  int a[50],i,n;
  printf("Enter the size of the array : ");
  scanf("%d",&n);
  printf("\nEnter the elements : ");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("\n\nArray before sorting : ");
  for(i=0;i<n;i++)
    printf("%d   ",a[i]);
  bsort(a,n);
  printf("\n\nArray after sorting : ");
  for(i=0;i<n;i++)
    printf("%d   ",a[i]);
  return 0;
}
void bsort(int * a,int n)
{
   int i,j,tmp;
   for(i=0;i<n-1;i++)
     {
        int flag=0;
        for(j=0;j<n-1-i;j++)
          {
            if(a[j]>a[j+1])
            {
               tmp=a[j];
               a[j]=a[j+1];
               a[j+1]=tmp;
               flag=1;
            }
          }
         if(flag==0)
           break;
     }
}