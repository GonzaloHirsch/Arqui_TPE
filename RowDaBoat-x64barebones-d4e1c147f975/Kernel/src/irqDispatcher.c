#include <irqDispatcher.h>
#include <stdint.h>
#include <time.h>
#include <naiveConsole.h>
#include <keyboard.h>

void irqDispatcher(uint64_t irq);
void int_20();
void int_21();
extern char read_key();

static char buffer[100];

void irqDispatcher(uint64_t irq) {
    switch (irq) {
        case 0:
        	int_20();
			break;
        case 1:
            int_21();
        break;
	}
	return; 
}

void int_20() {
    timer_handler();
}

void int_21() {
    printKey();
}