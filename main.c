#include "stm32f10x.h"

static volatile uint8_t cont_MEF = 0,Flag_MEF = 0;


int main(void)
{
    //inicializar lcd
		//inicializar teclado matricial
		//inicializar mef
		//inicializar y activar interrupciones con timer
    while (1) { 
	    if (Flag_MEF) {
		    //MEF_Update();
		    Flag_MEF=0;
	    }
    }
}
/*
ISR (TIMER0_COMPA_vect)
{
	if (++cont_MEF==25) {	
		Flag_MEF=1;			//se ejecuta cada 100ms
		cont_MEF = 0;
	}
}*/