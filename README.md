# Lab6
Documentation: C1C Snyder and I worked on the initial code for making the robot move together. We also shared timing 
for the turns. 

## Basic Robot Motions
Example code: This code will demonstrate each funciton and show how to set up and configure the timers.

```c
#include <msp430.h> 
#include "robotMotion.h"
/*
 * main.c
 */
void main(void) {
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
```

## Notes

- Difference between the turns (big and small) is only one of timing. I change the time they are allowed to turn.
- `moveForward` has a longer time and a larger duty cycle than moveBakcward because there is a knob which slows the robot 
down as it moves forward. I want to make their distances closer to even. 
