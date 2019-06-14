//
// Created by root on 6/12/19.
//

#ifndef ARQUI_TPE_EXCEPTIONDISPATCHER_H
#define ARQUI_TPE_EXCEPTIONDISPATCHER_H

#include <stdint.h>

void exceptionDispatcher(uint64_t type);
void printRegisters();

typedef struct {

    uint64_t rax;
    uint64_t rbx;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rdi;
    uint64_t rsi;
    uint64_t rbp;
    uint64_t rsp;
    uint64_t r8;
    uint64_t r9;
}RegisterSet;

void setVerifying();
void clearVerifying();
void setExceptionAssert();

#endif //ARQUI_TPE_EXCEPTIONDISPATCHER_H
