#include <stdint.h>
#include <time.h>
#include <naiveConsole.h>
#include <interrupts.h>

static unsigned long ticks = 0;


void timer_handler();
int ticks_elapsed();

void timer_handler() {
  ticks++;
}

int ticks_elapsed(){
	return ticks;
}

/*
max = 1193182 / 1 = 1193182 hz
min = 1193182 / 65536 ≈ 18.2065 hz
freq = 1193182 / div
*/
void over_clock(int div){
  //Verifica que no se este pasando
  if (1 <= div && div <= 65356){
    _over_clock(div);
  }
}

void set_time(){
  write_port(0x70, 0x0B);
  uint8_t aux = read_port(0x71);
  aux = aux | 0x04;
  write_port(0x71, aux);
}

int get_time(int selector){
  _cli();
  set_time();
  write_port(0x70, selector_to_register[selector]);
  int aux = read_port(0x71);
  _sti();
  return aux;
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
}

void timer_wait(int expectedTicks){
  //Prepara para que pueda recibir iterrupciones
  _sti();
  expectedTicks = ticks + expectedTicks;
  while (ticks < expectedTicks){
    //Le dice que puede ser interrumpido
    halt();
  }
}
