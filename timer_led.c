#include<LPC214x.h>
#include"pll.h"
int main(void)
{
	IO1DIR = IO1DIR | (1<<24);//Make P0.0 an o/p pin
	pll();//Fosc=12MHz, CCLK=60MHz, PCLK=60MHz
	while(1)
	{
		IO1SET = IO1SET | (1<<24);
		delayms(500);//0.5s ON
		IO1CLR = IO1CLR | (1<<24);
		delayms(500);
	}
}
	