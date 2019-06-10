#include <utils.h>

int getKey(){
	char * buff[1];
	sys_get_key(0, buff);
	return buff[0];
}

void writeKey(char * key){
	sys_write_key(0, key);
}