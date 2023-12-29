#include "auto.h"
#include "ball.h"
#include "paddle.h"
#include "setting.h"
#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *auto_paddle_update(void *arg) {

  env_data *data = (env_data *)arg;
  Paddle *p = data->p1;
  float addy = ((p->y + ((float)p->len / 2)) < data->ball->y)
                   ? PADDLE_UPDATE_STEP
                   : -PADDLE_UPDATE_STEP;
  int *state = data->state;

  static int counter;

  extern int LINES;
  if (addy == 0 || p->y + addy + p->len > LINES - 1 + (p->len / 2) ||
      p->y + addy <= -(p->len / 2))
    return NULL;

  update_paddle(p, addy);

  usleep(PADDLE_UPDATE_DELAY);
  *state = 0;

  free(arg);
  return NULL;
}

int auto_state = 0;
void auto_paddle(Paddle *p, Ball *b) {
  if (auto_state)
    return;
  auto_state = 1;
  env_data *data = (env_data *)malloc(sizeof(env_data));
  data->p1 = p;
  data->p2 = NULL;
  data->ball = b;
  data->state = &auto_state;

  pthread_t thread;
  pthread_create(&thread, NULL, auto_paddle_update, (void *)data);
}
