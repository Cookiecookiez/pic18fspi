#include <xc.h>
#define _XTAL_FREQ 20000000
void main(void) 
{
    ADCON1=0X0F;
    CMCON=0X07;
    TRISA=0X00;
    TRISC=0X10;
    TRISD=0x00;
    SSPIF=0;
    SSPSTAT=0b11000000;
    SSPCON1=0X12;
    SSPCON1bits.SSPEN=1;
    while(1)
    {
        LATDbits.LATD5=0;
        SSPBUF='0';
        while(SSPIF==0);
        SSPIF=0;
        LATDbits.LATD5=1;
       __delay_ms(1000);
    }
    return;
}
