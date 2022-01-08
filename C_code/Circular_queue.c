#include <stdio.h>
#include <stdlib.h>

struct CQueue
{
  int size;
  int f;
  int r;
  int *arr;
};

void TraverseQueue(struct CQueue *q)
{
  printf("var_name>> ");

  if (q->r > q->f)
  {

    for (int i = q->f + 1; i <= q->r; i++)
    {
      printf("%d ", q->arr[i]);
    }
  }
  else
  {
    for (int i = q->f + 1; i < q->size; i++)
    {
      printf("%d ", q->arr[i]);
    }
    for (int i = 0; i <= q->r; i++)
    {
      printf("%d ", q->arr[i]);
    }
  }
  printf("\n");
}

int isFull(struct CQueue *q)
{
  return ((q->r + 1) % q->size == q->f);
}
int isEmpty(struct CQueue *q)
{
  return (q->r == q->f);
}

void enqueue(struct CQueue *q, int val)
{
  if (isFull(q))
  {
    printf("CQueue is Full\n");
  }
  else
  {
    q->r = (q->r + 1) % q->size;
    q->arr[q->r] = val;
  }
}
int dequeue(struct CQueue *q)
{
  int a = -1;
  if (isEmpty(q))
  {
    printf("CQueue Already Empty\n");
  }
  else
  {
    q->f = (q->f + 1) % q->size;
    a = q->arr[q->f];

    printf("var_name :>> %d\n", q->arr[q->f]);
  }

  return a;
}

int main(int argc, char *argv[])
{
  struct CQueue *q;
  q = (struct CQueue *)malloc(sizeof(struct CQueue));
  q->size = 6;
  q->f = q->r = 0;
  q->arr = (int *)malloc(q->size * sizeof(int));

  enqueue(q, 12);
  enqueue(q, 15);
  enqueue(q, 15);
  enqueue(q, 16);
  enqueue(q, 16);
  // enqueue(q, 17);
  TraverseQueue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  enqueue(q, 18);
  enqueue(q, 18);
  TraverseQueue(q);

  return 0;
}
