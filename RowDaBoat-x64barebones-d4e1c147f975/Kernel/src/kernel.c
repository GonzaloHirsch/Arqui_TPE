#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <irqDispatcher.h>
#include <time.h>
#include <idtLoader.h>
#include <interrupts.h>
#include <syscall.h>

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

//Addresses a donde copia los modulos
static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;

static char stdin[200]={0};
static char stdout[200]={0};
static char stderr[200]={0};

typedef int (*EntryPoint)();

extern char read_key();


void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void printModules(){
	char module[] = "n - First module to be loaded";
	ncPrint(module);
	ncNewline();
}

void handleModuleChoosing(int option){

}

void * initializeKernelBinary()
{
	char buffer[10];

	ncPrint("[x64BareBones]");
	ncNewline();

	ncPrint("CPU Vendor:");
	ncPrint(cpuVendor(buffer));
	ncNewline();

	ncPrint("[Loading modules]");
	ncNewline();
	//Llena con los addresses a donde copia los modulos
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	ncPrint("[Done]");
	ncNewline();
	ncNewline();

	ncPrint("[Initializing kernel's binary]");
	ncNewline();

	clearBSS(&bss, &endOfKernel - &bss);

	ncPrint("  text: 0x");
	ncPrintHex((uint64_t)&text);
	ncNewline();
	ncPrint("  rodata: 0x");
	ncPrintHex((uint64_t)&rodata);
	ncNewline();
	ncPrint("  data: 0x");
	ncPrintHex((uint64_t)&data);
	ncNewline();
	ncPrint("  bss: 0x");
	ncPrintHex((uint64_t)&bss);
	ncNewline();

	ncPrint("[Done]");
	ncNewline();
	ncNewline();
	return getStackBase();
}

int main()
{
    char buffer[100];
    int moduleIsChosen = 0;

	ncPrint("[Kernel Main]");
	ncNewline();

	ncChangeOutput(STDERR);
	ncPrint("Arquitectura de Computadoras");
	ncChangeOutput(STDIN);
	ncNewline();

	//Carga del IDT
	ncPrint("Loading IDT... ");
	load_idt();
	ncPrint("[Done]");

	ncNewline();

	ncPrint("Choose the module to be loaded: ");
	ncNewline();
	printModules();
	//While para la decision del modulo
	while(!moduleIsChosen){
	    ncPrintOnAddress((char *) 0xB8000, itoa(ticks_elapsed(), buffer, 10));
	}

	ncNewline();
	ncPrintDec(getSeconds());
	ncPrintDec(getMinutes());
	ncPrintDec(getHours());
	ncNewline();
	ncPrint("  Sample code module at 0x");
	ncPrintHex((uint64_t)sampleCodeModuleAddress);
	ncNewline();
	ncPrint("  Calling the sample code module returned: ");
	ncPrintHex(((EntryPoint)sampleCodeModuleAddress)());
	ncNewline();
	ncNewline();

	while(1){
	    ncPrintOnAddress((char *) 0xB8000, itoa(ticks_elapsed(), buffer, 10));
	}

	ncPrint("  Sample data module at 0x");
	ncPrintHex((uint64_t)sampleDataModuleAddress);
	ncNewline();
	ncPrint("  Sample data module contents: ");
	ncPrint((char*)sampleDataModuleAddress);
	ncNewline();

	ncPrint("[Finished]");
	return 0;
}