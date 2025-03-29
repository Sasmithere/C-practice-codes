#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

void print(struct node *head) {
  struct node *ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
}

struct node *ins_beg(struct node *head,int data) {
  struct node *ins = (struct node *)malloc(sizeof(struct node));
  ins->data = data;
  ins->link = head;
  head=ins;
  return head;
}

struct node *ins_at_end(struct node* head,int data){
  struct node *ins = (struct node *)malloc(sizeof(struct node));
  ins->data = data;
  ins->link = NULL;
  struct node *ptr=head;
  while(ptr->link!=NULL){
    ptr=ptr->link;
  }
  ptr->link=ins;
  ins->link=NULL;
  return head;
}

struct node *ins_at_pos(struct node* head,int data,int key){
  struct node *ins = (struct node *)malloc(sizeof(struct node));
  ins->data = data;
  ins->link = NULL;
  struct node *ptr=head;
  for(int i=0;i<key-1 && ptr!=NULL;i++){
    ptr=ptr->link;
  }
  if(ptr!=NULL){
  ins->link=ptr->link;
  ptr->link=ins;}
  else{
    printf("invalid pos");
    free(ins);
  }
  return head;
}


int main() {
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->data = 10;
  head->link = NULL;
  struct node *current = (struct node *)malloc(sizeof(struct node));
  current->data = 20;
  current->link = NULL;

  head->link = current;
  printf("\n");
  print(head);
  head=ins_beg(head,30);
  printf("\n");
  print(head);
  head=ins_at_end(head,40);
  printf("\n");
  print(head);
  head=ins_at_pos(head,50,2);
  printf("\n");
  print(head);
  
}