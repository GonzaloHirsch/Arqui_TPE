#ifndef SYSCALL_H
#define SYSCALL_H

#include <stdint.h>
#include <keyboard.h>
#include <time.h>
#include <io_read.h>
#include <sound.h>

#define READ 1
#define WRITE 2
#define BEEP 3
#define SNAKE 4
#define TIME 5
#define SLEEP 6

void handleSyscall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9);

void handle_sys_write(int fd, const char * buf, int length);

void handle_sys_read(int fd, char * buf, int length);

void handle_sys_beep();

#endif
