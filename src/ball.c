#include "ball.h"
#include "paddle.h"
#include "ping.h"
#include "setting.h"
#include <math.h>
#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

Ball *init_ball() {
  Ball *b = (Ball *)malloc(sizeof(Ball));

  // init
  b->y = (int)(LINES / 2);
  b->x = (int)((COLS - 1) / 2);
  b->xvel = INITIAL_XVEL;
  b->yvel = INITIAL_YVEL;
  b->body = "";

  return b;
}

void draw_ball(Ball *b, int state) {
  char *body = (state) ? b->body : " ";
  mvaddstr(b->y, b->x, body);
}

// NOTE: add timeless update with threads
int state = 0; // 0 not being used; 1 in use
void refresh_ball(Ball *b, Paddle *p1, Paddle *p2) {
  // check state
  if (state)
    return;
  else {
    env_data *data = (env_data *)malloc(sizeof(env_data));
    data->state = &state;
    data->ball = b;
    data->p1 = p1;
    data->p2 = p2;
    void *arg = (void *)data;
    pthread_t thread;
    pthread_create(&thread, NULL, update_ball, arg);
  }
}

void *update_ball(void *arg) {
  // deselialize arg
  env_data *data = (env_data *)arg;
  Ball *b = data->ball;
  Paddle *p1 = data->p1;
  Paddle *p2 = data->p2;

  // make sure the state is set to occupied
  *(data->state) = 1;
  // check bounds and adjust velocity
  // check the top bound;
  if ((b->y + b->yvel <= 1) || (b->y + b->yvel >= LINES - 1))
    b->yvel = -(b->yvel);
  // player 1
  /* if (b->x > p1->x && b->x < p1->x + 1 && b->y > p1->y &&
      b->y < p1->y + p1->len) {
    // add paddle_impact handler
    b->xvel = -(b->xvel);
    b->yvel = -((p1->y + ceil(((float)p1->len) / 2) - b->y) / p1->len) * 0.350;
  } */
  // player 1 hit check
  if (((b->x >= p1->x) && (b->x <= p1->x + 1)) &&
      ((b->y >= p1->y) && (b->y <= p1->y + p1->len))) {
    b->xvel = -(b->xvel);
    b->yvel = -((p1->y + (((float)p1->len) / 2) - b->y) / (p1->len)) * 0.375;
    // player 2 aka ai hit check
  } else if (((b->x >= p2->x) && (b->x <= p2->x + 1)) &&
             ((b->y >= p2->y) && (b->y <= p2->y + p2->len))) {
    b->xvel = -(b->xvel);
    b->yvel = -((p2->y + (((float)p2->len) / 2) - b->y) / (p2->len)) * 0.375;
  }
  // undraw
  draw_ball(b, 0);
  // update pos
  b->x += b->xvel;
  b->y += b->yvel;
  // redraw
  draw_ball(b, 1);
  draw_paddle(p1, 1);
  draw_paddle(p2, 1);
  // game over
  extern game_state s;
  if (b->x < 0 || b->x > COLS)
    s = GAME_OVER;
  // return
  usleep(BALL_REFRESH_INTERVAL);
  *(data->state) = 0;
  free(data);
  return NULL;
}
