//
// Created by root on 6/8/19.
//

#ifndef ARQUI_TPE_SYSCALL_H
#define ARQUI_TPE_SYSCALL_H

#include <stdint.h>

void handleSyscall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9);

#endif //ARQUI_TPE_SYSCALL_H
