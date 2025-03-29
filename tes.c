#include <stdio.h>
#include <string.h>

int main(){
  int ch[100];
  fgets(ch,sizeof(ch),stdin);
  puts(ch);
}