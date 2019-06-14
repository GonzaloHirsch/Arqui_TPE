#include <stdint.h>
#include <time.h>
//#include <naiveConsole.h>

static unsigned long ticks = 0;

void timer_handler();
int ticks_elapsed();

void timer_handler() {
	//ncPrintDec(ticks);
  ticks++;
}

void timer_wait(int expectedTicks){
  //Prepara para que pueda recibir iterrupciones
  _sti();
  expectedTicks = ticks + expectedTicks;
  while (ticks < expectedTicks){
    //Le dice que puede ser interrumpido
    _hlt();
  }
}

int ticks_elapsed(){
	return ticks;
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
