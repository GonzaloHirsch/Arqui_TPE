#ifndef SYSCALL_H
#define SYSCALL_H

#include <stdint.h>
#include <keyboard.h>
#include <time.h>
#include <io_read.h>
#include <sound.h>
#include <console.h>
#include <videoDriver.h>
#include <types.h>
#include <interrupts.h>

#define READ 1
#define WRITE 2
#define BEEP 3
#define TICKS 4
#define TIME 5
#define SLEEP 6
#define DATE 7
#define CLEAR 8
#define DRAW_PIXEL 9
#define OVER_CLOCK 10
#define SHUTDOWN 11

uint64_t handleSyscall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9);

void handle_sys_write(int fd, const char * buf, int length);

void handle_sys_read(int fd, char * buf, int length);

void handle_sys_beep(void);

void handle_sys_get_ticks(int * ticks);

void handle_sys_sleep(int ticks);

void handle_sys_over_clock(int rate);

int handle_sys_time(uint64_t selector);

void handle_sys_clear_console(void);

void handle_sys_draw_pixel(int x, int y, int r, int g, int b);

#endif
