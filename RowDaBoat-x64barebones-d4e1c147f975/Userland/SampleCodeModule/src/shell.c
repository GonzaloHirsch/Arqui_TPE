#include <shell.h>

const char * commandMessages[] = {"help - Show available commands and their use",
								"snake - Initializes the Snake game",
								"shutdown - Shuts down and exits the system",
								"verify - Runs verification routines for system exceptions",
								"time - Displays system date and time"};

const char * commands[] = {"help", "snake", "shutdown", "verify", "time", "beep", "sleep", "date", "clear"};
const int commandCount = 9;

uint64_t * init_shell(void){
	display_welcome_message();

	print("arquiOS@ITBA: ");
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
		//print("WHILE AWAY");
		key = getKey();
		//printChar(key);
		//writeKey(key);

		//En el caso de que se pase de la cantidad de caracteres
		if (commandBuffPos == MAX_BUFF_SIZE){
			command = INVALID_COMMAND;
			handle_command(command);

			clear_buffer(commandBuff);
			commandBuffPos = 0;

			print("\narquiOS@ITBA: ");
		}

		//En el caso de que aprete enter
		if (key == '\n'){
			writeKey(&key);
			// print(commandBuff);
			// print("-");
			ncNewline();
			commandBuff[commandBuffPos] = 0;
			command = getCommand(commandBuff);
			//print(commandBuff);
			//printHex(command);
			handle_command(command);
			//clear_buffer(commandBuff);
			commandBuffPos = 0;
			print("arquiOS@ITBA: ");
		} else if (key == '\b'){
			writeKey(&key);
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

	return (uint64_t *) RETURN_ADRESS;
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
		// print(cmd);
		// print("-");
		// print(commands[i]);
		if (!strcmp(cmd, commands[i])){
			//print("EQU");
			result = i;
		}
	}
	return result;
}

void handle_command(int cmd){
	//printDec(cmd);
	Vector2 pos = {100,100};
	Vector2 size = {250,250};
	Color color = {0,255,0};
	int h = 15;
    char buffer[10]={0};
    char c = 10;

    switch(cmd){
		case HELP:
			display_help();
		break;
		case SNAKE:
		break;
		//Retorna y sale del while, y no se puede hacer nada mas
		case SHUTDOWN:
		return;
		break;
		case VERIFY:
		break;
		//Imprime la fecha de hoy
		case DATE:
			display_date();
		break;
		case TIME:
			//printf("Hola %d", "Jorge");
			scanf("%s hola%c %d", &buffer, &c, &h);
			printf("Recibido: %s %c %d", buffer, c, h);
			display_time();
		break;
		case BEEP:
			make_sound();
		break;
		case SLEEP:
			sleep();
		break;
		case CLEAR:
			clearScreen();
		break;
		case INVALID_COMMAND:
			display_invalid_command();
		break;
	}
	print("\n");
}

void display_welcome_message(void){
	clearScreen();
	print("                                               /$$  /$$$$$$   /$$$$$$\n");
	print("                                              |__/ /$$__  $$ /$$__  $$\n");
	print("        /$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$ /$$| $$  \\ $$| $$  \\__/\n");
	print("       |____  $$ /$$__  $$ /$$__  $$| $$  | $$| $$| $$  | $$|  $$$$$$ \n");
	print("        /$$$$$$$| $$  \\__/| $$  \\ $$| $$  | $$| $$| $$  | $$ \\____  $$\n");
	print("       /$$__  $$| $$      | $$  | $$| $$  | $$| $$| $$  | $$ /$$  \\ $$\n");
	print("      |  $$$$$$$| $$      |  $$$$$$$|  $$$$$$/| $$|  $$$$$$/|  $$$$$$/\n");
	print("       \\_______/|__/       \\____  $$ \\______/ |__/ \\______/  \\______/ \n");
	print("                                | $$                                  \n");
	print("                                | $$    \n");
	print("                                |__/   \n");
	print("Welcome to arquiOS\n");
	print("Type in \"help\" to discover all available commands\n\n");
}

void display_help(void){
	print("help - Displays available commands and their usage\n");
	print("snake - Initiates the snake game\n");
	print("shutdown - Shuts down the system\n");
	print("verify - Runs system verification routines and informs the results\n");
	print("time - Displays current system time\n");
	print("date - Displays current system date\n");
	print("beep - Makes the system go Beep!\n");
	print("sleep - Makes the system sleep for 5 seconds\n");
}

void display_time(void){
	char * time = getTime();
	print(time);
	ncNewline();
}

void display_date(void){
	char * date = getDate();
	print(date);
	ncNewline();
}

void make_sound(void){
	makeSound();
}

void sleep(void){
	goToSleep(50);
}

void display_invalid_command(void){
	print("Invalid command, type \'help\' to view system commands\n");
}

void display_goodbye_message(void){

}
