#include <utils.h>

char getKey(){
	char buff;
	sys_get_key(0, &buff);
	return buff;
}

void writeKey(char * key){
	sys_write_key(0, key);
}
