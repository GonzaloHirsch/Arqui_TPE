//
// Created by nacho on 12/06/19.
//

#ifndef ARQUI_TPE_CONSOLE_H
#define ARQUI_TPE_CONSOLE_H

#include <types.h>
#include <pixelMap.h>
#include <strings.h>
#include <stdarg.h>
#include <videoDriver.h>

void initConsole();

void print(char * str, ...);

void clearConsole();


#endif //ARQUI_TPE_CONSOLE_H
