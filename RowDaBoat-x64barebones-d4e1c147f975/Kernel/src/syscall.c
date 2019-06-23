#include <syscall.h>
#include <naiveConsole.h>
#include <stdint.h>
#include <console.h>

//Todo: agregar todos los syscalls

extern void hang();
extern void over_clock(int rate);

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
			handle_sys_beep(rsi, rdx);
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
	    case SHUTDOWN:
	        //Metodo facil: Halteo la PC, como seria en la version original
	        //del kernel. Se podria buscar una forma de apagar la PC
	        //realmente, es decir, apagar el hardware.
            hang();
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

void handle_sys_beep(int freq, int time){
	beep(freq, time);
}

void handle_sys_over_clock(int rate){
	over_clock(rate);
}

int handle_sys_time(uint64_t selector){
	return get_time(selector);
}
