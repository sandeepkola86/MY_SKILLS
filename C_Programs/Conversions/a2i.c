#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{ 
char  *str="abcd 123%@",i;
for(i=0;i<strlen(str);i++)
{
   int integer =str[i]-0;
  printf("%d\t",integer);         
}
 
    return 0;
}

