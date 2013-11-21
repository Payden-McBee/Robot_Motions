#include <msp430.h> 
#include "robotMotion.h"
/*
 * example.c
 */
void example(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initTimerOutputSignals();
	 configureA0andA1Timers();


	 	 __delay_cycles(1000000); //wait before the first instruciton so i have time to get away from the robot before it starts moving

	moveForward();

		__delay_cycles(1000000); //delays between each movement to differentiate which movement is which

	moveBackward();

		__delay_cycles(1000000);

	turnSmallRight();

		__delay_cycles(1000000);

	turnSmallLeft();

		__delay_cycles(1000000);

	turnBigLeft();

		__delay_cycles(1000000);

	turnBigRight();
	
		__delay_cycles(1000000);

}
