/*
 * robotMotion.c
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Payden.McBee
 */
#include <msp430g2553.h>
#include "robotMotion.h"

void clearModes()
{
	TA0CCTL1 &= ~OUTMOD_7;        // clear mode
	TA0CCTL0 &= ~OUTMOD_7;		 // clear mode

	TA1CCTL1 &= ~OUTMOD_7;  //clear mode
	TA1CCTL0 &= ~OUTMOD_7;  //clear mode
}

void turnSmallRight()
{
	clearModes();
	TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset mode
	TA0CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset/Set

	TA1CCTL1 |= OUTMOD_7; //reset/set
	__delay_cycles(2000000);
	clearModes();
}

void turnBigRight()
{
	clearModes();
	TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset mode
	TA0CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset/Set

	TA1CCTL1 |= OUTMOD_7; //reset/set
	__delay_cycles(4000000);
	clearModes();
}

void turnSmallLeft()
{
	clearModes();
	TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset

	TA0CCTL1 |= OUTMOD_7;
	__delay_cycles(2000000);
	clearModes();
}

void turnBigLeft()
{
	clearModes();
	TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset

	TA0CCTL1 |= OUTMOD_7;
	__delay_cycles(4000000);
	clearModes();
}

void moveForward()
{
	clearModes();
	TA1CCTL1 |= OUTMOD_7; //reset/set
	TA0CCTL1 |= OUTMOD_7; //reset/set
}

void moveBackward()
{
	clearModes();
	TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset mode
	TA1CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset/Set
	TA0CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset mode
	TA0CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset/Set
}
//functions

