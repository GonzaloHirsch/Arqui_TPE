#include <syscall.h>
#include <naiveConsole.h>
#include <stdint.h>
#include <console.h>

//Todo: agregar todos los syscalls

uint64_t handleSyscall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9){
	switch(rdi){
		case WRITE:
		//ncPrint("WRITE");
			handle_sys_write(rsi, (char *)rdx, rcx);
		break;
		case READ:
		//ncPrint("READ");
			handle_sys_read(rsi, (char *)rdx, rcx);
		break;
		case TIME:
			return handle_sys_time(rsi);
		break;
		case BEEP:
		//ncPrint("READ");
			handle_sys_beep();
		break;
		case SLEEP:
		//ncPrint("SLEEP");
			handle_sys_sleep(rcx);
		break;
		case OVER_CLOCK:
		//ncPrint("SLEEP");
			handle_sys_over_clock(rsi);
		break;
		case CLEAR:
		//ncPrint("SLEEP");
			handle_sys_clear_console();
		break;
		case DRAW_PIXEL:
		//ncPrint("SLEEP");
			handle_sys_draw_pixel(rsi, rdx, rcx, r8, r9);
		break;
		case TICKS:
		//ncPrint("SLEEP");
			handle_sys_get_ticks((int *)rdx);
		break;
	}
	return 0;
}

void handle_sys_write(int fd, const char * buf, int length){
	print_N(buf, length);
}

void handle_sys_get_ticks(int * ticks){
	*(ticks) = ticks_elapsed();
}

void handle_sys_clear_console(void){
	clear_console();
}

void handle_sys_draw_pixel(int x, int y, int r, int g, int b){
	Vector2 auxPos = {x,y};
	Color auxColor = {r,g,b};
	draw_pixel(auxPos, auxColor);
}

void handle_sys_read(int fd, char * buf, int length){
	//ncPrintDec(length);
	for (int i = 0; i < length; i++){
		*(buf + i) = getChar();
		//ncPrintChar(*(buf + i));
	}
}

void handle_sys_sleep(int ticks){
	timer_wait(ticks);
}

void handle_sys_beep(){
	beep();
}

void handle_sys_over_clock(int rate){
	_over_clock(rate);
}

int handle_sys_time(uint64_t selector){
	return get_time(selector);
}
