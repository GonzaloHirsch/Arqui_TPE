

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
static void doubleFault();
static void tBI(); //to Be Implemented

static int verifying = 0;
static int exceptionAssert = 0;

extern void goToUserland();

static void (*exceptionsArray[])() = {divZeroError, tBI, tBI, tBI, tBI, tBI, invalidOpcodeError, tBI, doubleFault, tBI, tBI, tBI, tBI, protectionFault, pageFault};

void exceptionDispatcher(uint64_t type){

    if(verifying){

        print("\nHere\n");

        if(exceptionAssert == type){
            print("Exception %d: OK\n", type);
        }
        else{
            printError("Error: Expected %d but got %d\n", exceptionAssert, type);
        }
    }
    else {
        _cli();
        sleep(1000);

        //Lo que sigue es para el modo vesa
        clear_console();
        print("\n");
        (*exceptionsArray[type])();
        printRegisters();

        print("\n\nRebooting to userland");
        _sti();
        sleep(2000);
        goToUserland();
    }
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

void setVerifying(){
    verifying = 1;
}
void clearVerifying(){
    verifying = 0;
}
void setExceptionAssert(int i){
    exceptionAssert = i;
}