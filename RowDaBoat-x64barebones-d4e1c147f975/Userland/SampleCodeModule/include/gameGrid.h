#ifndef GAME_GRID_H
#define GAME_GRID_H

#include <graphicsLibrary.h>
#include <types.h>
#include <utils.h>

static Vector2 GRID_SIZE = {95,65};

void initGrid();

void drawCell(Vector2 cell, Color color) ;

void drawPoints(int p);

#endif
