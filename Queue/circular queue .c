#include <stdio.h>
#include <stdlib.h>
/*
1. 參考: https://github.com/nicehorse06/data-structures-and-algorithms/blob/master/queue/circle_queue.c
2. 用環狀佇列能改善於linear queue新增資料時，搬動資料的時間。
3. 新增資料：O(1)，刪除資料：O(1)

*/

// creat a circular queue
# define size 10
int front=size-1;
int rear=size-1;
int queue[size];

// check if it is full or not
int full(){
  return ( ((rear+1)%size) == front);
}

// check if it is empty or not
int empty(){
  return (rear==front);
}

// 新增資料
void enqueue(int x){
  if(full()){
    printf("Queue is full!\n");
  }
  else{
    rear = (rear+1)%size; //rear往下個位置移動
    queue[rear] = x; 
  }
}

// 刪除資料且輸出剩餘資料
void dequeue(){
  int t;
  if(empty())  printf("Queue is empty!\n");
  else{
    front=(front+1)%size;
    t= queue[front];
    printf("欲刪除的資料：%d\n",t);
  }
}


void printlist(){
  if(front==rear)  printf("Queue is empty!\n");
  else{
    int k=(front+1)%size;      //k為欲輸出的首元素之index
    printf("queue中的資料：");
    printf("front->");
    
    for(int i=k;i<=rear;i++){
      printf("%3d->",queue[i]);
    }
  }
  printf(" rear");
  printf("\n");
}

int main(void) {

  enqueue(10);
  enqueue(20);
  enqueue(25);
  enqueue(55);
  enqueue(72);
  printlist();
  
  dequeue();
  printlist();

  dequeue();
  dequeue();
  printlist();

  return 0;
}