/*
Button based delay - G2553
Author: Kevin Beenders
credit to Cameron K
 */

#include <msp430.h>


void main(void) {

  WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer

  P1DIR |= BIT0;                   // Set P1.0 to output direction
  P1OUT &= ~BIT0;                  // Set the red LED off

  P4DIR |= BIT7;                   // Set P4.7 to output direction
  P4OUT &= ~BIT7;                  // Set the green LED off

  TA0CCR0 = 12000;                 // Count limit (16 bit)
  TA0CCTL0 = 0x10;                 // Enable Timer A0 interrupts, bit 4=1
  TA0CTL = TASSEL_1 + MC_1 + ID_1;        // Timer A0 with ACLK, count UP

  TA1CCR0 = 64000;                 // Count limit (16 bit)
  TA1CCTL0 = 0x10;                 // Enable Timer A1 interrupts, bit 4=1
  TA1CTL = TASSEL_1 + MC_1 + ID_1; // Timer A1 with ACLK, count UP
  _BIS_SR(LPM0_bits + GIE);        // LPM0 (low power mode) interrupts enabled

}

#pragma vector=TIMER1_A0_VECTOR    // Timer1 A0 interrupt service routine

  __interrupt void Timer1_A0 (void) {

   P1OUT ^= BIT0;                  // Toggle green LED
}

#pragma vector=TIMER0_A0_VECTOR    // Timer0 A0 interrupt service routine

  __interrupt void Timer0_A0 (void) {

   P4OUT ^= BIT7;                  // Toggle red LED
}
