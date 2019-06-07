/* sampleCodeModule.c */

#include <showTextOnScreen.h>
#include <time.h>

char * v = (char*)0xB8000;

static int var1 = 0;
static int var2 = 0;

int main() {
	//All the following code may be removed 
	

    showTextOnScreen(v, "Arquitectura de Computadoras");
    showTextOnScreen(v+80*2, "Shit");
    showTime(v+80*2*2);

	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xBEBEC17A;

	return 0xDEADBEEF;
}