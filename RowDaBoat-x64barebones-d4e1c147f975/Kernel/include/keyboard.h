#ifndef KEYBOARD_H
#define KEYBOARD_H

#define BREAK_CODE_DIF          128

#define LEFT_SHIFT              130
#define RIGHT_SHIFT             131
#define CAPS_LOCK               132
#define UP_ARROW                133
#define DOWN_ARROW              134
#define LEFT_ARROW              135
#define RIGHT_ARROW 136

#define EOF -1
#define MAX_BUFFER_SIZE 100

void printKey(void);
int addChar(char c);
int getChar(void)

#endif
