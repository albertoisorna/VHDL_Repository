/*
LIBRERIA .h para el keypad 
	Alberto Gonzalez Isorna
	25/12/17
*/

// Includes 
#include "xstatus.h"
#include "xgpio.h"
#include "xparameters.h"


// si cambiamos de periferico
#include "simon_periferico.h"
#define mi_baseaddr XPAR_SIMON_PERIFERICO_0_BASEADDR
#define KEYPAD_DEVICE XPAR_SIMON_PERIFERICO_0_DEVICE_ID
XGpio KYPAD_XGPIO;

// Prototipos Funciones KEYPAD
void GpioDriverHandler(void *CallBackRef);
int num_fila();
int inicia_keypad();
char leePKMOD ();

// Matriz
char MATRIZ[4][4]={{'1','2','3','A'},{'4','5','6','B'}, {'7','8','9','C'},{'0','F','E','D'}};


#define LED_DELAY	  10000000



//----------------- keypad ------------------
// un gpio con dos canales
#define KEYPAD_DATA_I *((volatile u32 *)(mi_baseaddr))
#define KEYPAD_TRI_I *((volatile u32 *)(mi_baseaddr+0x4))
#define KEYPAD_DATA_O *((volatile u32 *)(mi_baseaddr+0x8))
#define KEYPAD_TRI_O *((volatile u32 *)(mi_baseaddr+0xC))


// ------------------------------------------
//*((volatile u32 *)(XPAR_AGI_PLB_0_BASEADDR+0x04))


// ----------------------------------- Funcion inicializacion de KEYPAD
int inicia_keypad()
{
	// FIL -- INPUT
	KEYPAD_TRI_I = 0xFFFFFFFF;
	// COL -- OUTPUT
	KEYPAD_TRI_O = 0x00000000;
	return XST_SUCCESS;
}

// ----------------------------------  Funcion que extrae el numero de fila
int num_fila()
{
u32 dato;
u32 result;
volatile int Delay;
// Lectura de la fila
dato=SIMON_PERIFERICO_mReadSlaveReg1(mi_baseaddr, 0);
//dato=AGI_PLB_mReadSlaveReg0(baseaddr, 0);
putnum(dato);
print("\n\r");
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
		SIMON_PERIFERICO_mWriteSlaveReg0(mi_baseaddr, 0, (~(1<<col)));
		for (Delay = 0; Delay < LED_DELAY; Delay++);
		// leemos la fila activa
		fil=num_fila(); 
		if(fil!=0) 
			{	
		   while(num_fila()==fil); //esperamos a soltar el boton (suponemos que estamos manteniendo el mismo)
				num=MATRIZ[fil-1][col];
				break;
			}
		}
	}
	return num;
}

