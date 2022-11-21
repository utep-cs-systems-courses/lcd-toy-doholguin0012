/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);
  /*nt row =50, col = 60;
  for(int c=0; c < 20;c++)
    for(int r = 0; r <=c; r++)
      {
      drawPixel(col + c, row + r,COLOR_PINK);//line code.
      drawPixel(col - c, row + r,COLOR_PINK);
      drawPixel(col - c, row - r,COLOR_PINK);
      drawPixel(col + c, row - r,COLOR_PINK);
      }
      drawPixel(col, row, COLOR_WHITE);*/

  int fcol=0, frow =10, v = 1, a=1;
  while (fcol < 100)
    {
      if(fcol >=0 && fcol < screenWidth && frow >=0 && frow < screenHeight)
	drawPixel(fcol, frow, COLOR_YELLOW);
      fcol++;
      if (frow + v > 100)
	v = - v;
      frow += v;
      v +=a;
    }
  drawPixel(fcol, frow, COLOR_WHITE);
  /*drawPixel(25,50, COLOR_PINK);*/
  /*drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

    fillRectangle(30,30, 60, 60, COLOR_ORANGE);*/
  

  
}
