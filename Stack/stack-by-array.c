#include <stdio.h>
#include <stdlib.h>


// implementing stack using array 
# define size 3
int stack[size];
int sp = -1;

void push(int x);
int pop(void);
int full(void);
int empty(void);
int top(void);

int main(void)
{
  push(5);
  push(10);
  push(15);
  push(20);
  
  printf("top =%d\n",top());
  
  printf("pop =%d\n",pop());
  
  printf("top =%d\n",top());
  
  printf("pop =%d\n",pop());


  return 0;
}
void push(int x)
{
  if(full()) 
    printf("The stack is full!\n");
  else 
    stack[++sp] = x;
}

int pop(void)
{
  int y;
  if(empty())
  {
    printf("The stack is empty!\n");
    return 0;
  }
  else
  {
    y = stack[sp--];
    return y;
  } 
}

int  full(void)
{
  if(sp==size-1)
    return 1;
  else
    return 0;
}

int empty(void)
{
  if(sp==-1)
    return 1;
  else
    return 0;
}

int top(void)
{
  return stack[sp];
}


