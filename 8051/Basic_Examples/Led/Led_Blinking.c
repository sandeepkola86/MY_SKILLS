#include<reg52.h>			//special function register declarations
void delay();
sbit LED0=P2^0;
sbit LED1=P2^1;
sbit LED2=P2^2;
sbit LED3=P2^3;
sbit LED4=P2^4;
sbit LED5=P2^5;
sbit LED6=P2^6;
sbit LED7=P2^7;
void main()					//Main Code
{
	P1=0x00;
	while(1)
	{
			LED0=1;
			delay();

			LED1=1;
			delay();

			LED2=1;
			delay();
			
			LED3=1;
			delay();

			LED4=1;
			delay();

			LED5=1;
			delay();

			LED6=1;
			delay();

			LED7=1;
			delay();

			P1=0x00;
			delay();
	}
}
void delay()
{
			unsigned int x=60000;
			while (x--);
}