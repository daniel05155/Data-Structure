#include <stdio.h>
#include <stdlib.h>

struct node{
 int data;
 struct node *link;
};
typedef struct node *nodeptr;

// 建立Linked List
nodeptr create(int arr[],int length)
{
  nodeptr head,tail,temp;
  head = tail=(nodeptr)malloc(sizeof(struct node));
  for(int i=0;i<length;i++)
  {
    tail->link = (nodeptr)malloc(sizeof(struct node));
    tail = tail->link;
    tail->data = arr[i];
  }
  tail->link = NULL;
  temp = head;
  head = head->link;
  free(temp);
  return head;
}

// 計算Linked List長度(非遞迴)
int NodeNum(nodeptr head)
{
  int count=0;
  nodeptr temp=head;
  while(temp)
  {
    temp=temp->link;
    count++;
  }
  return count;
}

// 計算Linked List長度(遞迴版)
int NodeNum2(nodeptr head)
{
 if(head==NULL) return 0;
 else  return NodeNum2(head->link)+1;
 
}

 // 列印鏈結串列
void printlist(nodeptr linklist)              
{
  nodeptr q = linklist;
  while(q!=NULL)
  {
    printf("%d,",q->data);
    q=q->link;
  }
  printf("\n");
}


int main()
{
  int arr[] = {12,43,56,34,98,76,43,24,15,26,29};   
  int length = sizeof(arr)/sizeof(arr[0]);
  //以陣列arr[]來建立一個鏈結串列，並將其列印出來
  nodeptr first = create(arr,length);
  printlist(first);
 
  printf("計算Linked List長度: %d",NodeNum(first));
  printf("\n計算Linked List長度(遞迴版): %d",NodeNum2(first));

return 0;
}