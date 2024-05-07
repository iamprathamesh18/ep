/* IR sensor P0.30   buzzer P1.20    */


#include<lpc214x.h>

void delay(unsigned int time)
{
unsigned int i,j;
	
	for(i = 0; i < time ;i++ )
	{
		for(j = 0; j < 5000 ; j++);
	}
}

int main (void)
{
	unsigned int sensor;
	
	PINSEL2 = 0x00000000;
	IODIR1 |= 1<<20;			//set direction of buzzer as output
	IODIR1 &= 0xBFFFFFFF; //set direction for IR sensor as input
	
	while(1)
	{
		sensor = (IO0PIN & (1 << 30));
		if(sensor)
		{	
		IOSET1 |= 1<<20;
		delay(1500);
		}
		else
		{
			IOCLR1 |=1<<20;
		}
	}
}

