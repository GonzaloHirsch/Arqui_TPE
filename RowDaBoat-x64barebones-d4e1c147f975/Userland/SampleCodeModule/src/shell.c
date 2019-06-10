#include <shell.h>

const char * commandMessages[] = {"help - Show available commands and their use", 
								"snake - Initializes the Snake game", 
								"shutdown - Shuts down and exits the system",
								"verify - Runs verification routines for system exceptions",
								"time - Displays system date and time"};

const char * commands[] = {"help", "snake", "shutdown", "verify", "time", "beep", "sleep"};


void init_shell(void){

	display_welcome_message();

	int command = 1;

	//while para la shell y su funcionamiento
	while(command != SHUTDOWN){
		//Hacer un get de la tecla que se apreto

		//Ver si es un enter

		//Ver si matchea con alguno de los comandos
	}

	display_goodbye_message();
}

void handle_command(int cmd){
	switch(cmd){
		case HELP:
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

void display_welcome_message(){

}

void display_help(){
	
}

void display_goodbye_message(){

}