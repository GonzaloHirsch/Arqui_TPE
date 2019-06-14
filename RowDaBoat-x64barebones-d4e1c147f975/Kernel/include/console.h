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

void init_console();

void print(char * str, ...);

void printInteger(uint64_t dec);

void printError(char * str, ...);

void move_line_up(unsigned int line);

void clear_line(unsigned int line);

void move_all_up();

void clear_console();


#endif //ARQUI_TPE_CONSOLE_H
