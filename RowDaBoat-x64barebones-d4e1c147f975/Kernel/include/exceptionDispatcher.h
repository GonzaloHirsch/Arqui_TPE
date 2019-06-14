//
// Created by root on 6/12/19.
//

#ifndef ARQUI_TPE_EXCEPTIONDISPATCHER_H
#define ARQUI_TPE_EXCEPTIONDISPATCHER_H

#include <stdint.h>

void exceptionDispatcher(uint64_t type);
void printRegisters();


void setVerifying();
void clearVerifying();
void setExceptionAssert();

#endif //ARQUI_TPE_EXCEPTIONDISPATCHER_H
