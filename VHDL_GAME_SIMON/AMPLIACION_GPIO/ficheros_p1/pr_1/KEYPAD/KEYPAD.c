/*
FICHERO DEPURADO -- 21 12 17
CASI DEF
*/
/***************************** Include Files ********************************/
#include "xparameters.h"
#include "xgpio.h"
#include "stdio.h"
#include "xstatus.h"
#include "simon_periferico.h"
/************************** Constant Definitions ****************************/

#define LED_DELAY	  1000000

#define LED_CHANNEL 1// parameters.h

#define LED_MAX_BLINK	0x1	/* Number of times the LED Blinks */

#define GPIO_BITWIDTH	4	/* This is the width of the GPIO */

#define printf xil_printf	/* A smaller footprint printf */


#define GPIO_OUTPUT_DEVICE_ID	XPAR_LEDS_4BITS_DEVICE_ID
#define GPIO_INPUT_DEVICE_ID	XPAR_LEDS_4BITS_DEVICE_ID

//----------------- KEYPAD ------------------
// un gpio con dos canales
#define KEYPAD_CHANNEL_I 1
#define KEYPAD_CHANNEL_O 2
#define KEYPAD_DEVICE XPAR_GPIO_KEYPAD_DEVICE_ID
XGpio KYPAD_XGPIO;

//----------------- DISPLAY ------------------
#define DISPLAY_CHANNEL_O 1
#define DISPLAY_DEVICE XPAR_GPIO_DISPLAY_DEVICE_ID
XGpio DISPLAY_XGPIO;


//----------------- LEDS ---------------------
#define leds_CHANNEL_O 1
#define leds_DEVICE XPAR_LEDS_4BITS_DEVICE_ID
XGpio leds_XGPIO;


/************************** Function Prototypes ****************************/
int GpioOutputExample(u16 DeviceId, u32 GpioWidth);
int GpioInputExample(u16 DeviceId, u32 *DataRead);

void GpioDriverHandler(void *CallBackRef);

// funciones propias
int enciendeleds (u16 DeviceId, u8 mask);
void enciendeled_concreto (u16 DeviceId,char led);
void espera (int n_seg);


// Funciones KEYPAD
int num_fila();
int inicia_keypad();
char leePKMOD ();
char *leePKMOD_str ();

//Funciones DISPLAY
void representa(u32 num);
int inicia_display_leds();

// Espera
void espera_m (u32 mseg);

// Imprime ini
void imprime_ini();

// parpadeo leds
void parpadeo_leds();
#define Numblinks 3
#define Tblink 100 // ms


// Aleatorio
u8 r=7;

void alb_rand()
{
	r^=r<<7;
	r^=r<<5;
	r^=r<<3;
}

// JUEGO
u8 Nvict=1;
#define Maxvict 10
u8 cont=0;
u8 aciertos=0;
u8 fallos=0;


//******************************************************************************/
char MATRIZ[4][4]={{'1','2','3','A'},{'4','5','6','B'}, {'7','8','9','C'},{'0','F','E','D'}};

int main(void)
{
	int s1,s2;
	u32 InputData,dato;
	char mi_char[2];
	int i=0,j=0;
	volatile int Delay;
	u32 numdisplay[Maxvict];
	
	print("\tHola Mundo...\n\r");
	imprime_ini();
	// --- Inicio Keypad -----------
	s1=inicia_keypad();
	inicia_display_leds();
	if (s1==XST_FAILURE || s2==XST_FAILURE) 
	{
	print("Error INI"); 
	return 'Z';
	}
	else
	{
	print("-> DISPLAY... OK\n\r");
	print("-> KEYPAD... OK\n\n\r");
	}
	parpadeo_leds();
	// -----------------------------
	while(Nvict<Maxvict && mi_char[0]!='D')
	{
	// numero aleatorio+
	for (j=0;j<Nvict;j++)
	{
	alb_rand();
	numdisplay[j]=(r*(i++))%10;
	espera_m((u32)100*(Maxvict-Nvict));
	// representamos
	representa(numdisplay[j]);
	}
	parpadeo_leds();
	// leemos el numero
	print("  Introduzca Numeros  ");
	for (j=0;j<Nvict;j++)
	{
	mi_char[0]= leePKMOD();
	if (mi_char[0]=='D')
	continue;
	else
	{
	mi_char[1]='\0';
	print("\n\r");
	// imprimimos el numero
	print("  NUM introducido is :  ");
	print(mi_char);
	print("\n\r");
	if (mi_char[0] == (char)(numdisplay[j]+'0'))
	cont++;
	else
	break;
	}
	}
	/*if (mi_char[0]=='D')
	continue;*/
	// Vemos si coincide
	//numdisplay=(u32)(mi_char[0]-'0');
	if (cont==Nvict)
		{
		print("\a\n");
		print("\t--- OK ----\n\n\r");
		Nvict++;aciertos++;
		SIMON_PERIFERICO_mWriteSlaveReg2(0, 0,aciertos);
		}
	else
		{
		Nvict=1; fallos++;
		SIMON_PERIFERICO_mWriteSlaveReg3(0, 0,fallos);
		print("\t--- ERROR ----\n\n\r");
		representa(0xA); 
		}
	cont=0;
	parpadeo_leds();
	}
	print("Se acabó...\n\r");
	dato=SIMON_PERIFERICO_mReadSlaveReg1(0, 0);
	print("exitos: ");
	putnum(aciertos);print("\n\r");
	print("pulsados: ");
	putnum(dato);print("\n\r");
	
	return 0;
}


