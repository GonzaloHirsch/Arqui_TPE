#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdarg.h>
#include <syscalls.h>
#include <naiveConsole.h>
#include <graphicsLibrary.h>

#define MAX_BUFFER 100

char getChar(void);
void putChar(char c);
void printf(char * str, ...);
int scanf(const char * fmt, ...);

char* itoa(int value, char* buffer, int base);

int atoi(const char* buffer, int len);

int isNumeric(char c);

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
