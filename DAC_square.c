#include<LPC214x.h>
void delay()
{
int i;
for(i=0; i<80000;i++);
}
int main(void)
{
PINSEL1 = 0x80000;
IODIR0 = 0x80000;
delay();
while(1)
{
DACR = (0x3FF<<6);
delay();
DACR = (0X0000<<6);
delay();
}
delay();
return 0;
}
