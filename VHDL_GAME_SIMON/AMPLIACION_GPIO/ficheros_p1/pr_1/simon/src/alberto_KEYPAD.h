/*
LIBRERIA .h para el keypad 
	Alberto Gonzalez Isorna
	25/12/17
*/

// Includes 
#include "xstatus.h"
#include "xgpio.h"
#include "xparameters.h"
#include "agi_plb.h"

// Prototipos Funciones KEYPAD
void GpioDriverHandler(void *CallBackRef);
int num_fila();
int inicia_keypad();
char leePKMOD ();

// Matriz
char MATRIZ[4][4]={{'1','2','3','A'},{'4','5','6','B'}, {'7','8','9','C'},{'0','F','E','D'}};




//----------------- keypad ------------------
// un gpio con dos canales
#define KEYPAD_CHANNEL_I 1
#define KEYPAD_CHANNEL_O 2
#define KEYPAD_DEVICE XPAR_AGI_PLB_0_DEVICE_ID
XGpio KYPAD_XGPIO;
// ------------------------------------------
//*((volatile u32 *)(XPAR_AGI_PLB_0_BASEADDR+0x04))


// ----------------------------------- Funcion inicializacion de KEYPAD
int inicia_keypad()
{
	int Status;
	// inicializamos inputs FIL y outputs COL
	Status = XGpio_Initialize(&KYPAD_XGPIO, KEYPAD_DEVICE); 	
	putnum(Status);
	if (Status != XST_SUCCESS)
	 return XST_FAILURE;
	// FIL
	XGpio_SetDataDirection(&KYPAD_XGPIO,KEYPAD_CHANNEL_I,0xF); 
	// COL
	XGpio_SetDataDirection(&KYPAD_XGPIO,KEYPAD_CHANNEL_O,0x0);
	return XST_SUCCESS;
}

// ----------------------------------  Funcion que extrae el numero de fila
int num_fila()
{
u32 dato;
u32 result;
volatile int Delay;
// Lectura de la fila
dato=XGpio_DiscreteRead(&KYPAD_XGPIO,KEYPAD_CHANNEL_I); // ej 0000000 1101(32 bits (26 + 4 de las filas))
// Conversion a entero
switch(dato)
	{
	case 15: result=0; break;
	case 14: result=1; break;
	case 13: result=2; break;
	case 11: result=3; break;
	case 7:  result=4; break;
	default: result=0; break;
	}
return result;
}

// ----------------------------------- Funcion Global que lee el char del keypad
char leePKMOD ()
{
	char num='X';
	u32 col;
	int fil=0;
	volatile int Delay;
	// bucle
	while (fil==0)
	{
	for (col=0x0;col<4;col++)
		{
		XGpio_DiscreteWrite(&KYPAD_XGPIO, KEYPAD_CHANNEL_O, (~(1<<col)));
		// leemos la fila activa
		fil=num_fila(); 
		if(fil!=0) 
			{	
		   while(num_fila()==fil); //esperamos a soltar el boton (suponemos que estamos manteniendo el mismo)
				num=MATRIZ[fil-1][col];
				break;			}
		}
	}
	return num;
}

