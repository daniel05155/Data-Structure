# include <stdio.h>
# include <stdlib.h>

// 在circular queue加入一個標記變數後，可解決於普通的circular queue中不能辨別全滿或全空的問題。

#define  size 5
int arr[size];
int front=size-1,rear=size-1,qfull=0;

// 判別是否為空佇列
int empty()
{
  return qfull==0 && rear==front;
}

int full()
{
  return qfull==1;
}

//新增資料
void enqueue(int x){
  
  if( full() ){
    printf("Queue is full!\n");
  }
  else{
    rear = (rear+1)%size;
    arr[rear] = x;
    if(front==rear){
      qfull=1;
    }
  }
}

//刪除資料
void dequeue(){
  if(empty()){
    printf("Queue is empty()!\n");
  }
  else{
    front = (front+1)%size;
    printf("欲刪除的資料：%d\n",arr[front]);
  }
}

//輸出資料
void printlist(){
  if(empty()){
    printf("Queue is empty()!\n");
  }
  else{
    int i=(front+1)%size;
    printf("front-> ");
    for(;i<=rear;i++){
      printf("%d-> ",arr[i]);
    }
    printf(" rear\n");
  
  }
}

int main()
{

  enqueue(10);
  enqueue(20);
  enqueue(25);
  enqueue(55);
  enqueue(48);
  printlist();
  
  enqueue(95);  // 測試是否有滿的情形

  dequeue();
  dequeue();
  dequeue();
  dequeue();
  
  printlist();

return 0 ;
}

