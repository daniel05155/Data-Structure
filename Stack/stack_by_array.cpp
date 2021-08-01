#include <iostream>
#include <cstdlib>
using namespace std;
// 以array實作stack
// 參考來源：http://alrightchiu.github.io/SecondRound/stack-yi-arrayyu-linked-listshi-zuo.html 

class  StackArray
{
  private:

    int top;
    int capacity;
    int *stack;
    void Double_Capacity() 
    {
      capacity=capacity*2;
      int *newstack = new int [capacity];

      for(int i=0;i<capacity/2;i++)
      {
        newstack[i] = stack[i];
      }
      delete [] stack;        //釋放掉原先的array
      stack = newstack;   
    }

  public:

    StackArray():top(-1),capacity(1)  
    { 
      stack = new int[capacity];       
    }

    void push(int x);
    int pop();
    bool empty();            //檢查堆疊是否為空
    bool full();             //檢查堆疊是否全滿
    int Top();
    int Getsize();
};
   
   void StackArray::push(int x){
       if(top == capacity-1){
          Double_Capacity();
       }
      stack[++top]=x;     
      //此處不能加else，若if成立，則會少Push一個元素
   }

    int StackArray::pop()
    {
      if(top==-1) return 0;
      else  return stack[top--];
    }

    //檢查堆疊是否為空
    bool StackArray::empty()
    {
      if(top==-1) return true;
      else return false;
    }

    //檢查堆疊是否全滿
    bool StackArray::full()
    {
      return (top==(capacity-1));
    }

    int StackArray::Top()
    {
      if(top==-1){
        cout<<"Stack is empty!,";
        return -1;
      } 
      else  return stack[top];
    }

    int StackArray::Getsize()
    {
      return (top+1);
    }


int main()
{
    StackArray s;
    
    s.push(14);
    cout<<"Push 14："<<endl;
    cout<<"top:"<<s.Top()<<",size:" <<s.Getsize()<<endl<<endl;

    cout<<"Push 5和7："<<endl;
    s.push(5);
    s.push(7);
    cout << "top: " << s.Top() << ",size: " << s.Getsize() <<endl;
    cout<<endl;

    cout<<"Pop 一個元素："<<endl;
    s.pop();
    cout << "top: " << s.Top() << ",size: " << s.Getsize() <<endl; 
    cout<<endl;

    cout<<"Pop 一個元素："<<endl;
    s.pop();
    cout << "top: " << s.Top() << ",size: " << s.Getsize() <<endl;
  

system("pause");
return 0;
}