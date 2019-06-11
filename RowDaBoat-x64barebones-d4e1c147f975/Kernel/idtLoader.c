#include <idtLoader.h>
#include <interrupts.h>

#pragma pack(push)
#pragma pack (1)

void setup_IDT_entry (int index, uint64_t offset);
void load_idt();

DESCR_INT * idt = (DESCR_INT *) 0;

void setup_IDT_entry (int index, uint64_t offset) {
   idt[index].offset_l = offset & 0xFFFF;
   idt[index].selector = 0x08;
   idt[index].cero = 0;
   idt[index].access = ACS_INT;
   idt[index].offset_m = (offset >> 16) & 0xFFFF;
   idt[index].offset_h = (offset >> 32) & 0xFFFFFFFF;
   idt[index].other_cero = 0;
}

void load_idt() {
  _cli();
  setup_IDT_entry (0x20, (uint64_t) &_irq00Handler);
  // Interrupción de timer tick habilitada
  pic_master_mask(0xFE);
  pic_slave_mask(0xFF);
  _sti();
   }

#pragma pack(pop)