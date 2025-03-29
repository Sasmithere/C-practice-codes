#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *prevNode;
struct node *nextNode;
};

struct node* deleteNode(struct node* head, int key) {
    struct node* temp = head;
    if (temp == NULL) {
        return head;
    }

    // Special case: If the key is in the head node
    if (temp->data == key) {
        head = temp->nextNode;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != key) {
        temp = temp->nextNode;
    }

    // If key not found, return the original list
    if (temp == NULL) {
        return head;
    }

    temp->prevNode->nextNode = temp->nextNode;
    if (temp->nextNode != NULL) {
        temp->nextNode->prevNode = temp->prevNode;
    }
    free(temp);
    return head;
}


void print(struct node *head){
  struct node *current=head;
  while(current!=NULL){
    printf("%d ",current->data);
    current=current->nextNode;
  }
}

struct node* ins_at_beg(struct node *head,int data){
  struct node *head2=(struct node *)malloc(sizeof(struct node));
  head2->data=data;
  head2->nextNode=NULL;
  head2->prevNode=NULL;
  head2->nextNode=head;
  head=head2;
  return head;
}

struct node* ins_at_end(struct node *head,int data){
  struct node *head2=(struct node *)malloc(sizeof(struct node));
  head2->data=data;
  head2->nextNode=NULL;
  head2->prevNode=NULL;
  struct node *current=head;
  while(current->nextNode!=NULL){
    current=current->nextNode;
  }
  current->nextNode=head2;
  head2->prevNode=current;
  return head;
}

struct node* ins_at_pos(struct node *head,int data,int key){
  struct node *head2=(struct node *)malloc(sizeof(struct node));
  head2->data=data;
  head2->nextNode=NULL;
  head2->prevNode=NULL;
  if(head==NULL){
    return head;
  }
  struct node* current=head;
  for(int i = 0 ; i<key-1 && current->nextNode!=NULL;i++){
    current=current->nextNode;
  }
  if(current->nextNode!=NULL){
        head2->nextNode = current->nextNode;
        current->nextNode->prevNode = head2;
  }
  current->nextNode=head2;
  head2->prevNode=current;
  return head;
  
}

int main(){
  struct node *head=(struct node *)malloc(sizeof(struct node));
  head->data=10;
  head->nextNode=NULL;
  head->prevNode=NULL;
  struct node *head2=(struct node *)malloc(sizeof(struct node));
  head2->data=20;
  head2->nextNode=NULL;
  head2->prevNode=head;
  head->nextNode=head2;
  print(head);
  printf("\n");
  head=ins_at_beg(head,30);
  print(head);
  printf("\n");
  head=ins_at_end(head,40);
  print(head);
  printf("\n");
  head=ins_at_pos(head,50,3);
  print(head);
  printf("\n");
  head=deleteNode(head,2);
  print(head);
  }