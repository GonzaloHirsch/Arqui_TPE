

#include <exceptionDispatcher.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <lib.h>
#include <time.h>
#include <kernel.h>

static void divZeroError();
static void invalidOpcodeError();
static void protectionFault();
static void pageFault();
static void tBI(); //(to Be Implemented


static void (*exceptionsArray[])() = {divZeroError, tBI, tBI, tBI, tBI, tBI, invalidOpcodeError, tBI, tBI, tBI, tBI, tBI, tBI, protectionFault, pageFault};

void exceptionDispatcher(uint64_t type){

   // char buffer[100];


    _cli();
    ncClear();
    // ncPrintOnAddress((char*)(0xB8000 + 80*2*4), "Hola");
   //ncPrintOnAddress((char *)(0xB8000 + 80*2*2), itoa(type, buffer, 10));
   // ncPrintOnAddress((char *)(0xB8000) ,"Dispatching exception");
    (*exceptionsArray[type])();
    ncNewline();
    ncClear();

   printRegisters();

    goToUserland();

}


void tBI(){
    ncPrint("Exception yet to be implemented");
}


static void divZeroError(){

    ncPrint("Division By Zero");
    //ncPrintOnAddress((char *)(0xB8000 + 80*2 + 80-20*2) ,"Division By Zero");

}

static void invalidOpcodeError(){

    ncPrint("Invalid Opcode");
   // ncPrintOnAddress((char *)(0xB8000 + 80*2 + 80-20*2), "Invalid Opcode");
}

static void protectionFault(){
    ncPrint("Protection Fault");
   // ncPrintOnAddress((char *)(0xB8000 + 80*2 + 80-20*2), "Protection Fault");
}

void pageFault(){
    ncPrint("Page Fault");
    //ncPrintOnAddress((char *)(0xB8000 + 80*2 + 80-20*2), "Page Fault");
}