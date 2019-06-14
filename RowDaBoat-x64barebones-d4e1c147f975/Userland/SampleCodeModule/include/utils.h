#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdarg.h>
#include <syscalls.h>
#include <naiveConsole.h>

#define MAX_BUFFER 100

char getChar(void);
void putChar(char c);
void printf(char * str, ...);

char* itoa(int value, char* buffer, int base);

char getKey(void);

void writeKey(char * key);

int strcmp(const char * stra, const char * strb);

int strlen(const char * str);

void makeSound(void);

void goToSleep(int ticks);

char * getTime(void);

char * getDate(void);

void print(const char * str);

void printN(const char * str, int length);

#endif
