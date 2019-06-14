/* sampleCodeModule.c */
//#include <interrupts.h>
#include <naiveConsole.h>
#include <shell.h>
#include <stdint.h>

char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;


int main() {
	//ncPrint("ACA");
	//All the following code may be removed 
	/*
	*v = 'X';
	*(v+1) = 0x74;
    //syscall(2, 0, 0, 0, 0, 0);

	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xdeadbeef;
	*/
	//return 0xDEADBEEF;

	//init_shell();

	/* Prueba para excepciones
	uint64_t invalid= 0xFFFFFFFFFFFF;
    uint64_t * ptr = &invalid;
    ((void(*)())ptr)();
    */

	int i = 0xFFFFFFFF;
	i += 1;
	ncPrintOnAddress((char *)(0xB8000 + 80*2*12), "hello, I'm a user");
	i/=0;
	//ncPrint("hello, I'm a user");
	return 1;
}