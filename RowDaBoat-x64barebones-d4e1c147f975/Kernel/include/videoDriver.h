//
// Created by nacho on 10/06/19.
//

#ifndef ARQUI_TPE_VIDEODRIVER_H
#define ARQUI_TPE_VIDEODRIVER_H

#include <stdint.h>
#include <lib.h>
#include <pixelMap.h>
#include <types.h>

// Struct taken from https://wiki.osdev.org/Getting_VBE_Mode_Info
typedef struct __attribute__((packed)) {
    uint16_t attributes;
    uint8_t win_A,win_B;
    uint16_t granularity;
    uint16_t winsize;
    uint16_t segment_A, segment_B;
    uint32_t real_fct_ptr;
    uint16_t pitch; // bytes per scanline

    uint16_t x_res, y_res;
    uint8_t w_char, y_char, planes, bpp, banks;
    uint8_t memory_model, bank_size, image_pages;
    uint8_t reserved0;

    uint8_t red_mask, red_position;
    uint8_t green_mask, green_position;
    uint8_t blue_mask, blue_position;
    uint8_t rsv_mask, rsv_position;
    uint8_t directcolor_attributes;

    uint32_t physbase;  // your LFB (Linear Framebuffer) address ;)
    uint32_t reserved1;
    uint16_t reserved2;
} ModeInfoBlock;

void initVideoDriver();

void draw_pixel(Vector2 pos, Color color);
void draw_rect(Vector2 pos, Vector2 size, Color color);
void draw_char_with_background(Vector2 pos, char c, Color foreground, Color background);
void draw_string_with_background(Vector2 pos, char * str, Color foreground, Color background);


int getResX();
int getResY();


#endif //ARQUI_TPE_VIDEODRIVER_H
