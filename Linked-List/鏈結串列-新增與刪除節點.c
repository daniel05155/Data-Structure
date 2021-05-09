#include <stdio.h>
#include <stdlib.h>

//題1：以陣列arr[]來建立一個鏈結串列，並將其列印出來
//題2：在節點56後，插入一個新節點88
//題3：刪除節點12、34與24

struct node
{
  int data;
  struct node *link;
};
typedef struct node *nodeptr;


nodeptr create(int a[],int length)        //建立Linked list
{
  nodeptr head,tail,p;
  head = tail = (nodeptr)malloc(sizeof(struct node));
  for(int i=0;i<length;i++)
  {
    tail->link =(nodeptr)malloc(sizeof(struct node));
    tail = tail->link; 
    tail->data = a[i];
  }  
  p=head; 
  head = head->link;
  free(p);
  return head;
}

void printlist(nodeptr linklist)               // 列印鏈結串列
{
  nodeptr q = linklist;
  while(q!=NULL)
  {
    printf("%d,",q->data);
    q=q->link;
  }
  printf("\n");
}

nodeptr SearchandInsert (nodeptr first,int ordinarynum,int newnum)   //搜尋與插入節點
{
  nodeptr p = first; 
  nodeptr head= first,newnode;

  if(p->data == ordinarynum)
  {
    newnode = (nodeptr)malloc(sizeof(struct node));
    newnode -> data =  newnum;
    newnode->link = p->link;
    p->link = newnode;
    return head;
  }
  else
  {
    while(p->data!= ordinarynum)
    {
      p=p->link;
    }
    newnode = (nodeptr)malloc(sizeof(struct node));
    newnode -> data =  newnum;
    newnode->link = p->link;
    p->link = newnode;
    return head;
  }
}

nodeptr del(nodeptr first,int deletenum)               
{
  nodeptr ptr=first;
  nodeptr temp;
  if(ptr==NULL)
    printf("串列是空的");
  else if(ptr->data == deletenum)
  {  
    first = first->link;
    free(ptr);
  }
  else
  { 
    while(ptr->link->data!=deletenum)
    {
      ptr=ptr->link;
    }
    temp=ptr->link;
    if(temp->link==NULL)       //檢查欲刪除節點是否為最後一個節點
    {
      free(temp);
      ptr->link=NULL;
    }
    else
    {
      ptr->link =ptr->link->link;
      free(temp);
    }
    
  }

return first ;
}



int main(void) 
{
  int arr[] = {12,43,56,34,98,76,43,24};   
  int length = sizeof(arr)/sizeof(arr[0]);


  //題1：以陣列arr[]來建立一個鏈結串列，並將其列印出來
  nodeptr first = create(arr,length);
  printf("題1 — 以陣列arr[]來建立一個鏈結串列，並將其列印出來:\n");
  printlist(first);
  printf("\n");
  
  //題2：在節點56後，插入一個新節點88
  int ordinarynum = 56 ,newnum=88;
  nodeptr newlist = SearchandInsert(first,ordinarynum,newnum);
  printf("題2 — 在節點56後，插入一個新節點88:\n");
  printlist(newlist);
  printf("\n");

  //題3
  int num2=12,num3=34,num4=24;
  
  //刪除節點12
  nodeptr sec = del(first,num2);
  printf("題3 — 刪除節點12:\n");
  printlist(sec);
  printf("\n");

  //刪除節點34
  nodeptr sec1 = del(sec,num3);
  printf("題3 — 刪除節點34:\n");
  printlist(sec1);
  printf("\n");

  //刪除節點24
  nodeptr sec2 = del(sec1,num4);
  printf("題3 — 刪除節點24:\n");
  printlist(sec2);
  printf("\n");



  system("pause");
  return 0;
}