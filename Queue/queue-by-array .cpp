#include<iostream>
#include<cstdlib>
using namespace std;
//# define size 10;

class array_queue{
  private:
    int front;
    int tail;
    int *q;
    int size;
      
  public:
    array_queue(){
      front = tail= -1;
      size = 10;
      q = new int[size];
      // 查一下: int queue [size];  
    }
    void enqueue(int x);
    int dequeue();
    void queuemove();
    bool empty();
    bool full();
    int Getfront();
    
};
void array_queue::enqueue(int x)
{
  if(tail==(size-1)){
    queuemove();
  }
  else{
    q[++tail] = x;
  }
}

void array_queue::queuemove(){
  if(front==-1){              
    cout<<"queue is full!"<<endl;  //queue已滿
  }
  else{                           //將queue中元素往前補滿
    for(int j=front+1;j<=tail;j++){
      q[j-front-1]=q[j];  
    }
  }
  front=-1;
}

int array_queue::dequeue(){
  if(front==tail){
    cout<<"queue is empty!"<<endl;
    return -1;
  }
  else{
    int x;
    front++;
    x=q[front];
    return x;
  }
}

bool array_queue::empty()
{
  return (front==tail);
}

bool array_queue::full()
{
  return (tail-front==size);
}

 int array_queue:: Getfront()
 {
   return q[++front];
 }


int main(void)
{
  array_queue imp;
  
  cout<<"enqueue 56、42、28"<<endl;
  imp.enqueue(56);
  imp.enqueue(42);
  imp.enqueue(28);

  cout<<"首要元素: ";
  cout<<imp.Getfront()<<endl;

  cout<<"dequeue 56、42"<<endl;
  imp.dequeue();

  cout<<"首要元素: ";
  cout<<imp.Getfront()<<endl;


  
return 0;
}