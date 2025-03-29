#include <stdio.h>

int main(){
  char a[100],b[100],c[100];
  int d[100],x,y,z;
   printf("Enter a line of string: ");
    scanf("%s",a);
  printf("vowels:");
  for (int i = 0; a[i] != '\0'; i++){
     if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' ||
        a[i] == 'o' || a[i] == 'u' || a[i]=='A' || a[i]=='E'|| a[i]=='I'|| a[i]=='O'|| a[i]=='U') {
       printf("vowles %c\n",a[i]);
  } 
    else if(a[i]>='0' && a[i]<='9'){
      printf(" \nnumbers %c",a[i]);
    }
    else{
      printf("\nconsonants %c",a[i]);
    }
    }
  /*
  x=sizeof(b);
  y=sizeof(c);
  z=sizeof(d);
  printf("vowels:");
  for(int k=0;k<x;k++){
    printf("%c",b[k]);
  }
  printf("\nconsonants:");
  for(int l=0;l<z;l++){
    printf("%c",d[l]);
  }
  printf("\nnumbers:");
    for(int m=0;m<y;m++){
    printf("%d",c[m]);
      */
  }
