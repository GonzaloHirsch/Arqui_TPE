#ifndef SYSCALLS_H
#define SYSCALLS_H

//Incluye a interrupts para poder hacer la llamada a la int 80
#include <interrupts.h>

#define READ 1
#define WRITE 2
#define BEEP 3
#define SNAKE 4
#define TIME 5

void sys_write(char * str, int length);

void sys_read();

void sys_beep();

void sys_snake();

void sys_draw();

void sys_time();

#endif
