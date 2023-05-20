#include<stdio.h>
int add(int,int);
int sub(int,int);
int mul(int,int);
int main()
{
	int a,b;
	printf("enter the number\n");
	scanf("%d %d",&a,&b);
	printf("addition= %d\n",add(a,b));
	printf("subtraction= %d\n",sub(a,b));
	printf("multilication=%d\n",mul(a,b));
}



