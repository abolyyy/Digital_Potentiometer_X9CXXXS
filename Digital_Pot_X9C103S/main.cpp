/*
 * Digital_Pot_X9C103S.cpp
 *
 * Created: 9/9/2022 5:56:47 PM
 * Author : win-10
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include "Library/global.h"
#include "Library/DgitalDigital_Pot_X9CXXXS/Digital_Pot_X9CXXXS.h"

# define F_CPU 1000000UL

int main(void)
{

/************************************************************************/
/* Key' pin configuration "Key_Up"==>PD3 "Key_Down"==>PD4				*/
/************************************************************************/
	DDRD |= (0<<4) | (0<<3);
	DDRD |= (1<<0) | (1<<1) | (1<<2);
	PORTD|= (1<<4) | (1<<3);
	DPX9CXXXS_Init();
    while (1)
    {		
		
		if (!CHECKBIT(PIND,3))
		{
			Pot_Up(1);
			_delay_ms(100);
			
		}else if (!CHECKBIT(PIND,4))
		{
			Pot_Down(1);
			_delay_ms(100);	
		}
		
    }
}

