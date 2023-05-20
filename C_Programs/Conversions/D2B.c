// convert decimal to binary

#include <stdio.h>
#include <math.h>

int main()
{
  int n, bin=0, rem, i = 1;
  printf("Enter a decimal number: ");
  scanf("%d", &n);
  
  while (n!=0) 
  {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }
  printf("binary =  %d\n", bin);
  return 0;
}

