#include <idtLoader.h>
#include <exceptions.h>
#include <naiveConsole.h>


static void divZeroError();
static void invalidOpcodeError();

static void (*exceptionsArray[])() = {&divZeroError, 0, 0, 0, 0, 0, &invalidOpcodeError};


void loadExceptions(){

    setup_IDT_entry(0x00, (uint64_t) &_exception00Handler);
    setup_IDT_entry(0x06, (uint64_t) &_exception06Handler);

}

void exceptionDispatcher(uint64_t type){

    (*exceptionsArray[type])();
}

void divZeroError(){
    ncPrint("DivisionByZeroError");
}

void invalidOpcodeError(){
    ncPrint("InvalidOpcodeError");
}