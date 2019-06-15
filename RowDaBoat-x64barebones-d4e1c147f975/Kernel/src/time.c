#include <stdint.h>
#include <time.h>
//#include <naiveConsole.h>

static unsigned long ticks = 0;


void timer_handler();
int ticks_elapsed();

void timer_handler() {
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

//El rate tiene que ser 2 < rate < 15
void over_clock(int rate){
  if (2 < rate && rate < 15){
    rate &= 0x0F;			// rate must be above 2 and not over 15
    _cli();
    write_port(0x70, 0x8A);		// set index to register A, disable NMI
    char prev=read_port(0x71);	// get initial value of register A
    write_port(0x70, 0x8A);		// reset index to A
    write_port(0x71, (prev & 0xF0) | rate); //write only our rate to A. Note, rate is the bottom 4 bits.
    _sti();
  } else if (rate == 15){
      _cli();		// disable interrupts
    write_port(0x70, 0x8B);		// select register B, and disable NMI
    char prev=read_port(0x71);	// read the current value of register B
    write_port(0x70, 0x8B);		// set the index again (a read will reset the index to register D)
    write_port(0x71, prev | 0x40);	// write the previous value ORed with 0x40. This turns on bit 6 of register B
    _sti();
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
