#include<LPC214x.h>
unsigned int i;
void delay(unsigned int);
unsigned int arr[]={0x000000C0, 0x000000F9, 0x000000A4, 0x00000B0, 0x00000099, 0x00000092, 0x000082, 0x000000F8, 0x00000080, 0x00000010};
int main()
{
	IO1DIR = 0xFFFFFFF;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			IO1SET = arr[i]<<16;
			delay(9000);
			IO1CLR = arr[i]<<16;
		}
	}
}
void delay(unsigned int k)
{
	int i, j;
	for(i=0; i<k;i++)
	for(j=0; j<=1000;j++);
}