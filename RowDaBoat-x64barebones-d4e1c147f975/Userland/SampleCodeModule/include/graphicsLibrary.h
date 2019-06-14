#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <syscalls.h>
#include <types.h>
#include <utils.h>

void print(const char * str);

void printN(const char * str, int length);

void drawRect(Vector2 start, Vector2 size, Color color);

#endif
