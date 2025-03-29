#include <stdio.h>
#include <stdlib.h>

struct queue {
  int rear, front, size, *arr;
};

int isEmpty(struct queue *q) {
  if (q->front == q->rear) {
    return 1; // Queue is empty
  } else {
    return 0;
  }
}

int isFull(struct queue *q) {
  if (q->rear == q->size - 1) {
    return 1; // Queue is full
  } else {
    return 0;
  }
}

void enqueue(struct queue *q, int data) {
  if (isFull(q)) {
    printf("Queue is full !!\n");
  } else {
    q->arr[q->rear] = data;
    q->rear++;
  }
}

void dequeue(struct queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
  } else {
    printf("Dequeued element is %d\n", q->arr[q->front]);
    q->front++;
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

  dequeue(&q);
  dequeue(&q);

  for (int i = q.front; i < q.rear; i++) {
    printf("%d\n", q.arr[i]);
  }

  free(q.arr); // Don't forget to free the memory.
}
