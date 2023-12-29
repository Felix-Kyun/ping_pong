#ifndef _AUTO_AI
#define _AUTO_AI
#include "ball.h"
#include "paddle.h"

typedef struct auto_data{
  Paddle *p;
  float addy;
  int *state;
}auto_data;

void *auto_paddle_update(void*);
void auto_paddle(Paddle*, Ball*);

#endif
