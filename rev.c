#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stk{
int top;
int size;
int *arr;
};

struct stk *push(struct stk *ptr, int data) {
  if (ptr->top == -1) {
    ptr->arr[0] = data;
    ptr->top++;
  } else if (ptr->top == ptr->size - 1) {
    printf("Stack Overflow\n");
  } else {
    ptr->top++;
    ptr->arr[ptr->top] = data;
  }
  return ptr;
}

int main(){
  char str[] = "lmao";
 /* struct stk *s;
  s->top=-1;
  s->size=10;
  s->arr=(int *)malloc(sizeof(int)*s->size);*/
  for(int i=0;i<strlen(str);i++){
    printf("%c",str[i]);
  }
  
}