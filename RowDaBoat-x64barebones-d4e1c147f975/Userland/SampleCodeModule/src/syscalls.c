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

void sys_beep(){
	//_int80();
}

void sys_time(char * buf){
	_int80(TIME, 0, buf, 0, 0, 0);
}

void sys_snake(){
	//_int80();
}

void sys_draw(){
	//_int80();
}
