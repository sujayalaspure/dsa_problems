#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};
void lLTraversal(struct Node *ptr)
{

  while (ptr != NULL)
  {
    printf("element :>> %d\n", ptr->data);
    ptr = ptr->next;
  }
}

struct Node *deleteFirst(struct Node *head)
{
  struct Node *ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

int main(int argc, char *argv[])
{
  struct Node *head;
  struct Node *second;
  struct Node *third;

  head = (struct node *)malloc(sizeof(struct Node));
  second = (struct node *)malloc(sizeof(struct Node));
  third = (struct node *)malloc(sizeof(struct Node));

  head->data = 7;
  head->next = second;

  second->data = 10;
  second->next = third;

  third->data = 15;
  third->next = NULL;

  printf("before deletion\n");
  lLTraversal(head);
  head = deleteFirst(head);


  printf("After deletion\n");
  lLTraversal(head);

  return 0;
}
