//
// Created by root on 6/14/19.
//

#include <exceptionDispatcher.h>

static void verif00();
static void verif06();
static void verif13();
static void verif14();
static void tBI(); //(to Be Implemented

static void (*verifFuncs[])() = {verif00, tBI, tBI, tBI, tBI, tBI, verif06, tBI, tBI, tBI, tBI, tBI, tBI, verif13, verif14};

int verifyExceptions(){


    setVerifying();

    for(int i = 0; i<15; i++){
        setExceptionAssert(i);
        print("Verifying exception %d", i);
        (*verifFuncs[i])();
        sleep(1000);
    }

    setExceptionAssert(0);
    clearVerifying();
}

void tBI(){
    return;
}

void verif00(){

    int i = 0xFFFFFFFF;

    i/=0;
}

void verif06(){

}
void verif13(){

}
void verif14(){

}