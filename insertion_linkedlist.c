#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int data;
  struct Node *next;
};
void lLTraversal (struct Node *ptr) {

while (ptr!=NULL)
{
  printf("element :>> %d\n", ptr->data);
  ptr = ptr->next;
}

}


struct Node * insertAtBegining(struct Node * head, int data){

  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  ptr->next = head;

  return ptr;
}
struct Node * insertAtEnd(struct Node * head, int data){

  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *p = head;
  
  while (p->next!=NULL)
  {
    p = p->next;
  }
  p->next = ptr;
  ptr->data = data;
  ptr->next = NULL;

  return head;
}
struct Node * insertinBetween(struct Node * head, int data, int index){

  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  int i = 0;
  struct Node *p = head;
  while (i != index - 1)
  {
    p = p->next;
    i++;
  }

  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;

  return head;
}


int main (int argc, char *argv[]) {
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
  third->next =  NULL;

  lLTraversal(head);
  // head = insertAtBegining(head, 20);
  head = insertAtEnd(head, 20);
  // head = insertinBetween(head, 20, 2);
  lLTraversal(head);

  return 0;
}
