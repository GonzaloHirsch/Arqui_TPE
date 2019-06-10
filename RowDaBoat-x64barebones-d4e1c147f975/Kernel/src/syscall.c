#include <syscall.h>
#include <naiveConsole.h>
#include <stdint.h>

//Todo: agregar todos los syscalls

void handleSyscall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9){
	switch(rdi){
		case WRITE:
			handle_sys_write(rsi, (char *)rdx, rcx);
		break;
		case READ:
			handle_sys_read(rsi, (char *)rdx, rcx);
		break;
	}
	ncPrintDec(WRITE);
    ncPrint("syscall no ");
    ncPrintDec(rdi);
    ncNewline();
}

void handle_sys_write(int fd, const char * buf, int length){
	for(int i = 0; i < length; i++){
		ncPrintChar(*(buf + i));
	}
}

void handle_sys_read(int fd, char * buf, int length){
	for (int i = 0; i < length; i++){
		*(buf + i) = getChar();
	}
}