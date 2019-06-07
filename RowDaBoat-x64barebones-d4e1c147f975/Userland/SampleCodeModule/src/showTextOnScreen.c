 #include <showTextOnScreen.h>

static int strlen(char *);

void showTextOnScreen(char *screenBase, char *text){

	if(strlen(text) > MAX_TEXT_LENGTH) return;

	int i = 0;

	while(*text != 0){

		*(screenBase+i) = *text;
		*(screenBase+i+1) = 0xF2;
		i+=2;
		text++;
	}

}

int strlen(char * s){

	int i = -1;
	while(*(s+(++i))!=0);
	return i;

}