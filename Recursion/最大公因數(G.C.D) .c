#include <stdio.h>
#include <stdlib.h>
/** GCD **/

// recursion:
int gcd(int x,int y){
  if(y) return gcd(y,x%y);
  else  return x;

}

/*
 
 // iterative approach

int gcd(int x,int y)
{
  while(y){
    int z=x%y;x=y;y=z;
  }
  return x;
}
*/

int main(void){
	int a,b;
	printf("請輸入數值：");
	scanf("%d,%d",&a,&b);
	printf("gcd(%d,%d) = %d\n",a,b,gcd(a,b));	

return 0;
}