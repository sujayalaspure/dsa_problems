#include <stdio.h>
#include <stdlib.h>
struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
  int data;
  struct Node *next;
};

void lLTraversal(struct Node *ptr)
{

  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

void enqueue(int val)
{
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (n == NULL)
  {
    printf("Q is Full");
  }
  else
  {
    n->data = val;
    n->next = NULL;
    if (f == NULL)
    {
      f = r = n;
    }
    else
    {
      r->next = n;
      r = n;
    }
  }
}

int dequeue()
{
  int val;
  struct Node *n = f;
  if (f == NULL)
  {
    printf("Q empty");
  }
  else
  {
    f = f->next;
    val = n->data;
    free(n);
  }
  return val;
}

int main(int argc, char *argv[])
{

  enqueue(12);
  enqueue(13);
  enqueue(14);
  dequeue();
  dequeue();
  dequeue();
  lLTraversal(f);

  return 0;
}
