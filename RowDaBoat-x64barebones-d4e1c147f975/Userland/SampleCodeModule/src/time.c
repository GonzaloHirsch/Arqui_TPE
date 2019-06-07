#include <time.h>

extern int getTimeParticle(int particleName);

static char * inttostr(int n, char * buffer);
static int numdigits(int n);


void showTime(char * screenBase){

	int secs = getTimeParticle(0);
	int mins = getTimeParticle(2);
	int hours = getTimeParticle(4);
	int dayOfMonth = getTimeParticle(7);
	int month = getTimeParticle(8);
	int year = getTimeParticle(9);

	char buffer[10]={0};

	showTextOnScreen(screenBase + 80*2, inttostr(mins, buffer));
}

char * inttostr(int n, char * buffer){

	
	if(n!=0){
	int offset = numdigits(n);

	//Termino el string
	buffer[offset--] = '\0';

	//Escribo de menor a mayor potencia de 10.
	while(n!=0){
		buffer[offset--] = n%10 + '0';
		n/=10;
	}
}
	else{
		buffer[0]='0';
		buffer[1]=0;
	}

	return buffer;
}

numdigits(int n){
	
	int length = 0;

	if(n<0) n = -n;

	while(n!=0){
		length++;
		n/=10;
	}

	return length;
}