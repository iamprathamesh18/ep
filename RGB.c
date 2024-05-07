#include<lpc214x.h>

void delay(unsigned int time)
{
unsigned int i,j;
	for(i = 0; i < time ;i++ )
	{
		for(j = 0; j < 5000 ; j++);
	}
}

int main(void)
{
	int i;

  PINSEL2 = 0x00000000;
  IODIR1 |= 0x00F00000;	
	
	while(1)
	{
			IOSET1 |= 0x00F00000;
			IOCLR1 |= (1<< 21);	  //
			delay(5000);
	IOSET1 |= 0x00F00000;
		IOCLR1 |= (1<< 22);	  //
			delay(5000);
	IOSET1 |= 0x00F00000;
	IOCLR1 |= (1<< 23);	  //
			delay(5000);
	}

}

