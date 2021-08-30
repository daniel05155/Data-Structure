# include<stdio.h>
# include<stdlib.h>
 
int fac(int n)
{
	if(n==1)
		return 1;
	else
		return n*fac(n-1); 
 } 
 
int main(void)
{	
	int a;
	printf("請輸入欲計算的階乘：");
	scanf("%d",&a);
	printf("%d!=%d\n",a,fac(a));
system("pause");
return 0;	
}
