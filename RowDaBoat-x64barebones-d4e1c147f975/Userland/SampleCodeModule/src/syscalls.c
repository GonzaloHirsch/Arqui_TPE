#include <syscalls.h>

void sys_write(int fd, const char *buf, int count){
	_int80((uint64_t)WRITE, (uint64_t)fd, buf, (uint64_t)count, 0, 0);
}

void sys_read(int fd, char *buf, int count){
	_int80((uint64_t)READ, (uint64_t)fd, buf, (uint64_t)count, 0, 0);
}

void sys_get_key(int fd, char *buf){
	_int80((uint64_t)READ, (uint64_t)fd, buf, (uint64_t)1, 0, 0);
}

void sys_write_key(int fd, const char * buf){
	_int80((uint64_t)WRITE, (uint64_t)fd, buf, 1, 0, 0);
}

void sys_beep(void){
	_int80((uint64_t)BEEP, 0, 0, 0, 0, 0);
}

// void sys_time(char * buf){
// 	_int80(TIME, 0, buf, 0, 0, 0);
// }

int sys_time(int selector){
	uint64_t time = _int80((uint64_t)TIME, (uint64_t)selector, 0, 0, 0, 0);
	return time;
}

void sys_over_clock(int rate){
	_int80((uint64_t)OVER_CLOCK, (uint64_t)rate, 0, 0, 0, 0);
}

// void sys_date(char * buf){
// 	_int80((uint64_t)DATE, 0, buf, 0, 0, 0);
// }

void sys_sleep(int ticks){
	_int80((uint64_t)SLEEP, 0, 0, (uint64_t)ticks, 0, 0);
}

void sys_draw_pixel(int x, int y, int r, int g, int b){
	_int80((uint64_t)DRAW_PIXEL, (uint64_t)x, (uint64_t)y, (uint64_t)r, (uint64_t)g, (uint64_t)b);
}

void sys_clear_console(void){
	_int80((uint64_t)CLEAR, 0, 0, 0, 0, 0);
}

void sys_snake(void){
	//_int80();
}

void sys_draw(void){
	//_int80();
}
