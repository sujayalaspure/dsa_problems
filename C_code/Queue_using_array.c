#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int size;
  int f;
  int r;
  int *arr;
};

void TraverseQueue(struct Queue *q)
{
  printf("var_name>> ");
  for (int i = q->f + 1; i <= q->r; i++)
  {
    printf("%d\t", q->arr[i]);
  }
  printf("\n");
}

int isFull(struct Queue *q)
{
  return (q->r == q->size - 1);
}
int isEmpty(struct Queue *q)
{
  return (q->r == q->f);
}

void enqueue(struct Queue *q, int val)
{
  if (isFull(q))
  {
    printf("Queue is Full\n");
  }
  else
  {
    q->r++;
    q->arr[q->r] = val;
  }
}
int dequeue(struct Queue *q)
{
  int a = -1;
  if (isEmpty(q))
  {
    printf("Queue Already Empty\n");
  }
  else
  {
    q->f++;
    a = q->arr[q->f];

    printf("var_name :>> %d\n", q->arr[q->f]);
  }

  return a;
}

int main(int argc, char *argv[])
{
  struct Queue *q;
  q = (struct Queue *)malloc(sizeof(struct Queue));
  q->size = 100;
  q->f = q->r = -1;
  q->arr = (int *)malloc(q->size * sizeof(int));

  TraverseQueue(q);
  enqueue(q, 20);
  enqueue(q, 2);
  enqueue(q, 0);
  enqueue(q, 80);
  TraverseQueue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);

  if (isEmpty(q))
  {
    printf("Queue Empty\n");
  }
  TraverseQueue(q);

  return 0;
}
