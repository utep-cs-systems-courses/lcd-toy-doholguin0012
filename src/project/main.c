// this is tha main file for will be running
#include <msp430.h>
#include <libTimer.h>
#include "swithces.h"
#include "screen.h"
#include "lcdutils.h"
#include "lcddraw.h"

#define LED BIT6

void main(void)
{
  P1DIR |= LED;
  P1OUT |= LED;

  configureClocks();
  lcd_init();
  switch_init();

  enableWDTInterrupts(); /* enables periodic interrupt*/
  or_sr(0x8);            /* GIE (enable interrupts) */

  clearScreen(Color_Black);
  drawMiddleDashLine();

  while(1) {
    if(redrawScree) {
      redrawScreen = 0;
      update_shape();
    }
    P1OUT &= ~LED;
    or_sr(0x10);
    P1OUT |= LED;
  }
  
}
