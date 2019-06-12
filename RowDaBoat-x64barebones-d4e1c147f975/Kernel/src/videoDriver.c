//
// Created by nacho on 10/06/19.
//

#include <videoDriver.h>

unsigned char * screen;

static ModeInfoBlock* infoBlock;
void initVideoDriver() {
    infoBlock = (ModeInfoBlock*)0x0000000000005C00;
}

void draw_pixel(Vector2 pos, Color color){
    unsigned char * pixel_address;
    int bpp = infoBlock->bpp / 8;
    pixel_address = (unsigned char *) (infoBlock->physbase + pos.x * bpp  + pos.y * (infoBlock->x_res) * bpp);
    pixel_address[0] = color.b;
    pixel_address[1] = color.g;
    pixel_address[2] = color.r;
}

void draw_rect(Vector2 pos, Vector2 size, Color color){
    Vector2 auxPos = {0,0};
    for (auxPos.y = pos.y; auxPos.y < pos.y + size.x; auxPos.y++) {
        for (auxPos.x = pos.x; auxPos.x < pos.x + size.x; auxPos.x++) {
            draw_pixel(auxPos, color);
        }
    }
}

void draw_char_with_background(Vector2 pos, char c, Color foreground, Color background){
    char * cMap = pixel_map(c);
    for (int j = 0; j < CHAR_HEIGHT; ++j) {
        for (int i = 0; i < CHAR_WIDTH+1; ++i) {                                //No se porque CHAR_WIDTH + 1 y no CHAR_WIDTH solamente... Pero funciona...
            Vector2 aux = {(pos.x*(CHAR_WIDTH+1))+i, (pos.y*CHAR_HEIGHT)+j};
            if((cMap[j] >> (CHAR_WIDTH - i)) & 1)
                draw_pixel(aux,foreground);
            else
                draw_pixel(aux, background);
        }

    }

}


void draw_string_with_background(Vector2 pos, char * str, Color foreground, Color background){
    Color color = {255,255,255};
    Vector2 auxPos = {pos.x,pos.y};

    while((*str) != 0) {
        draw_char_with_background(auxPos, (*str), foreground, background);
        auxPos.x++;
        str++;
    }
}

int getResX(){
    return infoBlock->x_res;
}
int getResY(){
    return infoBlock->y_res;
}