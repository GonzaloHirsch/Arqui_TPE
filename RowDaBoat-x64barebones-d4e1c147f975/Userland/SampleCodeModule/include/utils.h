#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <syscalls.h>
#include <naiveConsole.h>

char getKey(void);
void writeKey(char * key);
int strcmp(const char * stra, const char * strb);
void makeSound(void);
void goToSleep(int ticks);
char * getTime(void);
char * getDate(void);

#endif
