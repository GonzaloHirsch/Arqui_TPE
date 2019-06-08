//
// Created by root on 6/8/19.
//

#include <keyboard.h>
#include <naiveConsole.h>

extern char read_key();

static char buffer[100]={0};

unsigned char keycodes[128] = {
        27,  '`', '1', '2', '3', '4', '5', '6', '7', '8', /* INDEX: 0 - 9 */
        '9','0', '-', '=','\b', '\t' /* Tab */,'q', 'w', 'e', 'r',	/* INDEX: 10 - 19 */
        't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0 /* Control */, /* INDEX: 20 - 29 */
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* INDEX: 30 - 39 */
        '\'', '`',  LEFT_SHIFT,'\\', 'z', 'x', 'c', 'v', 'b', 'n', /* INDEX: 40 - 49 */
        'm', ',', '.', '/', RIGHT_SHIFT,'*',0/* Alt */,' '/* Space bar */, CAPS_LOCK, 0 /* F1 */, /* INDEX: 50 - 59 */
        0/* F2 */,   0/* F3 */,   0/* F4 */,   0/* F5 */,   0/* F6 */,   0/* F7 */,   0/* F8 */,   0/* F9 */, 0 /*F10 */, 0/*Num lock*/, /* INDEX: 60 - 69 */
        0 /* Scroll Lock */,0 /* Home key */, UP_ARROW /* Up Arrow */, 0 /* Page Up */, '-', LEFT_ARROW/* Left Arrow */, 0, RIGHT_ARROW/* Right Arrow */,'+', 0/*End key*/, /* INDEX: 70 - 79 */
        DOWN_ARROW/* Down Arrow */,0/* Page Down */, 0/* Insert Key */, 0/* Delete Key */, 0,   0,   0,  0/* F11 Key */, 0/* F12 Key */,
        0,	/* All other keys are undefined */
};

void printKey(){

    buffer[0] = keycodes[read_key()];
    ncPrint(buffer);
}