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
#define SLEEP 6
#define DATE 7

void sys_write(int fd, const char *buf, int count);

void sys_write_key(int fd, const char * buf);

void sys_get_key(int fd, char *buf);

void sys_read(int fd, char *buf, int count);

void sys_sleep(int ticks);

void sys_beep(void);

void sys_snake(void);

void sys_draw(void);

void sys_time(char * buf);

void sys_date(char * buf);

#endif
