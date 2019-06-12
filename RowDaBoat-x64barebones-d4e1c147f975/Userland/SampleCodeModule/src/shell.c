#include <shell.h>

const char * commandMessages[] = {"help - Show available commands and their use",
								"snake - Initializes the Snake game",
								"shutdown - Shuts down and exits the system",
								"verify - Runs verification routines for system exceptions",
								"time - Displays system date and time"};

const char * commands[] = {"help", "snake", "shutdown", "verify", "time", "beep", "sleep"};


void init_shell(void){
	ncClear();
	ncPrint("You have entered userland");

	display_welcome_message();

	int command = 1;
	char * commandBuff[100];
	int commandBuffPos = 0;
	int key;
	//while para la shell y su funcionamiento
	while(command != SHUTDOWN){
		//ncPrint("WHILE AWAY");
		key = getKey();
		ncPrintDec(key);
		//En el caso de un enter
		if (key == 29){
			command = HELP;
			handle_command(command);
		} else {
			writeKey(key);
			commandBuff[commandBuffPos] = key;
			commandBuffPos++;
		}
		//Hacer un get de la tecla que se apreto

		//Ver si es un enter

		//Ver si matchea con alguno de los comandos
	}

	display_goodbye_message();
}

void handle_command(int cmd){
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
		case TIME:
		break;
		case BEEP:
		break;
		case SLEEP:
		break;
	}
}

void display_welcome_message(void){
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
	ncPrint("YEAH");
}

void display_goodbye_message(void){

}