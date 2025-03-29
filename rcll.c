#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
struct node *tail;
};

int main(){
  struct node *head=(struct node *)malloc(sizeof(struct node));
  head->data=5;
  head->next=NULL;
  struct node *head1=(struct node *)malloc(sizeof(struct node));
  head1->data=10;
  head1->next=NULL;
  head->next=head1;
  struct node *head2=(struct node *)malloc(sizeof(struct node));
  head2->data=15;
  head2->next=NULL;
  head1->next=head2;
  struct node *head3=(struct node *)malloc(sizeof(struct node));
  head3->data=20;
  head3->next=NULL;
  head2->next=head3;
  struct node *head4=(struct node *)malloc(sizeof(struct node));
  head4->data=25;
  head4->next=NULL;
  head4->tail=head;
}