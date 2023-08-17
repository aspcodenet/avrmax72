#include "max72xx.h"
#include "uart.h"
#include "analogRead.h"
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>
#include "millis.h"
#include <util/delay.h>
#include <stdbool.h>

#define VERT_PIN 0
#define HORZ_PIN 1


#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


//3 * 3

void clear(){
	for(int col =3; col<6;col++)
	{
		max7219b_clr(col,3);
		max7219b_clr(col,4);
		max7219b_clr(col,5);
	}
}

void draw(int tal){
	if(tal == 1){
		max7219b_set(4,4);
	}
	else if(tal == 2){
		max7219b_set(3,3);
		max7219b_set(5,5);
	}
	else if(tal == 3){
		max7219b_set(3,3);
		max7219b_set(4,4);
		max7219b_set(5,5);
	}
	else if(tal == 4){
		max7219b_set(3,3);
		max7219b_set(3,5);
		max7219b_set(5,3);
		max7219b_set(5,5);
	}
	else if(tal == 5){
		max7219b_set(3,3);
		max7219b_set(3,5);
		max7219b_set(4,4);
		max7219b_set(5,3);
		max7219b_set(5,5);
	}
	else if(tal == 6){
		max7219b_set(3,3);
		max7219b_set(3,4);
		max7219b_set(3,5);
		max7219b_set(5,3);
		max7219b_set(5,4);
		max7219b_set(5,5);
	}
	max7219b_out();
}

//s
//// https://wokwi.com/projects/296234816685212169

// senaste kaffet = 10:53
 // 10:58
int main()
{
	BIT_CLEAR(DDRC,VERT_PIN);
	BIT_CLEAR(DDRC,HORZ_PIN);


 	millis_init();
    sei();

	init_serial();
	max7219_init();
	int x = 0;
	int y = 0;

	
	

	volatile millis_t antalMilliSekunderSenasteBytet = 0;
	bool first = true;
	int tal = 1;
	bool change = true;

	// stdout är som en vattenkran 
	// printf jobbar mot vattenkranar

	// kompilerar mot PC stdout -> terminalen

	// wire:a om så att stdout -> vad vi vill -> SERIAL

	uint32_t oldhorz = 0;
	uint32_t oldvert = 0;
	while (true) {
		//Läs joystick
		uint32_t horz = analogRead(HORZ_PIN);
  		uint32_t vert = analogRead(VERT_PIN);
		if(horz != oldhorz)
			printf("Horz:%d\n",horz);
		oldhorz = horz;	
		if(vert != oldvert)
			printf("Vert:%d\n",vert);
		oldvert = vert;

		if (horz < 300) {
			// RIGHT
			change = true;
			if(tal == 6){
				tal = 1;
			}
			else tal = tal + 1;
		}
		if (horz > 700) {
			// LEFT
			change = true;
			if(tal == 1){
				tal = 6;
			}

			else tal = tal - 1;
		}

		if (vert > 700) {
			// UP
			change = true;
			if(tal == 6){
				tal = 2;
			}
			else if(tal == 5){
				tal = 1;
			}
			else tal = tal + 2;
		}
		if (vert < 300) {
			// DOWN
			change = true;
			if(tal == 1){
				tal = 5;
			}
			else if(tal == 2){
				tal = 6;
			}
			else tal = tal - 2;

		}

		_delay_ms(100);
		
		


		// if (horz > 700) {
		// 	// RIGHT
		// 	change = true;
		// 	tal = tal + 1;
		// 	if(tal == 7){
		// 		tal = 1;
		// 	}
		// }
		// if (horz < 300) {
		// 	// LEFT
		// 	change = true;
		// 	tal = tal - 1;
		// 	if(tal == -1){
		// 		tal = 6;
		// 	}
		// }



		// sätt nytt tal   LEFT tal -1 RIGHT tal+1 UP tal+2 DOWN tal-2


		if( change )
		{
			change = false;
			//DAGS ATT GÖRA NÅT
			clear();
			draw(tal);
		}

	}
	return 0;
}