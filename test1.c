#include <stdio.h>
#include <stdlib.h>
// int main(){
//   int arr[]={11,55,34,77,43,88},data;
//   scanf("%d",&data);
//   for(int i=0;i<sizeof(arr);i++){
//     if(arr[i]==data){
//       printf("ele found at %d index",i);
//     }
//     else{printf("not found");break;}
//   }
// }
// void swap(int a ,int b){
//   int temp = a;
//   b=a;
//   a=temp;
// }
// void print(int *arr,int size){
//   for(int i=0;i<size;i++){
//     printf("%d",arr[i]);
//   }
// }
// int min;
// int main(){
//   int arr[]={11,55,34,77,43,88},size=sizeof(arr)/sizeof(arr[0]);
//   for(int i=0;i<size;i++){
//      min=i;
//     for(int j=i+1;j<size;j++){
//       if(arr[min]<arr[j]){
//         swap(arr[i],arr[j]);
//       }
//       // else if(arr[min]<arr[i]){

//       // }
//     }
//   }
//    printf(arr,size);

// }
struct node {
  int data;
  struct node *temp;
};

void count(struct node *lol) {
  int cout = 0;
  if (lol == NULL) {
    printf("empty sll");
  } else {
    struct node *ptr = lol;
    while (ptr != NULL) {
      cout++;
      ptr = ptr->temp;
    }
    printf("%d", cout);
  }
}

void ins_at_end(struct node *lmao) {
  int count = 0;
  if (lmao == NULL) {
    printf("empty sll");
  }
  else{
  struct node *ptr = lmao;
  while (ptr->temp!= NULL) {
    ptr = ptr->temp;
  }
  struct node *next = (struct node *)malloc(sizeof(struct node));
  next->data = 44;
  next->temp = NULL;
  ptr->temp = next;
  }
}
//   do{ptr=ptr->temp;
//      if(ptr==NULL){
//        ptr->data=50;
//        ptr->temp=NULL;
//        break;
//      }}while(ptr!=NULL);
// }
struct node* add_beg(struct node *head,int d){
 struct node *ptr=malloc(sizeof(struct node));
 ptr->data=d;
 ptr->temp=NULL;
 ptr->temp= head;
 return head;
}
int main() {
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->data = 10;
  head->temp = NULL;
  printf("%d\n", head->data);
  struct node *next = (struct node *)malloc(sizeof(struct node));
  next->data = 44;
  next->temp = NULL;
  head->temp = next;
  // printf("%d\n", next->data);
  // count(head);
  // ins_at_end(head);
  // int *ptr;
  int data1=65;
  head=add_beg(head,data1);
  while (head->temp!= NULL) {
    printf("%d", head->data);
    head=head->temp;
  }
  return 0;
}
