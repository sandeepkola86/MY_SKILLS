#include<reg51.h>
#define LCD_PORT P2

sbit rs=P3^5;
sbit en=P3^7;
sbit D7=P2^7;
sbit rw=P3^6;
sbit key1=P0^3;
sbit key2=P0^2;
sbit key3=P0^1;
sbit key4=P0^0;

void busy();
void CMD_WRT(unsigned char);
void LCD_WRT(unsigned char *);
void DATA_WRT(unsigned char);
void DELAY();
void main()
{
	unsigned char CMD[]={0x38,0x0f,0x01,0x06,0x80};
	unsigned char TEMP,i;
	for(i=0;i<=4;i++)
	{
		TEMP=CMD[i];
		CMD_WRT(TEMP);
	}
	CMD_WRT(0X01);
	CMD_WRT(0X80);
	LCD_WRT("RDL");
	DELAY();
	DELAY();
	DELAY();
	DELAY();
	while(1)
	{
		if (key1 ==0)
		{
			CMD_WRT(0X01);
			CMD_WRT(0X80);
			LCD_WRT("Key 1 is pressed");
			while(key1==0);
		}
		else if (key2 ==0)
		{
			CMD_WRT(0X01);
			CMD_WRT(0X80);
			LCD_WRT("Key 2 is pressed");
			while(key2==0);
		}
		else if (key3 ==0)
		{
			CMD_WRT(0X01);
			CMD_WRT(0X80);
			LCD_WRT("Key 3 is pressed");
			while(key3==0);
		}
		else if (key4 ==0)
		{
			CMD_WRT(0X01);
			CMD_WRT(0X80);
			LCD_WRT("Key 4 is pressed");
			while(key4==0);
		}
		else
		{
			CMD_WRT(0X01);
			CMD_WRT(0X80);
			LCD_WRT("No key Pressed");
			DELAY();
			DELAY();
			DELAY();
		}
	}
}
void busy()
{
	D7=1;
	rs=0;
	rw=1;
	while(D7!=0)
	{
		en=0;
		en=1;
	}
}
void CMD_WRT(unsigned char val)
{
		busy();
		LCD_PORT=val;
		rs=0;
		rw=0;
		en=1;
		en=0;
}
void LCD_WRT(unsigned char *string)
{
		while(*string)
		DATA_WRT(*string++);
}
void DATA_WRT(unsigned char ch)
{
		busy();
		LCD_PORT = ch;
		rs=1;
		rw=0;
		en=1;
		en=0;
}
void DELAY()
{
		unsigned int X=60000,Y=60000;
		while(X--);
		while(Y--);
}