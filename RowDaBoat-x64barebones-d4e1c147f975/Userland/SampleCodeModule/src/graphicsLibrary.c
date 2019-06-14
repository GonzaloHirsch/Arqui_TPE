#include <graphicsLibrary.h>

void print(const char * str){
  sys_write(1, str, strlen(str));
}

void printN(const char * str, int length){
  sys_write(1,str,length);
}

void drawPixel(Vector2 pos, Color color){
  //sys_draw_pixel(pos.x, pos.y, color.r, color.g, color.b);
}

void drawRect(Vector2 start, Vector2 size, Color color){
  for(int j = start.y; j < start.y + size.y; j++){
    for (int i = start.x; i < start.x + size.x; i++) {
      Vector2 aux = {i,j};
      drawPixel(aux, color);
    }
  }
}
