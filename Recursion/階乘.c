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
	printf("�п�J���p�⪺�����G");
	scanf("%d",&a);
	printf("%d!=%d\n",a,fac(a));
system("pause");
return 0;	
}
