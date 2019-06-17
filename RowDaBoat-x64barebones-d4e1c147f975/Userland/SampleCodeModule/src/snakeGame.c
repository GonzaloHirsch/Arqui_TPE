#include <snakeGame.h>

static uint64_t frame = 0;
static uint64_t lastFrame = 0;

static int isRunning;
static int winner;

static int totalTimeAlive = 0;
static int partialTime = 0;
static int relativeTime = 0;

//La velocidad inicial es para la frecuencia mas baja
static int velocity = 65356;
static int velocityIncrements = 5000;

void onExit();
void nextFrame();
int abosulteTimeDifference(int before, int after);

void resetVariables(){
  winner = 1;

  velocity = 65356;
  sys_over_clock(velocity);
  totalTimeAlive = 0;
  partialTime = 0;
  relativeTime = sys_time(SECONDS);

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

  return totalTimeAlive;
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
  int auxTime = sys_time(SECONDS);
  int delta = abosulteTimeDifference(relativeTime, auxTime);
  relativeTime = auxTime;
  totalTimeAlive += delta;
  partialTime += delta;

  if (partialTime >= 15){
    growSnake();
    sys_beep();
    velocity -= velocityIncrements;
    sys_over_clock(velocity);
    partialTime = 0;
  }

  updateInput();
  if(isSnakeColliding()){
    isRunning = 0;
    winner = 0;
  }
  updateSnake();
  drawPoints((int)totalTimeAlive);
}

int abosulteTimeDifference(int before, int after){
  int result = 0;
  if (after < before){
    result = 60 - before + after;
  } else {
    result = after - before;
  }
  return result;
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
  velocity = 65356;
  sys_over_clock(velocity);
  clearScreen();
}
