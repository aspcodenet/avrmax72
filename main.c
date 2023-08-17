#include "max72xx.h"
#include "uart.h"
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

//s
//// https://wokwi.com/projects/296234816685212169

 
int main()
{
	init_serial();
	max7219_init();
	int x = 0;
	int y = 0;

	max7219b_out();

	while (1) {

		//ER UPPGIFT
		// Skriv kod som blir mer generisk
		// function writeLetter(x,y, clear Y/N)

		max7219b_clr(3,2);
		max7219b_clr(3,3);
		max7219b_clr(3,4);
		max7219b_clr(3,5);
		max7219b_clr(3,6);

		max7219b_set(1,2);
		max7219b_set(1,3);
		max7219b_set(1,4);
		max7219b_set(1,5);
		max7219b_set(1,6);


		max7219b_set(5,2);
		max7219b_set(5,3);
		max7219b_set(5,4);
		max7219b_set(5,5);
		max7219b_set(5,6);

		max7219b_set(2,4);
		max7219b_set(3,4);
		max7219b_set(4,4);

		max7219b_out();
		_delay_ms(1000);

		
		max7219b_clr(1,2);
		max7219b_clr(1,3);
		max7219b_clr(1,4);
		max7219b_clr(1,5);
		max7219b_clr(1,6);


		max7219b_clr(5,2);
		max7219b_clr(5,3);
		max7219b_clr(5,4);
		max7219b_clr(5,5);
		max7219b_clr(5,6);

		max7219b_clr(2,4);
		max7219b_clr(3,4);
		max7219b_clr(4,4);


		max7219b_set(3,2);
		max7219b_set(3,3);
		max7219b_set(3,4);
		max7219b_set(3,5);
		max7219b_set(3,6);

		max7219b_out();


		_delay_ms(1000);

	}
	return 0;
}