#ifndef SHELL_H
#define SHELL_H

#include <stdint.h>
#include <naiveConsole.h>
#include <utils.h>
#include <graphicsLibrary.h>
#include <types.h>
#include <snakeGame.h>
#include <syscalls.h>

//Constantes para los comandos
#define INVALID_COMMAND -1
#define HELP 0
#define SNAKE 1
#define SHUTDOWN 2
#define INVALID_OC 3
#define TIME 4
#define BEEP 5
#define SLEEP 6
#define DATE 7
#define CLEAR 8
#define DIV 9

#define MAX_BUFF_SIZE 750

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
