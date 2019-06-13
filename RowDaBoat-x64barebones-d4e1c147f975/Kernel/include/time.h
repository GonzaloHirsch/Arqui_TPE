#ifndef TIME_H
#define TIME_H

#define REGULAR_TICK_TIME 55

//#include <lib.h>

void timer_handler();
int ticks_elapsed();
void sleep(uint64_t millis);

/*
void ncPrint(const char * string);
void ncPrintChar(char character);
void ncNewline();
void ncPrintDec(uint64_t value);
void ncPrintHex(uint64_t value);
void ncPrintBin(uint64_t value);
void ncPrintBase(uint64_t value, uint32_t base);
void ncClear();
*/

#endif