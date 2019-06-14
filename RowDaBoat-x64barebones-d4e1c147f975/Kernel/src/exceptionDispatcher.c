

#include <exceptionDispatcher.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <lib.h>
#include <time.h>
#include <console.h>

static void divZeroError();
static void invalidOpcodeError();
static void protectionFault();
static void pageFault();
static void tBI(); //(to Be Implemented

extern void goToUserland();

static void (*exceptionsArray[])() = {divZeroError, tBI, tBI, tBI, tBI, tBI, invalidOpcodeError, tBI, tBI, tBI, tBI, tBI, tBI, protectionFault, pageFault};

void exceptionDispatcher(uint64_t type){

   // char buffer[100];


    _cli();
    sleep(1000);
   /*
    ncClear();
    // printOnAddress((char*)(0xB8000 + 80*2*4), "Hola");
   //printOnAddress((char *)(0xB8000 + 80*2*2), itoa(type, buffer, 10));
   // printOnAddress((char *)(0xB8000) ,"Dispatching exception");
    ncNewline();
*/

   //Lo que sigue es para el modo vesa
   clear_console();
   print("\n");
    (*exceptionsArray[type])();
   printRegisters();
   _sti();
   goToUserland();

}


void tBI(){
    printError("Exception yet to be implemented\n");
}


static void divZeroError(){

    printError("Division By Zero\n");
    //printOnAddress((char *)(0xB8000 + 80*2 + 80-20*2) ,"Division By Zero");

}

static void invalidOpcodeError(){

    printError("Invalid Opcode\n");
   // printOnAddress((char *)(0xB8000 + 80*2 + 80-20*2), "Invalid Opcode");
}

static void protectionFault(){
    printError("Protection Fault\n");
   // printOnAddress((char *)(0xB8000 + 80*2 + 80-20*2), "Protection Fault");
}

void pageFault(){
    printError("Page Fault\n");
    //printOnAddress((char *)(0xB8000 + 80*2 + 80-20*2), "Page Fault");
}