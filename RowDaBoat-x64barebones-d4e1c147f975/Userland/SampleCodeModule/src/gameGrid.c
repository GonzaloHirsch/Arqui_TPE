#include <gameGrid.h>

void drawBorder(){
  Vector2 hor = {CELL_SIZE * GRID_SIZE.x, BORDER_SIZE};
  Vector2 ver = {BORDER_SIZE , CELL_SIZE * GRID_SIZE.y + BORDER_SIZE*2};

  // Vertical lines
  Vector2 auxStart = {START_POS.x-BORDER_SIZE, START_POS.y-BORDER_SIZE};
  drawRect(auxStart, ver, BORDER_COLOR);

  auxStart.x = START_POS.x + GRID_SIZE.x * CELL_SIZE;
  drawRect(auxStart, ver, BORDER_COLOR);

  // Horizontal lines
  auxStart.x = START_POS.x;
  auxStart.y = START_POS.y - BORDER_SIZE;
  drawRect(auxStart, hor, BORDER_COLOR);

  auxStart.y = START_POS.y + GRID_SIZE.y * CELL_SIZE;
  drawRect(auxStart, hor, BORDER_COLOR);
}

void drawCell(Vector2 cell, Color color) {
  Vector2 cellStart = {START_POS.x + cell.x * CELL_SIZE - CELL_PADDING, START_POS.y + cell.y * CELL_SIZE - CELL_PADDING};
  Vector2 cellSize = {CELL_SIZE - CELL_PADDING, CELL_SIZE - CELL_PADDING};
  drawRect(cellStart, cellSize, color);
}

void initGrid() {

  drawBorder();


}
