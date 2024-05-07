#include<LPC214x.h>
void lcdcmd(unsigned int cmd);
void lcddata(unsigned int data);
void delay(unsigned int itime);
int main()
{
	unsigned int i = 0;
	unsigned char array[]= "MODERN COE, Shivajinagar, Pune-5";
	PINSEL0 = 0x00000000;
	PINSEL1 = 0x00000000;
	PINSEL2 = 0x00000000;//
	IODIR0 = 0x00100C00;// P0.10 EN,  P0.11 RS,  P0.20 RW
	IODIR1 = 0x00FF0000;// P1.16 to P1.23- D0 to D7 as outputs
	IOCLR0 = 0x00100C00;
	lcdcmd(0x38);// 16x2 LCD
	delay(100);
	lcdcmd(0x06);// Increment Cursor and shift Right
	delay(100);
	lcdcmd(0x01);// Clear Display Screen
	delay(100);
	lcdcmd(0x0E);// Display ON cursor ON
	delay(100);
	lcdcmd(0x80);// First row, first position
	delay(100);
	
	
	for(i=0; i<17 ; i++)
	{
		lcddata(array[i]);
		delay(1000);
	}

	lcdcmd(0xC0);
	delay(1000);
	
	for(i=16; i<32 ; i++)
	{
		
		lcddata(array[i]);
		delay(1000);
	}
	
	return 0;
}
void delay(unsigned int itime)
{
	int i,j;
	for(i=0; i<itime ; i++)
	for(j=0; j<200   ; j++);
}
void lcdcmd(unsigned int cmd)
{
	IOCLR1 = 0x00FF0000;
	cmd = cmd<<16; // Command to appear on P1.16-P1.23
	IOSET1 = cmd;
	IOCLR0 = 0x00000800;//RS=0 for Command Register 
	IOSET0 = 0x00000400;// Enable= 1
	delay(5000);
	IOCLR0 = 0x00000400;// Enable= 0
	delay(5000);
}
void lcddata(unsigned int data)
{
	IOCLR1 = 0x00FF0000;
	data = data<<16;//data to appear on P1.16 - P1.23
	IOSET1 = data;
	IOSET0 = 0x00000800;// RS= 1 for data Register 
	IOSET0 = 0x00000400;// Enable=1
	delay(5000);
	IOCLR0 = 0x000000400;//Enable=0
	delay(5000);
}

	
