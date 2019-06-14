#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <syscalls.h>
#include <naiveConsole.h>

char getKey();
void writeKey(char * key);
int strcmp(const char * stra, const char * strb);
void makeSound();
void goToSleep(int ticks);

#endif
