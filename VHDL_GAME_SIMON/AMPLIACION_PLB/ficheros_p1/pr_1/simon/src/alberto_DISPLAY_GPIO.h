/*---------------------------
LIBRERIA .h para el display 
	Alberto Gonzalez Isorna
	10/01/18
---------------------------*/


//----------------- DISPLAY ------------------
#define DISPLAY_CHANNEL_O 1
#define DISPLAY_DEVICE XPAR_GPIO_DISPLAY_DEVICE_ID
XGpio DISPLAY_XGPIO;

//--------------Funciones DISPLAY--------------
void representa(u32 num);
int inicia_display();


// ----------------------------------- Funcion inicializacion de DISPLAY y Leds
int inicia_display()
{
	int Status;
	//---- display --------
	Status = XGpio_Initialize(&DISPLAY_XGPIO, DISPLAY_DEVICE); 	
	if (Status != XST_SUCCESS)
	 return XST_FAILURE;
	XGpio_SetDataDirection(&DISPLAY_XGPIO,DISPLAY_CHANNEL_O,0x0);
	XGpio_DiscreteWrite(&DISPLAY_XGPIO, DISPLAY_CHANNEL_O, 0xFF); //apagado
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