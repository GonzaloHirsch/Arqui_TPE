#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <syscalls.h>
#include <types.h>
#include <pixelMap.h>

void drawRect(Vector2 start, Vector2 size, Color color);

void drawString(Vector2 pos, char * str, Color foreground, Color background);

#endif
