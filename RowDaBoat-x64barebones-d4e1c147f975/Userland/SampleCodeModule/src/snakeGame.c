#include <snakeGame.h>

static uint64_t frame = 0;
static uint64_t lastFrame = 0;

static int isRunning;
static int winner;

static int snakeBody[400][2];
static int snakeLength;

void onExit();
void nextFrame();
void drawHeader();

void resetVariables(){
  winner = 1;

  resetSnakeBody();
}

int initSnakeGame(){
  isRunning = 1;
  clearScreen();
  initGrid();

  resetVariables();

  Vector2 startPos = {10, 10};

  initSnakeBody(startPos);

  nextFrame();

  onExit();

  return winner;
}

void updateInput(){
  char key = getKey();
  switch (key) {
    case 96:
    case 126:
      isRunning = 0;
    break;
  }
  updateDirection(key);
}

void Update(){
  updateInput();
  if(isSnakeColliding()){
    isRunning = 0;
    winner = 0;
  }
  updateSnake();
  drawPoints((int)frame); 
}



void nextFrame(){
  _sti();
  lastFrame = sys_get_ticks();
  while(isRunning){
    frame = sys_get_ticks();
    //print(frame);
    if (frame > lastFrame){
      lastFrame = frame;
      Update();
    }
    _hlt();
  }
}

void onExit(){
  clearScreen();
}