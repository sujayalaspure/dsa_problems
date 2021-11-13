#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node *next;
};
  struct Node *top = NULL;


void lLTraversal (struct Node *ptr) {

while (ptr!=NULL)
{
  printf("element :>> %d\n", ptr->data);
  ptr = ptr->next;
}

}

struct Node * pushList (struct Node * tp, int x) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  n->data = x;
  n->next = tp;
  tp = n;

  return tp;
}


int popList (struct Node * tp) {
  struct Node *n = tp;
  top = tp->next;
  int x = n->data;
  free(n);

  return x;
}


int main () {
 top= pushList(top, 12);
 top= pushList(top, 11);
 top= pushList(top, 13);
 top= pushList(top, 15);
  lLTraversal(top);
  printf("pop element :>> %d\n", popList(top));
  lLTraversal(top);
  return 0;
}
