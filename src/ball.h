
#ifndef _BALL 
#define _BALL
#include "paddle.h"
typedef struct Ball{
  float x, y, xvel, yvel;
  char *body;
} Ball;

typedef struct env_data {
  int *state;
  Ball *ball;
  Paddle *p1;
  Paddle *p2;
} env_data;

Ball* init_ball();
void draw_ball(Ball*, int);
void refresh_ball(Ball*, Paddle*, Paddle*);
void *update_ball(void *);
#endif
