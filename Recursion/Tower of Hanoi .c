#include <stdio.h>
#include <stdlib.h>
/* Tower of Hanoi*/
/*
學習:
1. https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
2.
https://kopu.chat/2017/08/19/%E9%81%9E%E8%BF%B4-recursive-%E4%BB%8B%E7%B4%B9%E8%88%87%E7%B6%93%E5%85%B8%E9%A1%8C%E5%9E%8B/
*/

void Hanoi(int x,char source,char temp,char dest)
{
  if(x==1) printf("move disk%d from %c to %c\n",x,source,dest);
  else{
    Hanoi(x-1,source,dest,temp);
    printf("move disk%d from %c to %c\n",x,source,dest);
    Hanoi(x-1, temp, source,dest);
 } 
}

int main()
{
  int x;
  printf("請輸入河內塔高度: ");
  scanf("%d",&x);

  Hanoi(x,'A','B','C');
  

 return 0;
}