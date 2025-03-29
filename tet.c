#include <stdio.h>
#include <string.h>

int main(){
    char b[]={'a','e','i','o','u','\0'},o;
    int n[]={'0','1','2','3','4','5','6','7','8','9','\0'},e;
   int x,y,z;
    //a=get_double("Enter the string to find the vowel, consonants and numbers\n")
  printf("enter a char");
  scanf("%s",&o);
  char a[]={'s','a','s','y','1','2'};
    e=sizeof(a);
  printf("%d\n",e);
  printf("%s",a);
  char d[e],f[e],g[e];
    for(int i=0;i<e;i++){
        for(int j=0;j<e;j++){
          if(a[i]==b[j]){
              d[i]=a[i];
          }
          else if(a[i]==n[j]){
              f[i]=a[i];
          }
          else{
            g[i]=a[i];
          }
        }
    }
  
  x=sizeof(d)/sizeof(d[0]);
  y=sizeof(f)/sizeof(f[0]);
  z=sizeof(g)/sizeof(g[0]);
  printf("vowels:");
  for(int k=0;k<x;k++){
    printf("%c",d[k]);
  }
  printf("\nconsonants:");
  for(int l=0;l<z;l++){
    printf("%c",g[l]);
  }
  printf("\nnumbers:");
    for(int m=0;m<y;m++){
    printf("%d",f[m]);
    }
  return 0;
  }