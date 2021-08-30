#include <stdio.h>
#include <stdlib.h>


//implementing stack using linked-list
struct node
{
  int data;
  struct node *link;
};
typedef struct node *NODE;
NODE top=NULL;

void push(int x);
int pop();
int Top();

int main(void)
{
  push(5);
  push(10);
  
  printf("Top =%d\n",Top());
  printf("pop =%d\n", pop());
  printf("Top =%d\n",Top());

return 0;
}

void push(int x)
{
  NODE ptr = NULL;
  ptr = (NODE)malloc(sizeof(struct node));
  if(ptr==NULL)
  {
    printf("No sufficient memory!\n");
  }
  else 
  {
    ptr->data = x;
    ptr->link = top;
    top = ptr;
  }
}

int pop()
{
  if(top==NULL)
  {
    printf("The stack is empty!\n");
    return 0;
  }
  else{
    NODE temp;
    int x;
    temp = top;
    top = top->link;
    x=temp->data;
    return x;
  }
}

int Top()
{
  return top->data;
}
