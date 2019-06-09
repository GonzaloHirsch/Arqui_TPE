/* sampleCodeModule.c */

#include <interrupts.h>
#include <naiveConsole.h>


char * v = (char*)0xB8000 + 79 * 2;

extern void syscall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9);

static int var1 = 0;
static int var2 = 0;


int main() {
	//All the following code may be removed 
	*v = 'X';
	*(v+1) = 0x74;
    syscall(2, 0, 0, 0, 0, 0);

	ncPrint("heytherebish");
	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xBEBEC17A;

	return 0xDEADBEEF;
}