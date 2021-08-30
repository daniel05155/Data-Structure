#include <stdio.h>
#include <stdlib.h>
// 加入特殊值以改善無法分清楚全滿或全空的現象

# define size 5
int arr[size];
int front=0,rear=size;


int full(void){
  return (front==rear);
}

int empty(void){
  return (rear==size);
}

void enqueue(int x){
  if( full() )  
    printf("Queue is full!\n");
  else{
    rear = (rear+1)%size;
    arr[rear] = x;
  }
    
}

void dequeue(void){
  if(empty())
   printf("Queue is empty!\n"); 
  else{
    front = (front+1)%size;
    printf("dequeue() = ");
    printf("arr[%d] = %d\n",front,arr[front]);
    if(front==rear) {front = 0,rear = size;}
  }
}

// Some errors in for loop
void output(int *arr)
{  
  if( empty() ) {printf("Queue is empty!\n");}
  else if( full() ){
    for(int i = (front+1)%size;i<=size-1;i++)
    {
      printf("%d-> ",arr[i]);
    }
    printf("%d->",arr[rear]);
  }
  else{ 
    int j=(front+1)%size;
    for(;j<=rear;j++){
      printf("%d-> ",arr[j]);
    }  
  }
  printf(" rear\n");
}

int main(void) 
{
  enqueue(15);
  enqueue(20);
  enqueue(25);
  enqueue(30);
  enqueue(35);
  output(arr);
  enqueue(40);

  dequeue();
  dequeue();

return 0;
}