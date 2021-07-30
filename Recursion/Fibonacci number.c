#include <stdio.h>
#include <stdlib.h>

Recursion�G
int fib(int x)
{
  if(x==0||x==1) return x;
  return fib(x-1)+fib(x-2);
}


/*
// non-recursive way�G

int fib(int x)
{
  if(x==0) return 0;
  else if(x==1) return 1;
  else{
    int a=0,b=1,c;
  for(int i=2;i<=x;i++){
    c = a+b;
    a = b;
    b = c; 
  }
  return b;
  } 
}

*/

int main(void){
	int x;
	printf("�п�J���p�⪺�O���ƦC���ȡG");
	scanf("%d",&x);
	printf("fib(%d) =%3d\n",x,fib(x));	
	

return 0;
}