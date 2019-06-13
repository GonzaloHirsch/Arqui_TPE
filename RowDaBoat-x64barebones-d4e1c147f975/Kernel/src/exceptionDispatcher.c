

#include <exceptionDispatcher.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <lib.h>

static void divZeroError();
static void invalidOpcodeError();
static void protectionFault();
static void pageFault();
static void tBI(); //(to Be Implemented


static void (*exceptionsArray[])() = {divZeroError, tBI, tBI, tBI, tBI, tBI, invalidOpcodeError, tBI, tBI, tBI, tBI, tBI, tBI, protectionFault, pageFault};



void exceptionDispatcher(uint64_t type){
ncClear();
    _cli();
    ncPrintOnAddress((char*)(0xB8000 + 80*2*4), "Hola");
    ncPrintOnAddress((char *)(0xB8000 + 80*2*2), itoa(type));
    ncPrintOnAddress((char *)(0xB8000) ,"Dispatching exception");
    (*exceptionsArray[type])();
   printRegisters();

    _sti();
}


void tBI(){
    ncPrint("Exception yet to be implemented");
}


static void divZeroError(){

    ncPrintOnAddress((char *)(0xB8000 + 80*2*12 + 80-20*2) ,"Division By Zero");

}

static void invalidOpcodeError(){

    ncPrintOnAddress((char *)(0xB8000 + 80*2*12 + 80-20*2), "Invalid Opcode");
}

static void protectionFault(){
    ncPrintOnAddress((char *)(0xB8000 + 80*2*12 + 80-20*2), "Protection Fault");
}

void pageFault(){
    ncPrintOnAddress((char *)(0xB8000 + 80*2*12 + 80-20*2), "Page Fault");
}