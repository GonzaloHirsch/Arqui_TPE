//
// Created by nacho on 12/06/19.
//

#include <console.h>

#define MAX_BUFFER 100

static Color background = {29,29,29};
static Color foreground = {255,255,255};

static Vector2 cursor = {0,0};

void initConsole(){
    clearConsole();
}

void newline(){
    cursor.y++;
    cursor.x=0;
}

void move_all_up(){}


void print(char * str, ...){
    va_list list;
    va_start(list, str);
    int i = 0;
    while(str[i] != 0){
        if(str[i] == '%' && str[i-1] != '\\'){
            char buffer[MAX_BUFFER] = {0};
            switch (str[i+1]) {
                case 'd':
                    int_to_string((int) va_arg(list,int), buffer, 10);
                    print(buffer);
                    i++;
                    break;
                case 's':
                    print(va_arg(list,char*));
                    i++;
                    break;
            }
        }
        else {
            switch(str[i]) {
                case '\n':
                    newline();
                    break;
                case '\t':
                    cursor.x+=4;
                    break;
                default:
                    draw_char_with_background(cursor, str[i], foreground, background);
                    cursor.x++;
                    break;
            }
        }


        if(cursor.x >= getVideoX()/CHAR_WIDTH){
            cursor.x = 0;
            cursor.y++;
        }
        if(cursor.y >= getVideoY()/CHAR_HEIGHT){
            move_all_up();
        }
        i++;
    }
}

void clearConsole(){
    Vector2 size = {getVideoX(), getVideoY()};
    draw_rect(ZeroVector, size, background);
}
