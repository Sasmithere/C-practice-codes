#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stk {
  int size;
  int top;
  int *arr;
};

void isEmpty(struct stk *ptr) {
  if (ptr->top == -1) {
    printf("Empty stack\n");
  } else {
    printf("Stack has elements\n");
  }
}

void isFull(struct stk *ptr) {
  if (ptr->top == ptr->size - 1) {
    printf("Stack is Full\n");
  }
}

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

struct stk *pop(struct stk *ptr) {
  if (ptr->top == -1) {
    printf("Empty stack\n");
    return ptr;
  } else {
    int temp = ptr->arr[ptr->top];
    ptr->top--;
    printf("Item popped: %d\n", temp);
    return ptr;
  }
}

struct stk *top(struct stk *ptr) {
  if (ptr->top == -1) {
    printf("Empty stack\n");
    return ptr;
  }
  printf("Top element index: %d\n", ptr->top);
  printf("%d\n", ptr->arr[ptr->top]);
  return ptr;
}

struct stk *peek(struct stk *ptr, int key) {
  if (ptr->top == -1) {
    printf("Empty Stack\n");
    return ptr;
  } else if (key >= 0 && key <= ptr->top) {
    printf("Index of the given element: %d\n", key);
    printf("Element is: %d\n", ptr->arr[key]);
    return ptr;
  } else {
    printf("Invalid index\n");
    return ptr;
  }
}

int main() {
  int in = 0;
  int ch = 0;
  struct stk *s = (struct stk *)malloc(sizeof(struct stk));
  s->size = 10;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));
  while (1) {
    printf("What operation do you want to perform:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Top\n");
    printf("4. Peek\n");
    printf("5. Quit\n");
    printf("6.print in reverse");
    scanf("%d", &in);
    if (in == 1) {
      printf("How much data do you want to enter: ");
      scanf("%d", &ch);
      int data = 0;
      for (int i = 0; i < ch; i++) {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &data);
        push(s, data);
      }
    } else if (in == 2) {
      pop(s);
    } else if (in == 3) {
      top(s);
    } else if (in == 4) {
      printf("Enter the index you want to access: ");
      int ind = 0;
      scanf("%d", &ind);
      peek(s, ind);
    } else if (in == 6) {
      char ch[] = "lmao bro";
      printf("string before : %s",ch);
      for(int i=strlen(ch)-1;i>=0;i--){
        push(s,ch[i]);
      }
      for(int i=)
      printf("after reversal : %s",);
    }
    else {
      free(s->arr);
      free(s);
      break;
    }
  }
}
