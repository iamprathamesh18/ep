//Triangular Waveform Generator
#include<LPC214x.h>
void delay()
{
int i;
for(i=0; i<5;i++);
}
int main(void)
{
int j;
PINSEL1 = 0x80000;
IODIR0 = 0x80000;
delay();
while(1)
{
for(j=0x00; j<=0x3FF; j++)
{
DACR = (j<<6);
	delay();
};
for(j=0x3FF; j>=0x00; j--)
{
DACR = (j<<6);
	delay();
}
}
}
