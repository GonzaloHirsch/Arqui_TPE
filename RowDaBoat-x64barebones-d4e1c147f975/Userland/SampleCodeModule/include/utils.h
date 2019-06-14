#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <syscalls.h>
#include <naiveConsole.h>

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
