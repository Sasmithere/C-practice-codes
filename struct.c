#include <stdio.h>
// struct d1{
// int Sr;
// char sr;
// char name[50];
// };

// int main(){
//   struct d1 s1={13,'b',"lmao"};
//   Modify values
//   s1.Sr = 30;
//   s1.sr = 'C';
//   strcpy(s1.name, "Something else");

//   Print values
//   printf("%d %c %s", s1.Sr, s1.sr, s1.name);

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;

struct node *createSSL() {
  struct node *newnode = malloc(sizeof(struct node));
  printf("Enter data: ");
  scanf("%d", &newnode->data);
  newnode->next = NULL;

  if (start == NULL) {
    start = newnode;
  } else {
    struct node *temp = start;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newnode;
  }

  return start;
}

int main() {
  struct node *head = createSSL();
  printf("The linked list is: ");
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  return 0;
}
 