// ----------------------------------- Funcion inicializacion de KEYPAD
int inicia_keypad()
{
	int Status;
	// inicializamos inputs FIL y outputs COL
	Status = XGpio_Initialize(&KYPAD_XGPIO, KEYPAD_DEVICE); 	
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
				break;
			}
		}
	}
	return num;
}



// ----------------------------------- Funcion Global que lee str
char *leePKMOD_str()
{
	char num='X';
	char *mi_str;
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
				mi_str[0]=num;
				mi_str[1]='\0';
				break;
			}
		}
	}
	return mi_str;
}

// ----------------------------------- Funcion inicializacion de DISPLAY y Leds
int inicia_display_leds()
{
	int Status;
	//---- display --------
	Status = XGpio_Initialize(&DISPLAY_XGPIO, DISPLAY_DEVICE); 	
	if (Status != XST_SUCCESS)
	 return XST_FAILURE;
	XGpio_SetDataDirection(&DISPLAY_XGPIO,DISPLAY_CHANNEL_O,0x0);
	XGpio_DiscreteWrite(&DISPLAY_XGPIO, DISPLAY_CHANNEL_O, 0xFF);
	// ---- leds --------
	Status = XGpio_Initialize(&leds_XGPIO, leds_DEVICE); 	
	if (Status != XST_SUCCESS)
	 return XST_FAILURE;
	XGpio_SetDataDirection(&leds_XGPIO,leds_CHANNEL_O,0x0);
	return XST_SUCCESS;
}

// ----------------------------------- Funcion representacion de DISPLAY
void representa(u32 num)
{
	// conversion a 7 segmenos
	u32 vnum[10]={0x81,0xF3,0x49,0x61,0x33,0x25,0x05,0xF1,0x01,0x31}; //anodo comun
	u32 result;
	
	// borramos lo que haya
	XGpio_DiscreteWrite(&DISPLAY_XGPIO, DISPLAY_CHANNEL_O, 0xFF);
	
	if(num<=9 && num>=0)
	result=(vnum[num]);
	else
	if (num=0xA)
	result=0xFF; //apagamos todos
	else
	result=0x00; //encendemos todos
	
	// escribimos
	XGpio_DiscreteWrite(&DISPLAY_XGPIO, DISPLAY_CHANNEL_O,result);
}

// ----------------------------------- Funcion espera (ms)
void espera_m (u32 mseg)
{
	volatile int Delay;
	int T;
	
	T=4500*mseg;
	
	for (Delay = 0; Delay < T; Delay++)
		asm("nop");
}


void imprime_ini()
{
print("\n\n------- SIMON DISPLAY -------- \n\r");
print("\n\n\t --- Instrucciones ---   \n\n\r");
print("1-Espera el inicio\n\r");
print("2-El parpadeo de leds indica el inicio de la secuencia\n\r");
print("3-Ver la secuencia e intentar memorizarla\n\r");
print("4-Esperar a que termine la secuencia con el parpadeo de leds\n\r");
print("5-Introducir en el KEYPAD la secuencia\n\r");
print("6-Pulsar la tecla [D] que indica fin de la introduccion\n\r");
print("7-Si es correcto, seguir jugando\n\r");
print("8-Si fallamos,  volver a empezar\n\r");
print("\n\n------- SIMON DISPLAY -------- \n\n\n\r");
}

void parpadeo_leds()
{
	u8 out=0x0;
	int i;
	for (i=0;i<(Numblinks<<1);i++)
	{
	out^=0xF;
	XGpio_DiscreteWrite(&leds_XGPIO, leds_CHANNEL_O,out);
	espera_m (Tblink);
	}
}

