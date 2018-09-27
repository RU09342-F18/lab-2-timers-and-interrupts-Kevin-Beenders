//authored by Kevin Beenders
//Credit to embeddedprojecthunter


#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;   //disables watchdog timer
    P1DIR = BIT6;
    P2REN = BIT1;
    P2OUT = BIT1;
    P2IE = BIT1;                //enables button as an interrupt case
    __enable_interrupt();
    while(1){  }
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)   //interrupt function
{
    __delay_cycles(500000);
    P1OUT ^= BIT6;              //toggles LED
    P1IFG = ~BIT3;
}
