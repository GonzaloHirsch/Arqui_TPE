#include <shell.h>

const char * commandMessages[] = {"help - Show available commands and their use",
								"snake - Initializes the Snake game",
								"shutdown - Shuts down and exits the system",
								"verify - Runs verification routines for system exceptions",
								"time - Displays system date and time"};

const char * commands[] = {"help", "snake", "shutdown", "verify", "time", "beep", "sleep"};


void init_shell(void){
	display_welcome_message();

	//Comando elegido
	int command = 1;
	//Buffer para el comando que se quiere escribir
	char commandBuff[100];
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
		//En el caso de un enter
		if (key == '\n'){
			command = HELP;
			handle_command(command);
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

int getCommand(char * buff){
	
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
	ncPrint("YEAH");
}

void display_goodbye_message(void){

}
