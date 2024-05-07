#include<LPC214x.h>
#include<stdio.h>
void delay(void);
void delay(void)
{
	int i, j;
	for(i=0;i<2000;i++)
	for(j=0; j<2000; j++);
}
void Uart0Init(void)  //Initialize Serial Interface
	{
		PINSEL0 = 0x00000005; // Enable TxD0(P0.0) & RxD0(P0.1) 
		U0LCR = 0x83;  // 8 bits data, No parity, 1 Stop bit
		U0DLL = 97; // 9600 Baud rate @ 15MHz PCLK
		U0LCR = 0x03;
		U0DLM = 0;
	}
	
	unsigned char Uart0GetCh(void) //Read a character from RxD
	{
		while(!(U0LSR & 0x01));
		return(U0RBR);
	}
	void Uart0PutCh(unsigned char ch) // Write a character to TxD
	{
		U0THR = ch;
		while(!(U0LSR & 0x20));
	}
void Uart0PutS(unsigned char *str)
{
while(*str)
{
Uart0PutCh(*str++);
}
}
int main()
{
	int adcdata;
	float voltage;
	unsigned char volt[3];
	PINSEL0=0X00000000;
	PINSEL1 = 0x01000000;
	Uart0Init();
	AD0CR = 0x00210402;
  while(1)
	{
		if(AD0DR1 & 0x80000000)
		{			
		adcdata = (AD0DR1 & 0x0000FFC0);
		adcdata = adcdata>>6;
    voltage = ((adcdata/1023.0) * 3.3 );
			sprintf(volt, "%.1f",voltage);
			Uart0PutS("\n ADC o/p: ");
			Uart0PutS(volt);
			delay();
		}
	}
}
