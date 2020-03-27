/***************************** Include Files ********************************/
#include "stdio.h"
#include "alberto_KEYPAD3.h"


/*int main()
{
XStatus miestado;
char mi_char[2];

miestado=inicia_keypad();
print("\n\n\rKeypad = ");
putnum(miestado);
print("\n\r");
//miestado = AGI_PLB_SelfTest(0);
//putnum(miestado);
print("\n\r");
while(1)
	{
	mi_char[0]= leePKMOD();
	mi_char[1]='\0';
	// imprimimos el numero
	print("NUM is :  ");
	print(mi_char);
	print("\n\r");
	}

return 0;
}*/


int main()
{
u32 col,dato;
volatile int Delay;
while(1)
for (col=0x0;col<4;col++)
{
	AGI_PLB_mWriteSlaveReg0(mi_baseaddr, 0, (1<<col));
	for (Delay = 0; Delay < LED_DELAY; Delay++);
	dato=AGI_PLB_mReadSlaveReg0(mi_baseaddr, 0);
	putnum(dato);
	print("\n\r");}
return 0;
}
