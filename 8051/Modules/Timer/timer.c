//Timer mode 1 for blinking LED using polling method
// XTAL frequency 11.0592MHz 
#include<reg51.h>
sbit led = P1^0; 				// LED connected to 1st pin of port P1
void delay();

main()
{
	unsigned int i;
	while(1)
	{
	led=~led; 				// Toggle LED
	for(i=0;i<1000;i++)
	delay();				// Call delay
	}
}

void delay()					// Delay generation using Timer 0 mode 1
{
	TMOD = 0x01;				// Mode1 of Timer0
	TH0= 0xFC;  				// FC66 evaluated hex value for 1millisecond delay
	TL0 = 0x66;
	TR0 = 1;   				// Start Timer
	while(TF0 == 0); 			// Using polling method
	TR0 = 0; 				// Stop Timer
	TF0 = 0; 				// Clear flag
}