#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int size;
  int top;
  int *arr;
};

int isEmpty(struct stack *ptr)
{
  return (ptr->top == -1) ? 1 : 0;
}

int isFull(struct stack *ptr)
{
  return (ptr->top == ptr->size - 1)
             ? 1
             : 0;
}

void push (struct stack *ptr, int val) {
   if(isFull(ptr)){
     printf("stack overflow\n");
   }else{
     ptr->top++;
     ptr->arr[ptr->top] = val;
   }
}

int popStack (struct stack *ptr) {
  if(isEmpty(ptr)){
    printf("Stack Empty");
    return -1;
  }
  else
  {
    int oldvalue = ptr->arr[ptr->top];
    ptr->top = ptr->top - 1;
    return oldvalue;
  }
}


void printStack (struct stack *ptr) {
  if (ptr->top==-1)
  {
    printf("Empty Stack\n");
  }
  
   for (int i = 0; i <= ptr->top; i++)
   {
     printf(" %d\t", ptr->arr[i]);
   }
   printf("\n");
}


int peekStack (struct stack *ptr, int i) {
  int arrIndex = ptr->top - i + 1;
  if(arrIndex<0){
    printf("Not a valid Pos\n");
    return -1;
  }else{

    return ptr->arr[arrIndex];
  }
}

int main()
{ 
  struct stack *s;
  s = (struct stack *)malloc(sizeof(struct stack));
  s->size = 20;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));

  printStack(s);
  push(s, 10);
  push(s, 11);
  push(s, 3);
  push(s, 12);
  push(s, 13);
  // printStack(s);
  // popStack(s);
  // popStack(s);
  printStack(s);
  for (int i = 1; i <= s->top+1; i++)
  {
    printf("var_name :>> %d\n", peekStack(s, i));
    
  }

  return 0;
}
