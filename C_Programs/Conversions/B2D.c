#include<stdio.h>
#include<math.h>

int main()
{
	int dec=0, i=0, rem,n;

	printf("Enter a Binary Numbe: ");
	scanf("%d", &n);

	while(n != 0)
	{
		rem = n % 10;
		dec = dec + rem *pow(2, i);
		n = n/10;
		++i;
	}

	printf("%d\n", dec);
	return 0;
}
