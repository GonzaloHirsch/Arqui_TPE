#include <stdint.h>
#include <time.h>
#include <naiveConsole.h>
#include <interrupts.h>

static unsigned long ticks = 0;

void timer_handler();
int ticks_elapsed();

void timer_handler() {
	//ncPrintDec(ticks);
     ticks++;
}

int ticks_elapsed(){
	return ticks;
}

void sleep(uint64_t millis){
    _sti();
    int x = ticks_elapsed();

    char buffer[100];

    int i = 0;
    while((ticks_elapsed()-x)*REGULAR_TICK_TIME < millis){

        //ncPrintOnAddress(0xB8000 + 80*2*23,itoa(x, buffer, 10));
        //ncPrintOnAddress(0xB8000 + 80*2*24,itoa(millis/REGULAR_TICK_TIME, buffer, 10));
        ncPrintOnAddress((char *)(0xB8000 + 80*2*12 + 40), "Waiting");
        ncPrintOnAddress((char *)(0xB8000 + 80*2*12 + 40 + 7*2), "   ");
        ncPrintOnAddress((char *)(0xB8000 + 80*2*12 + 40 + 7*2 + (i%3)*2), ".");
        i++;
       halt();
    }
    ncPrintOnAddress((char *)(0xB800 + 80*2*15 + 120 + (i%5)*2), "Done");
    _cli();
}