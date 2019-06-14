

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



    _cli();
    sleep(1000);

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

    printError("Exception 0: Division By Zero\n");

}

static void invalidOpcodeError(){

    printError("Exception 6: Invalid Opcode\n");
}

static void protectionFault(){
    printError("Exception 13: Protection Fault\n");
}

void pageFault(){
    printError("Exception 14: Page Fault\n");
}