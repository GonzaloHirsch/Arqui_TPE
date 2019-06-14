#include <shell.h>

const char * commandMessages[] = {"help - Show available commands and their use",
								"snake - Initializes the Snake game",
								"shutdown - Shuts down and exits the system",
								"verify - Runs verification routines for system exceptions",
								"time - Displays system date and time"};

const char * commands[] = {"help", "snake", "shutdown", "verify", "time", "beep", "sleep", "date"};
const int commandCount = 8;

void init_shell(void){
	display_welcome_message();

	ncPrint("arquiOS@ITBA: ");
	//Comando elegido
	int command = INVALID_COMMAND;
	//Buffer para el comando que se quiere escribir
	char commandBuff[MAX_BUFF_SIZE] = {0};
	//Posicion en el buffer de comando
	int commandBuffPos = 0;
	//Tecla que se toca
	char key;

	//while para la shell y su funcionamiento
	while(command != SHUTDOWN){
		//ncPrint("WHILE AWAY");
		key = getKey();
		//ncPrintChar(key);
		//writeKey(key);

		//En el caso de que se pase de la cantidad de caracteres
		if (commandBuffPos == MAX_BUFF_SIZE){
			command = INVALID_COMMAND;
			handle_command(command);
			//clear_buffer(commandBuff);
		}

		//En el caso de que aprete enter
		if (key == '\n'){
			// ncPrint("-");
			// ncPrint(commandBuff);
			// ncPrint("-");
			ncNewline();
			commandBuff[commandBuffPos] = 0;
			command = getCommand(commandBuff);
			//ncPrint(commandBuff);
			//ncPrintHex(command);
			handle_command(command);
			//clear_buffer(commandBuff);
			commandBuffPos = 0;
			ncNewline();
			ncPrint("arquiOS@ITBA: ");
		} else if (key == '\b'){
			//delete(key);
			commandBuffPos--;
		} else if (key != 0){
			writeKey(&key);
			commandBuff[commandBuffPos] = key;
			commandBuffPos++;
		}
		//Hacer un get de la tecla que se apreto

		//Ver si es un enter

		//Ver si matchea con alguno de los comandos
	}


	display_goodbye_message();
}

void clear_buffer(char * buff){
	for (int i = 0; i < MAX_BUFF_SIZE; i++){
		buff[i] = 0;
	}
}

int getCommand(char * cmd){
	//Itero el array de comandos para ver cual es el que se elige
	int result = INVALID_COMMAND;
	for (int i = 0; i < commandCount && result == INVALID_COMMAND; i++){
		//En el caso de que sean iguales
		// ncPrint(cmd);
		// ncPrint("-");
		// ncPrint(commands[i]);
		if (!strcmp(cmd, commands[i])){
			//ncPrint("EQU");
			result = i;
		}
	}
	return result;
}

void handle_command(int cmd){
	//ncPrintDec(cmd);
	switch(cmd){
		case HELP:
			display_help();
		break;
		case SNAKE:
		break;
		case SHUTDOWN:
		break;
		case VERIFY:
		break;
		case DATE:
			display_date();
		break;
		case TIME:
			display_time();
		break;
		case BEEP:
			make_sound();
		break;
		case SLEEP:
			sleep();
		break;
		case INVALID_COMMAND:
			display_invalid_command();
		break;
	}
}

void display_welcome_message(void){
	ncClear();
	ncNewline();
	ncPrint("	                                         /$$  /$$$$$$   /$$$$$$");
	ncNewline();
	ncPrint("                                        |__/ /$$__  $$ /$$__  $$");
	ncNewline();
	ncPrint("  /$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$ /$$| $$  \\ $$| $$  \\__/");
	ncNewline();
	ncPrint(" |____  $$ /$$__  $$ /$$__  $$| $$  | $$| $$| $$  | $$|  $$$$$$ ");
	ncNewline();
	ncPrint("  /$$$$$$$| $$  \\__/| $$  \\ $$| $$  | $$| $$| $$  | $$ \\____  $$");
	ncNewline();
	ncPrint(" /$$__  $$| $$      | $$  | $$| $$  | $$| $$| $$  | $$ /$$  \\ $$");
	ncNewline();
	ncPrint("|  $$$$$$$| $$      |  $$$$$$$|  $$$$$$/| $$|  $$$$$$/|  $$$$$$/");
	ncNewline();
	ncPrint(" \\_______/|__/       \\____  $$ \\______/ |__/ \\______/  \\______/ ");
	ncNewline();
	ncPrint("                          | $$                                  ");
	ncNewline();
	ncPrint("                          | $$    ");
	ncNewline();
	ncPrint("                          |__/   ");
	ncNewline();
}

void display_help(void){
	ncPrint("help - Displays available commands and their usage");
	ncNewline();
	ncPrint("snake - Initiates the snake game");
	ncNewline();
	ncPrint("shutdown - Shuts down the system");
	ncNewline();
	ncPrint("verify - Runs system verification routines and informs the results");
	ncNewline();
	ncPrint("time - Displays current system time");
	ncNewline();
	ncPrint("beep - Makes the system go Beep!");
	ncNewline();
	ncPrint("sleep - Makes the system sleep for 5 seconds");
	ncNewline();
}

void display_time(void){
	char * time = getTime();
	ncPrint(time);
	ncNewline();
}

void display_date(void){
	char * date = getDate();
	ncPrint(date);
	ncNewline();
}

void make_sound(void){
	makeSound();
}

void sleep(void){
	goToSleep(50);
}

void display_invalid_command(void){
	ncPrint("Invalid command, type \'help\' to view system commands");
	ncNewline();
}

void display_goodbye_message(void){

}
