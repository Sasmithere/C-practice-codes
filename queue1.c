#include <stdio.h>
#include <stdlib.h>

struct queue {
  int rear, front, size, *arr;
};

int isEmpty(struct queue *arr) {
  if (arr->front == arr->rear) {
    return 1;
  } else {
    return 0;
  }
}

int isFull(struct queue *arr) {
  if (arr->rear == arr->size) {
    return 1;
  } else {
    return 0;
  }
}

void enqueue(struct queue *arr, int data) {
  if (isFull(arr)) {
    printf("queue is full !!");
  } else {
    arr->arr[arr->rear] = data;
    arr->front++;
    arr->rear++;
  }
}

void dequeue(struct queue *arr){
  if(isEmpty(arr)){
    printf("queue is empty");
  }
  else{
    printf("dequeued element is %d",arr->arr[arr->front]);
    arr->front++;
  }
}

int main() {
  struct queue q;
  q.size = 10;
  q.front = q.rear = 0;
  q.arr = (int *)malloc(q.size * sizeof(int));

  enqueue(&q, 5);
  enqueue(&q, 10);
  enqueue(&q, 15);
  enqueue(&q, 20);
  dequeue(&q);

  for (int i = 0; i < q.front; i++) {
    printf("\n%d\n", q.arr[i]);
  }
}