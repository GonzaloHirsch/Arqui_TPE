#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void _irq00Handler();
void _irq01Handler();
void _irq80Handler(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9);

void _cli();
void _sti();

void pic_master_mask(uint8_t mask);

void pic_slave_mask(uint8_t mask);

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