#include <utils.h>

char getKey(){
	char buff;
	sys_get_key(0, &buff);
	return buff;
}

char * getTime(){
	char * buff;
	sys_time(&buff);
	return buff;
}

void writeKey(char * key){
	sys_write_key(0, key);
}

int strcmp(const char * stra, const char * strb){
	int result = 0;
	for (int i = 0; *(stra + i) != 0 &&  *(strb + i) != 0 && !result; i++){
		if (*(stra + i) < *(strb + i)){
			result = -1;
		} else if (*(stra + i) > *(strb + i)){
			result = 1;
		}
	}
	//ncPrintDec(result);
	return result;
}
