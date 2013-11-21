#include <msp430.h> 
#include "robotMotion.h"
/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR|=BIT1; //TA0.0
	P1DIR|=BIT2; //TA0.1
	P2DIR|=BIT0; //TA1.0
	P2DIR|=BIT1; //TA1.1

	P1SEL|=BIT1;
	P1SEL|=BIT2;
	P2SEL|=BIT0;
	P2SEL|=BIT1;


	TA0CTL &= ~MC1|MC0;            // stop timer A0

	TA0CTL |= TACLR;                // clear timer A0

	TA0CTL |= TASSEL1;           // configure for SMCLK

	TA1CTL &= ~MC1|MC0;            // stop timer A0

	TA1CTL |= TACLR;                // clear timer A0

	TA1CTL |= TASSEL1;           // configure for SMCLK



	TA0CCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 50;                // set duty cycle to 50/100 (50%)




	TA1CCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR1 = 50;                // set duty cycle to 50/100 (50%)

	TA0CTL |= MC0;                // count up

	TA1CTL |= MC0;
	//go the other way code
		/*TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset

		TA1CCTL1 |= OUTMOD_7;*/

	moveForward();
	//while (1) {
	//	__delay_cycles(1000000);
	//	TA0CCTL1 &= ~OUTMOD_7;        // clear mode
		//	TA0CCTL0 &= ~OUTMOD_7;		 // clear mode
//
	//		TA1CCTL1 &= ~OUTMOD_7;  //clear mode
		/*	TA1CCTL0 &= ~OUTMOD_7;  //clear mode

		TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
			TA1CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset

			TA0CCTL1 |= OUTMOD_7;*/
			//TA1CCTL0 |= OUTMOD_7;

			//TA0CCR0 = 100;
	    	//__delay_cycles(1000000);
	       // TA1CCR1 = 0;            // set duty cycle to 75/100 (75%)
	        /*__delay_cycles(1000000);
	        TACCR1 = 100;            // set duty cycle to 100/100 (100%)
	        __delay_cycles(1000000);
	        TACCR1 = 25;            // set duty cycle to 25/100 (25%)*/
	   // }
	
}
