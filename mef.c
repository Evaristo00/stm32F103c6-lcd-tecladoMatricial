#include "MEF.h"


typedef enum {cerrado,abierto,ingresar_contra,denegado} state_name;
	
//constantes

//Variables Privadas
static state_name actual_state;
static uint8_t time_state= 0;
static uint8_t hora=0,min=0,seg=0,cantTiempo = 0;
static uint8_t stringTime[8]= {0,0,':',0,0,':',0,0};
static uint8_t clave[4] = {4,3,2,1};

//funciones privadas
void actualizarTiempo(void);
void prepararHora(void);
void processAbierto(void);
void processCerrado(void);
void processDenegado(void);


void MEF_Init(){
	actual_state = cerrado;
}


void MEF_Update(){
	
	if (++cantTiempo == 10){	//actualizo cada 1s
		actualizarTiempo();
		cantTiempo =0;
	}
	switch(actual_state){
		case cerrado:
			processCerrado();
		break;
		case abierto:
			processAbierto();
		break;
		case denegado:
			processDenegado();
		break;
		case ingresar_contra:
			processIngresarContra();
		break;
	}
}

void prepararHora(){
	stringTime[0] = ((hora/10)% 10) + 48;
	stringTime[1] = (hora % 10) +48;
	stringTime[3] = ((min/10)% 10) + 48;
	stringTime[4] = (min % 10) + 48;
	stringTime[6] = ((seg/10)% 10) + 48;
	stringTime[7] = (seg % 10) +48;
	
	LCDGotoXY(0,0);
	LCDstring(stringTime,8);
}
void actualizarTiempo(){
	if(++seg == 60)
	{
		seg = 0;
		if(++min == 60)
		{
			min =0;
			if(++hora == 24)
			{
				hora=0;
			}
		}
	}
}

void processCerrado(){
	
}
