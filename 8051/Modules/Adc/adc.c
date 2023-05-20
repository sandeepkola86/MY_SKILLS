#include <reg51.h>
#include <stdio.h>

sbit ale=P3^3;  
sbit oe=P3^6; 
sbit start=P3^4; 
sbit eoc=P3^5;  
sbit clk=P3^7;  
sbit ADDA=P3^0;  //Address pins for selecting input channels.
sbit ADDB=P3^1;
sbit ADDC=P3^2;
#define lcd P2  //lcd 
sbit rs=P2^0;
sbit rw=P2^2;
sbit en=P2^1;
#define Adc_Data P1  //ADC

char result[3];
int ADC_value;

/*
We will give the clock for the ADC module using our controller itself s, 
for that, we have made a Function to generate a clock of frequency 500KHZ using Timer 0 interrupt.
*/

void timer0() interrupt 1 
{
    clk=~clk;
}

/*
Functions are made for delay and LCD.
*/

void delay(unsigned int count) 
{
    int i,j;
    for(i=0;i<count;i++)
    for(j=0;j<100;j++);
}

void lcd_data(unsigned char ch)
{
    rs=1;
    rw=0;
    lcd=ch & 0xF0;
    en=1;
    delay(1);
    en=0;
    lcd=ch<<4 & 0xF0;
    en=1;
    delay(1);
    en=0;
}

void lcdcmd(unsigned char ch)
{
    rs=0;
    lcd=ch & 0xf0;
    en=1;
    delay(1);
    en=0;
    lcd=ch<<4 & 0xF0;
    en=1;
    delay(1);
    en=0;
}

void lcdprint(char *str) //Function to send string data to LCD.
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}

void lcd_init() //Function to inisialize the LCD
{
    lcdcmd(0x02);
    lcdcmd(0x28);
    lcdcmd(0x0e);
    lcdcmd(0x01);
}

/*
In the function adc() first, the required channel is chosen using ADD A, ADD B and ADD C pins. 
After which read_adc() function is called. In read_adc() function, we wait for the conversion and 
the output is given to the variable ADC_value. which is then displayed after converting to string.
*/

void show()
{ 
sprintf(result,"%d",ADC_value);
lcdprint(result);
lcdprint(" ");
}

void read_adc() //Function to drive ADC
{
    ADC_value=0;
    ale=1;
    start=1;
    delay(1);
    ale=0;
    start=0;
    while(eoc==1);
    while(eoc==0);
    oe=1;
    ADC_value=Adc_Data;
    delay(1);
    oe=0;
}

void adc() 
{
    ADDC=0; // Selecting input channel IN0 using address lines
    ADDB=0;
    ADDA=0;
    lcdcmd(0xc0);
    read_adc();
    show();
}

/*
In the main function timer 0 interrupt is configured for the clock to drive ADC0808. LCD and the ADC0808 is also initialized.
A while(1) loop has been created to read and display the ADC value again and again.
*/
void main()
{
    eoc=1;
    ale=0;
    oe=0;
    start=0;
    TMOD=0x02;
    TH0=0xFD;
    lcd_init();
    IE=0x82;
    TR0=1;
    while(1)
    {
        adc();
        ADC_value=0;
    }
 }