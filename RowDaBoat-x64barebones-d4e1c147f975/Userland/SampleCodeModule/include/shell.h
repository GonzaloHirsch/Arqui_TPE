#ifndef SHELL_H
#define SHELL_H

#include <stdint.h>
#include <naiveConsole.h>
#include <utils.h>

//Constantes para los comandos
#define INVALID_COMMAND -1
#define HELP 0
#define SNAKE 1
#define SHUTDOWN 2
#define VERIFY 3
#define TIME 4
#define BEEP 5
#define SLEEP 6
#define DATE 7

#define MAX_BUFF_SIZE 100

//Address original que devolvia el samplecoremodule
#define RETURN_ADRESS 0xDEADC0DE

uint64_t * init_shell(void);

void handle_command(int cmd);

void display_welcome_message(void);

void display_help(void);

void display_goodbye_message(void);

void clear_buffer(char * buff);

void display_time(void);

void display_date(void);

void make_sound(void);

void sleep(void);

void display_invalid_command(void);

#endif
