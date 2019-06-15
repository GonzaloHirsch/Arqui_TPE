#include <snakeGame.h>

static uint64_t frame = 0;
static uint64_t lastFrame = 0;

static isRunning;
static int gameOver;

static int snakeBody[400][2];
static int snakeLength;

void onExit();
void nextFrame();

void resetVariables(){
  gameOver = 0;

  resetSnakeBody();
}

void initSnakeGame(){
  isRunning = 1;
  clearScreen();
  initGrid();

  resetVariables();

  Vector2 startPos = {10, 10};

  initSnakeBody(startPos);

  nextFrame();

  onExit();
}

void updateInput(){
  /* char key = getKey();
  switch (key) {
    case 'W':
    case 'w':
      if(direction.y != 1){
        direction.y = -1;
        direction.x = 0;
      }
      break;
    case 'S':
    case 's':
      if(direction.y != -1){
        direction.y = 1;
        direction.x = 0;
      }
      break;
    case 'A':
    case 'a':
      if(direction.x != 1){
        direction.x = -1;
        direction.y = 0;
      }
        break;
    case 'D':
    case 'd':
      if(direction.x != -1){
        direction.x = 1;
        direction.y = 0;
      }
      break;
    case 96:
    case 126:
      isRunning = 0;
    break;
  }*/
}

void Update(){
  updateInput();
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
