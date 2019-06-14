#ifndef IO_READ_H
#define IO_READ_H

int read_key();
int check_key();

int read_port(uint16_t port);
void write_port(uint16_t port, uint8_t data);

#endif
