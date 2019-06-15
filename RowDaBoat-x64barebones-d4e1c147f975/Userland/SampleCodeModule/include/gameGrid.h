#ifndef GAME_GRID_H
#define GAME_GRID_H

#include <graphicsLibrary.h>
#include <types.h>


#define BORDER_SIZE 5
#define CELL_SIZE 10
#define CELL_PADDING 1

static Vector2 GRID_SIZE = {95,65};
static Vector2 START_POS = {20,20};

static Color BORDER_COLOR = {126, 56, 120};
static Color CELL_COLOR = {255,255,255};


void initGrid();

void drawCell(Vector2 cell, Color color) ;

#endif
