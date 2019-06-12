//
// Created by root on 6/12/19.
//

#ifndef ARQUI_TPE_EXCEPTIONS_H
#define ARQUI_TPE_EXCEPTIONS_H


void loadExceptions();

void _exception00Handler();
void _exception06Handler();

void exceptionDispatcher(uint64_t exceptionType);

#endif //ARQUI_TPE_EXCEPTIONS_H
