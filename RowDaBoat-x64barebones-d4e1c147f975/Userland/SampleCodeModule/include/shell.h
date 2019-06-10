#ifndef SHELL_H
#define SHELL_H

#include <stdint.h>
#include <naiveConsole.h>

//Constantes para los comandos
#define HELP = 0
#define SNAKE = 1
#define SHUTDOWN = 2
#define VERIFY = 3
#define TIME = 4
#define BEEP = 5
#define SLEEP = 6

#define MAX_BUFF_SIZE 100

static char * STDIN[MAX_BUFF_SIZE] = {0};
static char * STDERR[MAX_BUFF_SIZE] = {0};
static char * STDOUT[MAX_BUFF_SIZE] = {0};

// void ncPrint(const char * string);
// void ncPrintChar(char character);
// void ncNewline();
// void ncPrintDec(uint64_t value);
// void ncPrintHex(uint64_t value);
// void ncPrintBin(uint64_t value);
// void ncPrintBase(uint64_t value, uint32_t base);
// void ncClear();
// void ncPrintOnAddress(char * address, char * text);

#endif