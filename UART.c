#include<LPC214x.h>

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
	unsigned char a;
	unsigned char b = '$';
	Uart0Init();
	while(1)
	{
		a = Uart0GetCh();
		Uart0PutCh(b);
		Uart0PutCh(a);
		
	}
}
