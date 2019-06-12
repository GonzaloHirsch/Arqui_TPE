#ifndef SYSCALLS_H
#define SYSCALLS_H

//Incluye a interrupts para poder hacer la llamada a la int 80
#include <interrupts.h>
#include <stdint.h>

#define READ 1
#define WRITE 2
#define BEEP 3
#define SNAKE 4
#define TIME 5

void sys_write(int fd, const char *buf, int count);

void sys_get_key(int fd, char *buf);

void sys_read(int fd, char *buf, int count);

void sys_beep();

void sys_snake();

void sys_draw();

void sys_time();

#endif
