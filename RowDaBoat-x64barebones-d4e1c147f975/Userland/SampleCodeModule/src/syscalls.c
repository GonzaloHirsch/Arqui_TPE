#include <syscalls.h>

void sys_write(int fd, const char *buf, int count){
	_int80(WRITE, fd, buf, count, 0, 0);
}

void sys_read(int fd, char *buf, int count){
	_int80(READ, fd, buf, count, 0, 0);
}

void sys_get_key(int fd, char *buf){
	_int80(READ, fd, buf, 1, 0, 0);
}

void sys_write_key(int fd, const char * buf){
	_int80(WRITE, fd, buf, 1, 0, 0);
}

void sys_beep(void){
	_int80(BEEP, 0, 0, 0, 0, 0);
}

void sys_time(char * buf){
	_int80(TIME, 0, buf, 0, 0, 0);
}

void sys_date(char * buf){
	_int80(DATE, 0, buf, 0, 0, 0);
}

void sys_sleep(int ticks){
	_int80(SLEEP, 0, 0, ticks, 0, 0);
}

void sys_draw_pixel(int x, int y, int r, int g, int b){
	_int80(DRAW_PIXEL, x, y, r, g, b);
}

void sys_clear_console(void){
	_int80(CLEAR, 0, 0, 0, 0, 0);
}

uint64_t sys_get_ticks(void){
	int ticks;
	_int80(TICKS, 0, &ticks, 0, 0, 0);
	return ticks;
}

void sys_draw(void){
	//_int80();
}
