#include <shell.h>

const char * commandMessages[] = {"help - Show available commands and their use",
								"snake - Initializes the Snake game",
								"shutdown - Shuts down and exits the system",
								"verify - Runs verification routines for system exceptions",
								"time - Displays system date and time"};

const char * commands[] = {"help", "snake", "shutdown", "invalid", "time", "beep", "sleep", "date", "clear", "div"};
const int commandCount = 10;

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

		//CASO EN QUE SE PASA DE LA CANTIDAD MAXIMA DE CARACTERES
		if (commandBuffPos == MAX_BUFF_SIZE){
			//Define el comando como invalido
			command = INVALID_COMMAND;
			//Imprime una linea nueva para que se vea bien
			print("\n");
			//Llama a la funcion para manejar el comando
			handle_command(command);
			//Hace un reset del buffer de comando volviendo a la posicion 0
			commandBuffPos = 0;
			//Imprime el usuario de nuevo
			print("\narquiOS@ITBA: ");
		}

		//CASO ENTER
		if (key == '\n'){
			//Manda el enter a la pantalla para que baje la linea y se vea bien
			writeKey(&key);
			//Agrega terminacion en 0 al buffer de comando
			commandBuff[commandBuffPos] = 0;
			//Recupera el comando que fue elegido
			command = getCommand(commandBuff);
			//Llama a la funcion que decide como actuar en frente del comando
			handle_command(command);
			//Hace un reset del buffer de comando volviendo a la posicion 0
			commandBuffPos = 0;
			//Vuelve a imprimir el usuario para que se vea bien
			print("arquiOS@ITBA: ");
		}
		//CASO BACKSPACE - DELETE
		else if (key == '\b'){
			//En el caso de que se borro todo, para que no borre de mas
			if (commandBuffPos != 0){
				//Manda el backspace para que borre fisicamente a la tecla
				writeKey(&key);
				//Borra la letra del buffer de comando
				commandBuffPos--;
			}
		}
		//CASO CUALQUIER OTRA TECLA
		else if (key != 0){
			//Manda la letra a pantalla
			writeKey(&key);
			//Manda la letra al buffer de comando
			commandBuff[commandBuffPos] = key;
			//Incrementa la longitud de la palabra
			commandBuffPos++;
		}
	}

	display_goodbye_message();

	return (uint64_t *) RETURN_ADRESS;
}

int getCommand(char * cmd){
	//Itero el array de comandos para ver cual es el que se elige
	int result = INVALID_COMMAND;
	for (int i = 0; i < commandCount && result == INVALID_COMMAND; i++){
		//En el caso de que sean iguales
		if (!strcmp(cmd, commands[i])){
			result = i;
		}
	}
	return result;
}

void handle_command(int cmd){
	switch(cmd){
		case HELP:
			display_help();
		break;
		case SNAKE:
		initSnakeGame();
		break;
		//Retorna y sale del while, y no se puede hacer nada mas
		case SHUTDOWN:
		return;
		break;
		case INVALID_OC:
			generate_invalid_opc();
		break;
		case DIV:
			generate_zero_division();
		break;
		//Imprime la fecha de hoy
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
		case CLEAR:
			clearScreen();
		break;
		case INVALID_COMMAND:
			display_invalid_command();
		break;
	}
	print("\n");
}

/*
	Imprime el mensaje de bienvenida
*/
void display_welcome_message(void){
	clearScreen();
	print("						                                               /$$  /$$$$$$   /$$$$$$\n");
	print("						                                              |__/ /$$__  $$ /$$__  $$\n");
	print("						        /$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$ /$$| $$  \\ $$| $$  \\__/\n");
	print("						       |____  $$ /$$__  $$ /$$__  $$| $$  | $$| $$| $$  | $$|  $$$$$$ \n");
	print("						        /$$$$$$$| $$  \\__/| $$  \\ $$| $$  | $$| $$| $$  | $$ \\____  $$\n");
	print("						       /$$__  $$| $$      | $$  | $$| $$  | $$| $$| $$  | $$ /$$  \\ $$\n");
	print("						      |  $$$$$$$| $$      |  $$$$$$$|  $$$$$$/| $$|  $$$$$$/|  $$$$$$/\n");
	print("						       \\_______/|__/       \\____  $$ \\______/ |__/ \\______/  \\______/ \n");
	print("						                                | $$                                  \n");
	print("						                                | $$    \n");
	print("						                                |__/   \n");
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
	print(getTime());
}

void display_date(void){
	print(getDate());
}

void generate_invalid_opc(){
	//inexistent_function();
}

void generate_zero_division(){
	int result = 10 / 0;
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
