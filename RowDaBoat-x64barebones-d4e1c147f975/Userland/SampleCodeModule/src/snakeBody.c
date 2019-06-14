#include <snakeBody.h>

#define MAX_BODY_SIZE 400

static Vector2 snake[MAX_BODY_SIZE] = {0,0};

static int snakeSize;

static int head;
static int tail;

static Vector2 direction;

void resetSnakeBody(){
  direction.x = 1;
  direction.y = 0;

  snakeSize = 4;

}

void drawSnake(){
  for (int i = 0; i < snakeSize; i++) {
    drawCell(snake[i], COLOR_WHITE);
  }
}

void setSnakeCell(int index, Vector2 position){
  snake[index].x = position.x;
  snake[index].y = position.y;
}

void initSnakeBody(Vector2 startPos){
  Vector2 auxPos = {startPos.x, startPos.y};
  setSnakeCell(0, auxPos);
  auxPos.x--;
  setSnakeCell(1, auxPos);
  auxPos.x--;
  setSnakeCell(2, auxPos);
  auxPos.x--;
  setSnakeCell(3, auxPos);

  drawSnake();

}

void updateSnake(){

}
