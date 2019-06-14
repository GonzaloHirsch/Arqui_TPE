#include <syscall.h>
#include <naiveConsole.h>
#include <stdint.h>
#include <console.h>

//Todo: agregar todos los syscalls

void handleSyscall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9){
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
		//ncPrint("READ");
			handle_sys_time((char *)rdx);
		break;
		case BEEP:
		//ncPrint("READ");
			handle_sys_beep();
		break;
		case SLEEP:
		//ncPrint("SLEEP");
			handle_sys_sleep(rcx);
		break;
		case DATE:
		//ncPrint("SLEEP");
			handle_sys_date((char *)rdx);
		break;
	}
	// ncPrintDec(READ);

 //    ncPrint("syscall no ");
 //    ncPrintDec(rdi);
 //    ncNewline();
}

void handle_sys_write(int fd, const char * buf, int length){
	print_N(buf, length);
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

void handle_sys_date(char * buff){
	int day = get_time(DAY_OF_MONTH);
	if (day < 10){
		itoa(0, buff, 10);
		itoa(day, buff + 1, 10);
	} else{
		itoa(day, buff, 10);
	}

	*(buff + 2) = '/';

	int month = get_time(MONTH);
	if (month < 10){
		itoa(0, buff + 3, 10);
		itoa(month, buff + 4, 10);
	} else{
		itoa(month, buff + 3, 10);
	}

	*(buff + 5) = '/';
	//int century = get_time(CENTURY);
	int year = get_time(YEAR);
	year = 2000 + year;
	itoa(year, buff + 6, 10);
	*(buff + 10) = 0;
	//ncPrint(buff);
}

void handle_sys_time(char * buff){
	int hours = get_time(HOURS);
	if (hours < 10){
		itoa(0, buff, 10);
		itoa(hours, buff + 1, 10);
	} else{
		itoa(hours, buff, 10);
	}

	*(buff + 2) = ':';

	int minutes = get_time(MINUTES);
	if (minutes < 10){
		itoa(0, buff + 3, 10);
		itoa(minutes, buff + 4, 10);
	} else{
		itoa(minutes, buff + 3, 10);
	}

	*(buff + 5) = ':';

	int seconds = get_time(SECONDS);
	if (seconds < 10){
		itoa(0, buff + 6, 10);
		itoa(minutes, buff + 7, 10);
	} else{
		itoa(minutes, buff + 6, 10);
	}
	*(buff + 8) = 0;
	//ncPrint(buff);
}
