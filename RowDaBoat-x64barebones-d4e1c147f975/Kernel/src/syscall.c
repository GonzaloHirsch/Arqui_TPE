//
// Created by root on 6/8/19.
//

#include <syscall.h>
#include <naiveConsole.h>
#include <stdint.h>

//Todo: agregar todos los syscalls

void handleSyscall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9){



    ncPrint("syscall no ");
    ncPrintDec(rdi);
    ncNewline();
}