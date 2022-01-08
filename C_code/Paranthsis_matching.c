#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int size;
  int top;
  char *arr;
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

void push (struct stack *ptr, char val) {
   if(isFull(ptr)){
     printf("stack overflow\n");
   }else{
     ptr->top++;
     ptr->arr[ptr->top] = val;
   }
}

char popStack (struct stack *ptr) {
  if(isEmpty(ptr)){
    printf("Stack Empty");
    return -1;
  }
  else
  {
    char oldvalue = ptr->arr[ptr->top];
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

int checkPara(char * exp){
  struct stack *sp;
  sp = (struct stack *)malloc(sizeof(struct stack));
  sp->size = 100;
  sp->top = -1;
  sp->arr = (char *)malloc(sp->size * sizeof(char));

  for (int i = 0; exp[i]!='\0'; i++)
  {
    if(exp[i]=='(')
      push(sp, exp[i]);
    if(exp[i]==')'){
      if(isEmpty(sp))
        return 0;
      popStack(sp);
    }
  }

  return isEmpty(sp);
}


int match (char a, char b) {
  if(a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']' )
    return 1;
  return 0;
}

int multiParaMatching (char * exp) {
   struct stack *sp;
  sp = (struct stack *)malloc(sizeof(struct stack));
  sp->size = 100;
  sp->top = -1;
  sp->arr = (char *)malloc(sp->size * sizeof(char));
  char popped_char;

  for (int i = 0; exp[i]!='\0'; i++)
  {
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
      push(sp, exp[i]);
    if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
      if(isEmpty(sp))
        return 0;
      popped_char= popStack(sp);
      if(!match(popped_char, exp[i])){
        return 0;
      }
    }
  }

  return isEmpty(sp);
}

int main()
{ 
printf("check Exp1 :>> %d\n", multiParaMatching("(3*5)-(8+1)"));
printf("check Exp2 :>> %d\n", multiParaMatching("{3*5]-(8+1)"));

  return 0;
}
