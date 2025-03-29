#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *prevNode;
struct node *nextNode;
}*start;

struct node *CreateNode(int data){
  struct node *current=(struct node *)malloc(sizeof(struct node));
  current->data=data;
  current->prevNode=NULL;
  current->nextNode=NULL;
  return current;
}

int Search(struct node *head,int key){
  struct node *current=head;
  int pos=0,count=0,pos1=0;
  while(current!=NULL){
    if(current->data==key){
      return pos;
    }
    current=current->nextNode;
    pos++;
  }
  return 0;
}



int main(){
  struct node *current=(struct node *)malloc(sizeof(struct node));
  current->data=5;
  current->prevNode=NULL;
  current->nextNode=NULL;
  struct node *current1=(struct node *)malloc(sizeof(struct node));
  current1->data=10;
  current1->prevNode=current;
  current1->nextNode=NULL;
  current->nextNode=current1;
  struct node *current2=(struct node *)malloc(sizeof(struct node));
  current2->data=15;
  current2->prevNode=current1;
  current2->nextNode=NULL;
  current1->nextNode=current2;
  struct node *current3=(struct node *)malloc(sizeof(struct node));
  current3->data=20;
  current3->prevNode=current2;
  current3->nextNode=NULL;
  current2->nextNode=current3;
  struct node *current4=(struct node *)malloc(sizeof(struct node));
  current4->data=25;
  current4->prevNode=current3;
  current4->nextNode=NULL;
  current3->nextNode=current4;

  struct node *head=current;
  while(head!=NULL){
    printf("%d ",head->data);
    head=head->nextNode;
  }
  int check=Search(current,25);
  if(check==0){
    printf("\nElement not Found!!!");
  }
  else{
    printf("\nfound at %d position ",check);
  }
}
