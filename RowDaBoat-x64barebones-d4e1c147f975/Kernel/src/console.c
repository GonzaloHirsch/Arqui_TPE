//
// Created by nacho on 12/06/19.
//

#include <console.h>

static Color background = {29,29,29};
//static Color background = {0,0,0};
static Color foreground = {255,255,255};

static Vector2 cursor = {0,0};

int get_max_cursorY(){
    return getVideoY() / CHAR_HEIGHT;
}

int get_max_cursorX(){
    return getVideoX() / CHAR_WIDTH;
}


void init_console(){
    clear_console();
}

void new_line(){
    cursor.y++;
    cursor.x=0;
}

void backspace(){
  if(cursor.y == 0 && cursor.x == 0){
    return;
  } else if(cursor.x == 0){
    cursor.x = get_max_cursorX()-1;
    cursor.y--;
  }

  draw_char_with_background(cursor, ' ', background, background);
}

void print_char(char c){
  switch(c) {
    case '\n':
      new_line();
      break;
    case '\t':
      cursor.x+=4;
      break;
    case '\b':
      backspace();
      break;
    default:
      draw_char_with_background(cursor, c, foreground, background);
      cursor.x++;
      break;
    }

    if(cursor.x >= getVideoX()/CHAR_WIDTH){
      cursor.x = 0;
      cursor.y++;
    }
    if(cursor.y >= getVideoY()/CHAR_HEIGHT){
      move_all_up();
      cursor.y--;
    }
}

void print(char * str){
    for(int i = 0; str[i] != 0; i++){
      print_char(str[i]);
    }
}

void print_N(char * str, int length){
  for(int i = 0; i < length; i++){
        print_char(str[i]);
    }
}

void move_line_up(unsigned int line){
    Color c = {0,0,0};
    Vector2 posGet = {0,line*CHAR_HEIGHT};
    Vector2 posDraw = {0,(line-1)*CHAR_HEIGHT};
    for(int j = 0; j < CHAR_HEIGHT; j++){
        for (int i = 0; i < getResX(); ++i)
        {
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
    for(int i = 1; i < get_max_cursorY(); i++){
        move_line_up(i);
    }
    clear_line(get_max_cursorY()-1);
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
    Vector2 size = {getResX(), getResY()};
    draw_rect(ZeroVector, size, background);
    cursor.x = 0;
    cursor.y = 0;
}
