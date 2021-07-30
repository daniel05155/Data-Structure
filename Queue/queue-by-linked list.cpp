#include<iostream>
#include<cstdlib>
using namespace std;
/*
 參考:
 https://alrightchiu.github.io/SecondRound/queue-introjian-jie-bing-yi-linked-listshi-zuo.html
 */

struct node{
  int data;
  node* link;
  node(int x):data(x),link(NULL){}; // struct constructor 
};
typedef struct node *nodeptr;

class queue{
  private: 
    nodeptr front;
    nodeptr tail;
    int size;
 
  public:
    queue():front(NULL),tail(NULL),size(0){}
    void enqueue(int x);
    int  dequeue();
    bool empty();
    int Getsize();
    int Getfront();
    int Gettail();
     
};

void queue::enqueue(int x)
{
  if(empty())
  {
    tail = new struct node(x);
    front = tail;
    size++;
  }
  else{
    tail->link = new struct node(x);
    tail = tail->link ;
    size++;
  }
}

int queue::dequeue(){
  if(empty()){
    cout<<"queue is empty!"<<endl;
    return 0;
  }
  else{
    int t;
    nodeptr p;
    t = front->data;
    p = front;
    front = front->link;
    size--;
    free(p);
    return t;
  }
}

bool queue::empty(){
  if(front==NULL&&tail==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

int queue::Getsize(){
  return size;
}

int queue::Getfront()
{
  if(empty())
  {
    cout<<"queue is empty!"<<endl;
    return 0;
  }
  else{
    return front->data;
  }
} 

int queue::Gettail(){
  if(empty())
  {
    cout<<"queue is empty!"<<endl;
    return 0;
  }
  else{
    return tail->data;
  }
}

int main(void)
{
  queue b;

  cout<<"queue的data數量 = "<< b.Getsize()<<endl<<endl;

  b.enqueue(56);
  cout<<"After enqueue 56:"<<endl;
  cout<<"front = "<<b.Getfront()<<",tail = "<<b.Gettail()<<endl;
  cout<<endl;
  
  
  b.enqueue(14);
  cout<<"After enqueue 14:"<<endl;
  cout<<"front = "<<b.Getfront()<<",tail="<<b.Gettail()<<endl;
  cout<<"size = "<<b.Getsize()<<endl;
  cout<<endl;
  
  
  b.enqueue(45);
  cout<<"After enqueue 45:"<<endl;
  cout<<"front = "<<b.Getfront()<<",tail="<<b.Gettail()<<endl;
  cout<<endl;
  
  b.dequeue();
  cout<<"After dequeue:"<<endl;
  cout<<"front = "<<b.Getfront()<<",tail = "<<b.Gettail()<<endl;
  cout<<"size = "<<b.Getsize()<<endl;
  cout<<endl;
  
  
return 0;
}
