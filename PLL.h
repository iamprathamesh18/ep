void delayms(unsigned int z);
void pll(void);
void pll()
{
	PLL0CFG = 0x24;//Set PSEL=2 & MSEL=5
	PLL0CON = 0x01;// PLL is active but not yet connected.
	PLL0FEED = 0xAA;// Feed sequence
	PLL0FEED = 0x55;
	while(!(PLL0STAT & (1<<10)));//Wait for Feed sequence to be inserted.
	PLL0CON = 0x03;//PLL is active & is being connected
	PLL0FEED = 0xAA;//Feed sequence
	PLL0FEED = 0x55;
	VPBDIV = 0x01;//Set PCLK same as FCCLK
}
void delayms(unsigned int z)
{
	T0CTCR = 0x0;//Select Timer mode
	T0PR = 59999;//Prescalar value for 1 ms
	T0TCR = 0x02;//Timer reset
	T0TCR = 0x01;// Timer ON
	while(T0TC < z);
	T0TCR = 0x00;//Timer OFF
}