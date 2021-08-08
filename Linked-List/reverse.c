#include <stdio.h>
#include <stdlib.h>

// 反轉鏈結串列

struct node
{
  int data;
  struct node *link;
};
typedef struct node *nodeptr;

nodeptr create(int a[],int length);        //建立Linked list
void printlist(nodeptr linklist);          // 列印鏈結串列
nodeptr invert(nodeptr first);

int main()  
{  
    int arr[] = {12,43,56,34,98,76,43,24};   
  int length = sizeof(arr)/sizeof(arr[0]);

  nodeptr first = create(arr,length);
  printf("反轉前:\n");
  printlist(first);
  printf("\n");

  nodeptr InvList = invert(first);
  printf("反轉後:\n");
  printlist(InvList);


return 0;                                                        
}        

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

nodeptr invert(nodeptr first)
{
  nodeptr middle,trail=NULL;
  while(first!=NULL)
  {
    middle = first;
    first = first->link;
    middle->link = trail;
    trail = middle;
  }
  first = trail;
  return first;
}
