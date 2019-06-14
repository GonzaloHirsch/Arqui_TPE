//
// Created by nacho on 12/06/19.
//

#include <console.h>

#define MAX_BUFFER 100

static Color background = {29,29,29};
//static Color background = {0,0,0};
static Color foreground = {255,255,255};

static Vector2 cursor = {0,0};

void init_console(){
    clear_console();
    print("%d - %d - %d", get_max_line(), getVideoY);
}

void new_line(){
    cursor.y++;
    cursor.x=0;
}


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
                    new_line();
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
            cursor.y--;
        }
        i++;
    }
}

void move_line_up(unsigned int line){
    Color c = {0,0,0};
    Vector2 posGet = {0,line*CHAR_HEIGHT};
    Vector2 posDraw = {0,(line-1)*CHAR_HEIGHT};
    for(int j = 0; j < CHAR_HEIGHT; j++){
        for (int i = 0; i < getResX(); ++i)
        {
            Color color = {0,255,0};
            get_pixel(posGet, &c);
            draw_pixel(posDraw, c);
            posGet.x++;
            posDraw.x++;
        }
        posGet.x=0;
        posGet.y++;
        posDraw.x=0;
        posDraw.y++;
    }
}

void move_all_up(){
    for(int i = 1; i < get_max_line(); i++){
        move_line_up(i);
    }
    clear_line(get_max_line()-1);
}

void clear_line(unsigned int line){
    Vector2 posDraw = {0,line*CHAR_HEIGHT};
    for(int j = 0; j < CHAR_HEIGHT; j++){
        for (int i = 0; i < getResX(); ++i)
        {
            draw_pixel(posDraw, background);
            posDraw.x++;
        }
        posDraw.x=0;
        posDraw.y++;
    }
}


void clear_console(){
    Vector2 size = {getVideoX(), getVideoY()};
    draw_rect(ZeroVector, size, background);
}

int get_max_line(){
    return getResY() / CHAR_HEIGHT;
}