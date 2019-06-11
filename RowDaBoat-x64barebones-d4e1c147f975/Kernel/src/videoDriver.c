//
// Created by nacho on 10/06/19.
//

#include <videoDriver.h>
#include <lib.h>


unsigned char * screen;

static ModeInfoBlock* infoBlock;
void initVideoDriver() {
    infoBlock = (ModeInfoBlock*)0x0000000000005C00;
}

static unsigned char ** start_video_position = (unsigned char**)0x0005C28;
/*static int ResoultionX;
static int ResolutionY;
static int VideoDepth;*/


/*void initVideoDriver(){
    VideoDepth = getVideoDepth() / 8;
    ResoultionX = getVideoX;
    ResolutionY = getVideoY;
}*/

unsigned char * get_video_start(){
    return *start_video_position;
}

void drawPixel(int x, int y, int r, int g, int b){
    unsigned char * pixel_address;
    int bpp = infoBlock->bpp / 8;
    pixel_address = (unsigned char *) (infoBlock->physbase + x * bpp  + (int)y * (infoBlock->x_res) * bpp);
    pixel_address[0] = b;              // BLUE
    pixel_address[1] = g;              // GREEN
    pixel_address[2] = r;              // RED
}