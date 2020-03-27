/***************************** Include Files ********************************/
#include "stdio.h"
#include "alberto_KEYPAD3.h"
#include "alberto_DISPLAY_GPIO.h"


int main()
{
XStatus s1,s2;
u32 num;
char mi_char[2];

s1=inicia_keypad();
s2=inicia_display();

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


while(1)
	{
	mi_char[0]= leePKMOD();
	mi_char[1]='\0';
	// imprimimos el numero
	print("NUM is :  ");
	print(mi_char);
	print("\n\r");
	num=(u32)(mi_char[0]-'0');
	// representamos display
	representa(num);
	}

return 0;
}

