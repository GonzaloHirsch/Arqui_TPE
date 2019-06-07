#include <stringUtils.h>

static int getDigitCount(int x);

char * num2Str(int x){

	int c = getDigitCount(x);

	while(x != 0){

	}
}

int getDigitCount(int x){
	int c = 0;

	if(x<0) x=x*(-1);

	while(x != 0){
		c++;
		x/=10;
	}

	return c;
}