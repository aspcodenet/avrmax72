/*
 * Tetris_V1.c
 *
 * Created: 06/04/2021 19:41:36
 * Author : dakak
 */  

#include "max72xx.h"
#include "uart.h"
#include <stdio.h>
#include <string.h>
#include <util/delay.h>





int main()
{
	init_serial();
	max7219_init();
	int x = 0;
	int y = 0;
	for (;;) {
		for(int i = 0; i < 16;i++){
			printf("%d\n", i);
			max7219b_set(i, y);
			max7219b_out();
				_delay_ms(1000);
		}
			// for (uint8_t x = 0; x <= MAX7219_SEG_NUM * 8 - 1; x++) {
			// 		max7219b_set(x, y);		// Set the pixel
			// 		max7219b_out();			// Output the buffer.
			// 	// for (int8_t y = 0; y <= 7; y++) {
			// 	// 	_delay_ms(20);
			// 	// 	max7219b_clr(x, y);		// Clear the pixel
			// 	}
			}
	return 0;
}