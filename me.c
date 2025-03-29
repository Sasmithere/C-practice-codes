#include <stdio.h>
#include <stdlib.h>

// void merge(int a[],int mid,int lb,int ub){
//   int i=lb , j=mid + 1 , k=lb, b[10];
//   while(i<=mid && j<=ub){
//     if(a[i]<a[j]){
//       b[k]=a[i];
//       i++;k++;
//     }
//     else{
//       b[k]=a[j];
//       j++;k++;
//     }
//   }
//   while(i<=mid){
//     a[k]=a[i];
//     k++;i++;
//   }
//   while(j<=lb){
//     a[k]=a[j];
//     k++;j++;
//   }
//   for(int i=lb;i<=ub;i++){
//     a[i]=b[i];
//   }
// }

// void printArr(int a[],int n){
//   for(int i = 0;i<n;i++){
//     printf("%d ",a[i]);
//   }
// }

// void MergeSort(int a[],int lb, int ub){
//   int mid;
//   if(lb<ub){
//     mid=(lb+ub)/2;
//     MergeSort(a,lb,mid);
//     MergeSort(a, mid+1,ub);
//     merge(a,mid,lb,ub);
//   }

// }

// int main(){
//   int a[]={5,1,3,2,9,6},n=6;
//   printArr(a,n);
//   printf("\n");
//   MergeSort(a,0,n-1);
//   printArr(a,n);
// }
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

struct node *ins_at_beg(struct node *head, int data) {
  struct node *head2 = (struct node *)malloc(sizeof(struct node));
  head2->data = data;
  head2->link = head;
  return head2;
}
struct node *ins_at_end(struct node *head, int data) {
  struct node *ptr = head;
  struct node *head2 = (struct node *)malloc(sizeof(struct node));
  head2->data = data;
  head2->link = NULL;
  while (ptr->link != NULL) {
    ptr = ptr->link;
  }
  head2->link = ptr->link;
  ptr->link = head2;
  return head;
}

struct node *ins_at_pos(struct node *head, int data, int key) {
  struct node *ptr = head;
  struct node *head2 = (struct node *)malloc(sizeof(struct node));
  head2->data = data;
  head2->link = NULL;
  for (int i = 0; i < key - 1 && ptr != NULL; i++) {
    ptr = ptr->link;
  }
  head2->link = ptr->link;
  ptr->link = head2;
  return head;
}

struct node *del_at_beg(struct node *head) {
  struct node *ptr = head;
  head = head->link;
  free(ptr);
  return head;
}

struct node *del_at_end(struct node *head) {
  if (head == NULL) {
    return head;
  }
  struct node *ptr = head;
  while (ptr->link->link != NULL) {
    ptr = ptr->link;
  }
  free(ptr->link);
  ptr->link = NULL;
  return head;
}

struct node *del_at_pos(struct node *head, int key) {
  struct node *ptr = head;
  if (key == 0) {
    struct node *ptr1 = head;
    head = head->link;
    free(ptr1);
    return head;
  }
  for (int i = 0; i < key - 1 && ptr != NULL; i++) {
    ptr = ptr->link;
  }
  struct node *temp = ptr->link;
  ptr->link = temp->link;
  free(temp);
  return head;
}

int main() {
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->data = 10;
  head->link = NULL;
  struct node *head1 = (struct node *)malloc(sizeof(struct node));
  head1->data = 20;
  head1->link = NULL;
  struct node *head2 = (struct node *)malloc(sizeof(struct node));
  head2->data = 30;
  head2->link = NULL;

  head->link = head1;
  head1->link = head2;
  struct node *ptr = head;
  print(head);
  head = ins_at_beg(head, 40);
  printf("\n");
  print(head);
  printf("\n");
  head = ins_at_end(head, 50);
  print(head);
  printf("\n");
  head = ins_at_pos(head, 60, 3);
  print(head);
  printf("\n");
  head = del_at_beg(head);
  print(head);
  printf("\n");
  head = del_at_end(head);
  print(head);
  printf("\n");
  head = del_at_pos(head, 2);
  print(head);
}
