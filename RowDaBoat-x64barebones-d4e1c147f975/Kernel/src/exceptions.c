

#include <exceptions.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <lib.h>
#include <time.h>
#include <console.h>
#include <idtLoader.h>

static void divZeroError();
static void invalidOpcodeError();
static void protectionFault();
static void pageFault();
static void doubleFault();
static void tBI(); //to Be Implemented

RegisterSet cRV;
ExceptionStackFrame eSF;

extern void goToUserland();

static void (*exceptionsArray[])() = {divZeroError, tBI, tBI, tBI, tBI, tBI, invalidOpcodeError, tBI, doubleFault, tBI, tBI, tBI, tBI, protectionFault, pageFault};

void retrieveRegisters();
void printRegistersAccurate();

void loadExceptions(){

    //Loading Exceptions
    _cli();
    setup_IDT_entry(0x00, (uint64_t) &_exception00Handler);
    setup_IDT_entry(0x06, (uint64_t) &_exception06Handler);
    setup_IDT_entry(0x0D, (uint64_t) &_exception13Handler);
    setup_IDT_entry(0x0E, (uint64_t) &_exception14Handler);
    _sti();
}

void exceptionDispatcher(uint64_t type){



        _cli();

        //uso este extended assembly para no ir a otra funcion
        //y tener un lio en el stack. Todavia tengo 8 bytes del
        //retAddr de exceptionDispatcher.
        __asm__ volatile ("mov 32(%%rsp), %0;"
        : "=a" (eSF.rip)
        );

        retrieveRegisters();        //Obtengo los registros antes de llamar a cualquier
                                    //otra funcion desde aca.

        clear_console();
        print("\n");
        (*exceptionsArray[type])();
        printError("RIP: %d\n", eSF.rip);
        printRegistersAccurate();

        print("\n\nRebooting to userland");
        _sti();
        sleep(2000);
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

static void pageFault(){
    printError("Exception 14: Page Fault\n");
}

static void doubleFault(){
    printError("Exception 8: Double Fault\n");
}

void retrieveRegisters(){

    __asm__ volatile ("mov %%rax, %0;"
    : "=a" (cRV.rax)
    );
    __asm__ volatile ( "mov %%rbx, %0;"
    : "=a" (cRV.rbx)
    );
    __asm__ volatile ( "mov %%rcx, %0;"
    : "=a" (cRV.rcx)
    );
    __asm__ volatile ( "mov %%rdx, %0;"
    : "=a" (cRV.rdx)
    );
    __asm__ volatile ( "mov %%rdi, %0;"
    : "=a" (cRV.rdi)
    );
    __asm__ volatile ( "mov %%rsi, %0;"
    : "=a" (cRV.rsi)
    );
    __asm__ volatile ( "mov %%rbp, %0;"
    : "=a" (cRV.rbp)
    );
    __asm__ volatile ( "mov %%rsp, %0;"
    : "=a" (cRV.rsp)
    );
    __asm__ volatile ( "mov %%r8, %0;"
    : "=a" (cRV.r8)
    );
    __asm__ volatile ( "mov %%r9, %0;"
    : "=a" (cRV.r9)
    );
}

void printRegistersAccurate(){

    printError("RAX: %d\nRBX: %d\nRCX: %d\nRDX: %d\nRDI: %d\nRSI: %d\nRBP: %d\nRSP: %d\nR8: %d\nR9: %d\n", cRV.rax, cRV.rbx,cRV.rcx, cRV.rdx,cRV.rdi, cRV.rsi,cRV.rbp, cRV.rsp,cRV.r8, cRV.r9);
}